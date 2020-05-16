/*************************************************************************
	> File Name: 46.cpp
	> Author: 
	> Mail: 
	> Created Time: Sat May 16 19:58:24 2020
 ************************************************************************/

#include<stdio.h>
#define max_n 1000000
int prime[max_n + 5] = {0};
int is_prime[max_n + 5] = {0};
void init() {
    for (int i = 2; i <= max_n; i++){
        if (!is_prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++){
            if (prime[j] * i > max_n) break;
            is_prime[prime[j] * i] = 1;
            if (i % prime[i] == 0) break;
        }
    }
}

int func(int n){
    return 2 * n * n;
}
int binary_search(int (*func)(int), 1, int ){

}
int is_val (int n) {
    for (int i = 1; prime[i] < n && i <= prime[0]; i++){
        int x = n - prime[i];
        if (binary_search(func, 1, x, x)) return 1;
    }
    return 0;
}
int main(){
    init();
    for (int i = 9;  ; i += 2) {
        if (!is_prime[i]) continue;
        if (is_val(i)) continue;
        printf("%d\n", i);
    }
}

