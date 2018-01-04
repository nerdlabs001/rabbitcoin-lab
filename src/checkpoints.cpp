// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2011-2012 Litecoin Developers
// Copyright (c) 2013 Dogecoin Developers
// Copyright (c) 2014 Rabbitcoin Developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "main.h"
#include "uint256.h"

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //

    static MapCheckpoints mapCheckpoints =
			boost::assign::map_list_of
			(  0, hashGenesisBlockOfficial )
			(10000,  uint256("0x302a440f5b5b9bce22ba797e07be7f5fb8491be3f53640735b53eb0196e3ec9e"))
			(100000,  uint256("0xb0c6daeeec578562604e0226343dee643fdbf626ee33fdef2498fbcf9489eb84"))
			(1000000,  uint256("0xd817da50632bb5c2e3bff9cd5d8e8458905221a17ba51bef850df940f328e74a"))
			(1150000,  uint256("0x72774ebafdfae4a9c34c68aa93686437499e4ee49ae80076eb8af0c31fc09ec1"))
			(1200000,  uint256("0x6101be75adbc7d0c11b407649b06f684dd613a970754a8d3e4577271f44db58a"))
			(1250000,  uint256("0xdf1455879772fe0e99f57e29c2699d7164e46c0e629fe7d5b1f4dc06fe536f7a"))
			(1300000,  uint256("0xae7dfa0fd0d3f308f4433ecef619c69db01ce0ac5d9a7d7fef4d84d9b292bb27"))
			(1350000,  uint256("0xb0a0ab3afffe2b9342f86daa9efea2a8b82dd433d4bd247db6091d97b94f7584"))
			(1400000,  uint256("0xe7330bf983cebb0f921079f774e22af2032b367162427bda37c9dba9acfa41ce"))
			(1410500,  uint256("0xda830cb0c15650d1c6ed9158fb8f99620f3694d357ad32fbed6871e880183c4b"))
			(1415000,  uint256("0x8db74e49def944ead4ce5fe48ab6ddde2c6afcef52f17db4d8dd99bc207c2991"))
			(1420000,  uint256("0xadea4fc3a47702cc7a109047ca76054875e54d06b5e5876094d9e0ead73c5fac"))
			(1425000,  uint256("0xcf8591c7fb76de50c62478773e50f8740b3b4d7d3e4d2f76b439496cf9364452"))
			(1430000,  uint256("0x6b45d8a4705017ef164209bc1014e7d3b470c248120ff1a2b29abce18f77ff55"))
			(2000000,  uint256("0x84b5e86be6c33f935a2f3d43fd24971bcbf04d354c14b8d82076f9f7ce1c0f0f"))
			(2190000,  uint256("0xb746aba19d5800a5cb8a40e0f57f2aed4c51e91a3f183ac2168297c92ad30759"))
			(2200000,  uint256("0x788bfcaa2304c40699278e06c9b91dee6cd0d131dd7fec2cc3a08fbf12d76872"))
			(2500000,  uint256("0xe2dfd4c01ec6d263b75ae81c29798ed2c1cb1d4457c2e18555dd3334f948a682"))
			(2700000,  uint256("0x64e1ed15df2a73068dceea4117405eceef2a8a536db919b7766efc5f3edd0f9f"))
			(3000000,  uint256("0x5cc5cb3a033f63b6c29f34d8f32bd5d8eb1737ceb659a6acbf9e9d353d8f0f5e"))
			(3660000,  uint256("0xc20207dfc846f610b716506cec395667d4a5b169a065edb85eb1cb3a5963f827"))
			(3700000,  uint256("0x71060fbf62ebc657e0e9459d24312f94bc9aa2cd167026aec939333bcb44359c"))
			(3750000,  uint256("0x4181f8be6acda6c47b82bededc60fb7b88bd923b585de6c26597373c147c26bf"))
			;


    bool CheckBlock(int nHeight, const uint256& hash)
    {
        if (fTestNet) return true; // Testnet has no checkpoints

        MapCheckpoints::const_iterator i = mapCheckpoints.find(nHeight);
        if (i == mapCheckpoints.end()) return true;
        return hash == i->second;
		// return true;
    }

    int GetTotalBlocksEstimate()
    {
        if (fTestNet) return 0;
	
        return mapCheckpoints.rbegin()->first;
		// return 0;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        if (fTestNet) return NULL;

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
				// return NULL;
        }
        return NULL;
    }
}
