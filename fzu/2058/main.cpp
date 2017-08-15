#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int A[100001];

int main()
{
    int N, M;
    long long ans;

    while(scanf("%d%d", &N, &M) != EOF){
        for(int i = 0; i < N; i++) scanf("%d", &A[i]);
        sort(A, A + N);
        ans = 0;
        for(int i = 0; i < N; i++) ans += (upper_bound(A + i + 1, A + N, M - A[i]) - A) - (lower_bound(A + i + 1, A + N, M - A[i]) - A);
        printf("%I64d\n", ans);
    }
    return 0;
}

/**
TLE, not friendly to map and c++14 :)
*/

/*
#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

map<int, int> Map;
map<int, int>::iterator it;

int main()
{
    int N, M;
    long long ans;

    while(scanf("%d%d", &N, &M) != EOF){
        ans = 0;
        Map.clear();
        for(int i = 0, x; i < N; i++){
            scanf("%d", &x);
            Map[x]++;
        }
        for(it = Map.begin(); it != Map.end(); ++it){
            if(Map.count(M - it->first)){
                if(M - it->first != it->first) ans += it->second * Map[it->first];
                else ans += (long long)(it->second - 1) * it->second;
            }
        }
        ans /= 2;
        printf("%I64d\n", ans);
    }
    return 0;
}
*/
