// Copyright (c) 2016-2021 The Funcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FUNCOIN_DEPLOYMENTINFO_H
#define FUNCOIN_DEPLOYMENTINFO_H

#include <consensus/params.h>

#include <string>

struct VBDeploymentInfo {
    /** Deployment name */
    const char *name;
    /** Whether GBT clients can safely ignore this rule in simplified usage */
    bool gbt_force;
};

extern const VBDeploymentInfo VersionBitsDeploymentInfo[Consensus::MAX_VERSION_BITS_DEPLOYMENTS];

std::string DeploymentName(Consensus::BuriedDeployment dep);

inline std::string DeploymentName(Consensus::DeploymentPos pos)
{
    assert(Consensus::ValidDeployment(pos));
    return VersionBitsDeploymentInfo[pos].name;
}

#endif // FUNCOIN_DEPLOYMENTINFO_H
