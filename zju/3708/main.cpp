#include <iostream>
#include <algorithm>
#include <set>
#include <utility>
#include <cstdio>

using namespace std;

set<pair<int, int> > cnt;
int in[501], out[501];
int main()
{
    int T, N, M;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d", &N, &M);
        cnt.clear();
        for(int i = 0; i < M; i++) scanf("%d", &in[i]);
        for(int i = 0; i < M; i++) scanf("%d", &out[i]);
        for(int i = 0; i < M; i++){
            if(in[i] > out[i]) swap(in[i], out[i]);
            cnt.insert(make_pair(in[i], out[i]));
        }
        printf("%.3f\n", (double)cnt.size() / N);
    }
    return 0;
}