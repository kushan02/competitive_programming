/*
ID: kushan02
LANG: C++14
*/
#include <bits/stdc++.h>

using namespace std;
#define ONLINE_JUDGE 1

const long long MOD = 1000000007;

long long gcd(long long a, long long b) {
    if (a == 0)return b;
    if (b == 0)return a;
    if (a == 1 || b == 1)return 1;
    if (a == b)return a;
    if (a > b)return gcd(b, a % b); else return gcd(a, b % a);
}

long long power(long long x, long long y, long long m) {
    if (y == 0)
        return 1;
    long long p = power(x, y / 2, m) % m;
    p = ((p % m) * (p % m)) % m;

    if (y % 2 == 0) {
        return p;
    } else {
        return ((x % m) * (p % m)) % m;
    }
}

long long mod_inverse(long long a, long long m) {
    long long g = gcd(a, m);
    if (g != 1)
        return a + 1;
    else
        return power(a, m - 2, m);
}

int main() {
//------------------------------------
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
//-----------------------------------
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//----------------------------------------

    long long t;
    cin >> t;

    while (t--) {


        cout << "\n";
    }


    return 0;
}
