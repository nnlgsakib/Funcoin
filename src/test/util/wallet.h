// Copyright (c) 2019 The Funcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FUNCOIN_TEST_UTIL_WALLET_H
#define FUNCOIN_TEST_UTIL_WALLET_H

#include <outputtype.h>
#include <string>

namespace wallet {
class CWallet;
} // namespace wallet

// Constants //

extern const std::string ADDRESS_BCRT1_UNSPENDABLE;

// RPC-like //

/** Import the address to the wallet */
void importaddress(wallet::CWallet& wallet, const std::string& address);
/** Returns a new encoded destination from the wallet (hardcoded to BECH32) */
std::string getnewaddress(wallet::CWallet& w);
/** Returns a new destination, of an specific type, from the wallet */
CTxDestination getNewDestination(wallet::CWallet& w, OutputType output_type);


#endif // FUNCOIN_TEST_UTIL_WALLET_H
