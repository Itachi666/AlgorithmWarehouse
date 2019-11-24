//
// Created by Niujx on 2019/11/12.
//

#ifndef ALGORITHMWAREHOUSE_PRIME_H
#define ALGORITHMWAREHOUSE_PRIME_H

#include <random>

// example:
//  Prime::miller_rabin(1203487239841)

namespace Prime {
#define random(a, b) (rand() % ((b) -(a)) +(a))
    typedef long long LL;

    LL power_mod(LL x, LL n, LL mod);

    LL mulmod(LL x, LL y, LL n);

    bool witness(LL a, LL n, LL u, LL t);

    bool miller_rabin(LL n, int times = 20);
}


#endif //ALGORITHMWAREHOUSE_PRIME_H
