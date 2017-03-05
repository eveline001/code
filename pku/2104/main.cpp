#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 1e5 + 7;

struct Floor{
    int elm[MAX];
    int num[MAX];
};


Floor T[32];
int arr[MAX];

void BuildUp(int l, int r, int d){
    if(l == r){
        T[d + 1].elm[l] = T[d].elm[l];
        return;
    }
    int mid = (l + r) >> 1, lsm = mid - l + 1;
    for(int i = l;  i <= r; i++){
        if(T[d].elm[i] < arr[mid]){
            lsm--;
        }
    }
    int lst = l, rst = mid + 1, into = 0;
    for(int i = l; i <= r; i++){
        if(i == l){
            T[d].num[i] = 0;
        }else{
            T[d].num[i] = T[d].num[i - 1];
        }
        if(T[d].elm[i] < arr[mid]){
            T[d].num[i]++;
            T[d + 1].elm[lst++] = T[d].elm[i];
        }else if(T[d].elm[i] > arr[mid]){
            T[d + 1].elm[rst++] = T[d].elm[i];
        }else{
            if(into < lsm){
                into++;
                T[d].num[i]++;
                T[d + 1].elm[lst++] = T[d].elm[i];
            }else{
                T[d + 1].elm[rst++] = T[d].elm[i];
            }
        }
    }
    BuildUp(l, mid, d + 1);
    BuildUp(mid + 1, r, d + 1);
    return;
}

int Querry(int L, int R, int k, int l, int r, int d){
    if(l == r){
        return T[d].elm[l];
    }
    int mid = (l + r) >> 1, into, st;
    if(L == l){
        into = T[d].num[R];
        st = 0;
    }else{
        into = T[d].num[R] - T[d].num[L - 1];
        st = T[d].num[L - 1];
    }
    if(into >= k){
        return Querry(l + st, l + T[d].num[R] - 1, k, l, mid, d + 1);
    }else{
        return Querry(mid + 1 + L - l - st, mid + 1 + R - l - T[d].num[R] ,k - into, mid + 1, r, d + 1);
    }
}

int main()
{
    int n, m, L, R, k;

    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            T[0].elm[i] = arr[i];
        }
        sort(arr + 1, arr + n + 1);
        BuildUp(1, n, 0);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &L, &R, &k);
            printf("%d\n", Querry(L, R, k, 1, n, 0));
        }
    }
    return 0;
}
