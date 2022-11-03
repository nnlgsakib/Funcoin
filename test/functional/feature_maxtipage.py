#!/usr/bin/env python3
# Copyright (c) 2022 The Funcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.
"""Test logic for setting -maxtipage on command line.

Nodes don't consider themselves out of "initial block download" as long as
their best known block header time is more than -maxtipage in the past.
"""

import time

from test_framework.test_framework import FuncoinTestFramework
from test_framework.util import assert_equal


DEFAULT_MAX_TIP_AGE = 24 * 60 * 60


class MaxTipAgeTest(FuncoinTestFramework):
    def set_test_params(self):
        self.setup_clean_chain = True
        self.num_nodes = 2

    def test_maxtipage(self, maxtipage, set_parameter=True):
        node_miner = self.nodes[0]
        node_ibd = self.nodes[1]

        self.restart_node(1, [f'-maxtipage={maxtipage}'] if set_parameter else None)
        self.connect_nodes(0, 1)

        # tips older than maximum age -> stay in IBD
        cur_time = int(time.time())
        node_ibd.setmocktime(cur_time)
        for delta in [5, 4, 3, 2, 1]:
            node_miner.setmocktime(cur_time - maxtipage - delta)
            self.generate(node_miner, 1)
            assert_equal(node_ibd.getblockchaininfo()['initialblockdownload'], True)

        # tip within maximum age -> leave IBD
        node_miner.setmocktime(cur_time - maxtipage)
        self.generate(node_miner, 1)
        assert_equal(node_ibd.getblockchaininfo()['initialblockdownload'], False)

    def run_test(self):
        self.log.info("Test IBD with maximum tip age of 24 hours (default).")
        self.test_maxtipage(DEFAULT_MAX_TIP_AGE, set_parameter=False)

        for hours in [20, 10, 5, 2, 1]:
            maxtipage = hours * 60 * 60
            self.log.info(f"Test IBD with maximum tip age of {hours} hours (-maxtipage={maxtipage}).")
            self.test_maxtipage(maxtipage)


if __name__ == '__main__':
    MaxTipAgeTest().main()
