#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 1e9 + 7;

struct Node{
    int L, R;

    bool operator < (const Node& other) const{
        if(this->L != other.L) return this->L < other.L;
        return this->R > other.R;
    }
};

Node A[25001];

int main()
{
    int N, T, ans, ed, last, pos, maxR;

    while(scanf("%d%d", &N, &T) != EOF){
        for(int i = 0; i < N; i++) scanf("%d%d", &A[i].L, &A[i].R);
        sort(A, A + N);
        ed = maxR = 1, ans = last = 0;
        while(maxR < T){
            pos = -1;
            for(int i = last; i < N; i++){
                if(A[i].L > ed) break;
                if(A[i].R > maxR) maxR = A[i].R, pos = i;
            }
            if(!~pos){
                ans = -1;
                break;
            }else last = pos + 1, ed = maxR + 1, ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
