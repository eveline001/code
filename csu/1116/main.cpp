#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct Edge{
    Edge(int x = 0, int y = 0, int Weight = 0) : x(x), y(y), Weight(Weight){
    }

    int x;
    int y;
    int Weight;

    bool operator < (const Edge& b) const{
        if(this->Weight < b.Weight) return true;
            else if(this->Weight == b.Weight){
                if(this->x < b.x) return true;
                    else if(this->x == b.x) return this->y < b.y;
                        else return false;
                }else return false;
    }
};

void ReSet(int arr[], int n){
    for(int i = 1; i <= n; i++) arr[i] = i;
}

int FindFather(int arr[], int x){
    if(arr[x] == x) return x;
    return arr[x] = FindFather(arr, arr[x]);
}

int Merge(int arr[], int a, int b){
    int fa = FindFather(arr, a),
        fb = FindFather(arr, b);

    if(fa != fb) return arr[fb] = arr[fa];
    return -1;
}

int T, n, m, K, u, v, c, cost, sum, ans, x, y;
int p[17], F[17];
Edge E[101];

int main()
{
    scanf("%d", &T);
    for(int t = 1; t <= T; t++)
    {
        scanf("%d%d%d", &n, &m, &K);
        for(int i = 1; i <= n; i++) scanf("%d", &p[i]);
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &c);
            E[i] = Edge(u, v, c);
        }
        sort(E, E + m);
        ans  = 0;
        for(int i = 3; i <= (1 << n) - 1; i++){
            if((i & 1) == 0) continue;
            ReSet(F, n);
            sum  = p[1];
            cost = 0;
            for(int j = 0; j < m; j++){
                if(((1 << (E[j].x - 1)) & i)
                   && ((1 << (E[j].y - 1)) & i)
                   && FindFather(F,E[j].x) != FindFather(F, E[j].y)){
                    Merge(F, E[j].x, E[j].y);
                    cost += E[j].Weight;
                   }
            }
            for(int j = 2; j <= n; j++){
                if(((1 << (j - 1)) & i) && FindFather(F, j) != FindFather(F, 1)){cost = 100001; break;}
            }
            if(cost <= K){
                for(int j = 2; j <= n; j++)
                    if((1 << (j - 1)) & i) sum += p[j];
                if(sum > ans) ans = sum;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
