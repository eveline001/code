#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 3000000;
const int MAXR = 10000;

long long B[MAXR + 1];

inline int Lowbit(int pos){
    return pos & (-pos);
}

void Add(int pos, int add){
    while(pos <= MAXR){
        B[pos] += add;
        pos += Lowbit(pos);
    }
}

inline long long Query(int pos){
    long long res = 0;
    while(pos > 0){
        res += B[pos];
        pos -= Lowbit(pos);
    }
    return res;
}

int f[MAXN + 1];

int main()
{
    int n, m;
    long long ans;
    char C[2];

    while(scanf("%d", &n) != EOF){
        ans = 0;
        memset(B, 0, sizeof(B));
        for(int i = 0; i < n; i++){
            scanf("%d", &f[i]);
            Add(f[i], 1);
            if(f[i] > 1) ans += Query(f[i] - 1);
        }
        scanf("%d", &m);
        for(int i = 0, S, E, temp; i < m; i++){
            scanf("%s", C);
            if(C[0] == 'R'){
                scanf("%d%d", &S, &E);
                temp = f[S];
                for(int j = S + 1; j <= E; j++){
                    if(f[j] > temp) ans--;
                    else if(f[j] < temp) ans++;
                    f[j - 1] = f[j];
                }
                f[E] = temp;
            }else printf("%I64d\n", ans);
        }
    }
    return 0;
}
