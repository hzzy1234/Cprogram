/*************************************************************************
	> File Name: 14.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat May 16 12:35:24 2020
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000
#define max_m 1000000

int keep[max_m + 5] = {0};

typedef long long ll;
ll get_len(ll n) {
    if (n == 1) return 1;
    if (n < max_m && n < keep[n]) return keep[n];
    ll ret;
    if (n & 1) ret = get_len(3 * n + 1) + 1;
    else ret =  get_len(n >> 1) + 1;
    if (n < max_m) keep[n] = ret;
    return ret;
}
int main () {
    int ans = 0, len = 0;
    for (int i = 1; i < max_n; i++) {
        int tmp = get_len(i);
        if (tmp <= len) continue;
        ans = i;
        len = tmp;
    }
    printf("%d\n", ans);
    return 0;
}
