// Copyright (c) 2022 The Funcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FUNCOIN_POLICY_FEES_ARGS_H
#define FUNCOIN_POLICY_FEES_ARGS_H

#include <fs.h>

class ArgsManager;

/** @return The fee estimates data file path. */
fs::path FeeestPath(const ArgsManager& argsman);

#endif // FUNCOIN_POLICY_FEES_ARGS_H
