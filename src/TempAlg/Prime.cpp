//
// Created by Niujx on 2019/11/12.
//

#include "Prime.h"

typedef long long LL;
#define random(a, b) (rand() % ((b) -(a)) +(a))

LL Prime::power_mod(LL x, LL n, LL mod) {
    LL ret = 1;
    while (n) {
        if (n & 1) ret = x * ret % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ret;
}

LL Prime::mulmod(LL x, LL y, LL n) {
    return x * y % n;
}

bool Prime::witness(LL a, LL n, LL u, LL t) {
    LL x0 = power_mod(a, u, n), x1 = 0;
    for (int i = 1; i <= t; ++i) {
        x1 = mulmod(x0, x0, n);
        if (x1 == 1 && x0 != 1 && x0 != n - 1)
            return false;
        x0 = x1;
    }
    return x1 == 1;
}

bool Prime::miller_rabin(LL n, int times) {
    if (n < 2)return false;
    if (n == 2)return true;
    if (!(n & 1))return false;
    LL u = n - 1, t = 0;
    while (u % 2 == 0) {
        t++;
        u >>= 1;
    }
    while (times--) {
        LL a = random(1, n - 1);
        //if(a == 0)std::cout << a << " "<<n<< " "<<u<<" " << t<<'\n';
        if (!witness(a, n, u, t))return false;
    }
    return true;
}