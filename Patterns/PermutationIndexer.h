//
// Created by Asus on 30-11-2024.
//

#ifndef PERMUTATIONINDEXER_H
#define PERMUTATIONINDEXER_H
#include "bits/stdc++.h"
#include "math.h"
using namespace std;

template <size_t N , size_t K = N>

class PermutationIndexer {
    array<uint32_t , (1<<N) - 1>onesCountLookup;
    array<uint32_t, K> Factorial;


public:
    PermutationIndexer() {
        for (uint32_t i = 0; i < (1<<N) - 1; i++) {
            bitset<N>bits(i);
            this->onesCountLookup[i] = bits.count();
        }

        for ( uint32_t i = 0; i < K; i++) {
            this->Factorial[i] = pick(N-1,K-1-i);
        }
    }

    uint32_t rank(const array<uint8_t , K>&perm)const {
        Array<uint32_t,K>lehmer;
        bitset<N>seen;
        lehmer[0] = perm[0];
        seen[ N - 1 - perm[0] ] = true;

        for ( uint32_t i = 1; i < K; i++) {
            seen[ N - 1 - perm[i] ] = true;

            uint32_t numOnes = this->onesCountLookup[seen.to_ulong()>>(N -perm[i])];
            lehmer[i] =  perm[i] - numOnes;

        }

        uint32_t index = 0;
        for (uint32_t i = 0; i < K; i++) {
            index +=lehmer[i] * this->Factorial[i];
        }
        return index;
    }
};

#endif //PERMUTATIONINDEXER_H
