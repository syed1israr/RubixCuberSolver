//
// Created by Asus on 05-12-2024.
//

#ifndef PERMUTATION_INDEXER_H
#define PERMUTATION_INDEXER_H
#include "Math.h"
#include  "bits/stdc++.h"
using namespace std;
template <size_t N, size_t K = N>

class Permutation_Indexer {
    array<uint32_t, (1 << N) - 1> onesCountLookup;


    array<uint32_t, K> factorials;

public:

    Permutation_Indexer()
    {
        for (uint32_t i = 0; i < (1 << N) - 1; ++i)
        {
            bitset<N> bits(i);
            this->onesCountLookup[i] = bits.count();
        }

        for (uint32_t i = 0; i < K; ++i)
            this->factorials[i] = pick(N - 1 - i, K - 1 - i);
    }


    uint32_t rank(const array<uint8_t, K>& perm) const
    {

        array<uint32_t, K> lehmer;
        bitset<N> seen;
        lehmer[0] = perm[0];
        seen[N - 1 - perm[0]] = 1;
        for (uint32_t i = 1; i < K; ++i)
        {
            seen[N - 1 - perm[i]] = 1;
            uint32_t numOnes = this->onesCountLookup[seen.to_ulong() >> (N - perm[i])];
            lehmer[i] = perm[i] - numOnes;
        }
        uint32_t index = 0;
        for (uint32_t i = 0; i < K; ++i)
            index += lehmer[i] * this->factorials[i];

        return index;
    }
};


#endif //PERMUTATION_INDEXER_H
