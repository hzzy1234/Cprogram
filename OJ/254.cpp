/*************************************************************************
	> File Name: 254.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu Jun 11 09:43:38 2020
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
#define max_n 50000

typedef struct cow {
    int starttime, endtime, node, num, pre, next;
} Cow;

void init(int, Cow *, int &sum);
void output(Cow *, int, int);
Cow cow[max_n + 5];

bool cmp1(Cow a, Cow b) {
    if (a.starttime - b.starttime) return a.starttime < b.starttime;
    return a.endtime < b.endtime;
}

bool cmp2(Cow a, Cow b) {
    return a.node < b.node;
}
int main() {
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cow[i].starttime >> cow[i].endtime;
        cow[i].num = 0;
        cow[i].pre = 0;
        cow[i].next = 0;
        cow[i].node = i;
    }
    sort(cow, cow + n, cmp1);
    init (n, cow, sum);
    sort(cow, cow + n, cmp2);
    output(cow, sum, n);

}

void init(int n, Cow *cow, int &sum) {
    for (int i = 0; i < n; i++) {
        int flag1 = 1, flag2 = 1;
        if (!cow[i].num) {
            sum += 1; 
            cow[i].num = sum;
        } 
        for (int j = i + 1; j < n && (flag1 + flag2); j++) {
            if (cow[j].num) continue;
            if (!cow[i].next && flag1 && (cow[i].endtime < cow[j].starttime)) {
                cow[j].num = cow[i].num;
                cow[i].next = 1;
                cow[j].pre = 1;
                flag1 = 0;
            }
            if (!cow[i].pre && flag2 && (cow[i].starttime > cow[j].endtime)) {
                cow[j].num = cow[i].num;
                cow[i].pre = 1;
                cow[j].next = 1;
                flag2 = 0;
            }
        }
    }
    return ;
}

void output (Cow * cow, int sum, int n) {
    cout << sum << endl;
    for (int i = 0; i < n; i++) {
        cout << cow[i].num << endl;
    }
    return ;
}