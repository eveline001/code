#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node{
    int A, i;

    bool operator < (const Node& other){
        return this->A > other.A;
    }
};

Node A[100001];

int main()
{
    int T, n;

    scanf("%d", &T);
    for(int cas = 1 ;cas <= T; cas++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &A[i].A);
            A[i].i = i;
        }
        sort(A + 1, A + 1 + n);
        for(int i = 2; i < n; i++){
            for(int j = 1; j <= n; j++){
                if(A[j].i % i != 0){printf("%d ", A[j].A); break;}
            }
        }
        for(int j = 1; j <= n; j++) if(A[j].i != n){printf("%d\n", A[j].A); break;}
    }
    return 0;
}
