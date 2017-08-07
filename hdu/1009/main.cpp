#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node{
    double J, F, p;

    bool operator < (const Node& other) const{
        return this->p > other.p;
    }
};

Node A[1001];

int main()
{
    int M, N, cnt;
    double res, ans;

    while(scanf("%d%d", &M, &N) != EOF && (~N || ~M)){
        cnt = 0, ans = 0.0, res = (double)M;
        for(int i = 0; i < N; i++){
            scanf("%lf%lf", &A[cnt].J, &A[cnt].F);
            if(A[cnt].F == 0.0) ans += A[cnt].J;
            else A[cnt].p = A[cnt].J / A[cnt].F, cnt++;
        }
        sort(A, A + cnt);
        for(int i = 0; i < cnt && res > 0.0; i++){
            if(res - A[i].F >= 0.0) ans += A[i].J, res -= A[i].F;
            else ans += res / A[i].F * A[i].J, res = 0.0;
        }
        printf("%.3f\n", ans);
    }
    return 0;
}
