//Dijkstra,会有同一条边多次输入，存最小的那个

#include <iostream>

using namespace std;

const int INF = 65535;

int E[201][201],Dij[201];
bool Vis[201];

int main()
{
    int n, m, i, j, x, y, Wei, S, T, Min, u;

    while(cin >> n >> m)
    {
        for(i = 0; i < 201; i++)
            for(j = 0; j < 201; j++)
                if(i == j) E[i][j] = 0;
                else E[i][j] = INF;
        for(i = 0; i < m; i++)
        {
            cin >> x >> y >> Wei;


            if(Wei < E[x][y])     //坑点


                E[x][y] =  E[y][x] = Wei;
        }
        cin >> S >> T;
        for(i = 0; i < 201; i++)
        {
            Dij[i] = E[S][i];
            Vis[i] = false;
        }
        Dij[S] = 0;
        Vis[S] = true;
        for(i = 0; i < n; i++)
        {
            Min =INF;
            for(j = 0; j < n; j++)
            {
                if(!Vis[j] && Dij[j] < Min)
                {
                    Min = Dij[j];
                    u = j;
                }
            }
            Vis[u] = true;
            for(j = 0; j < n; j++)
            {
                if(E[u][j] < INF)
                {
                    if(Dij[j] > Dij[u] + E[u][j])
                        Dij[j] = Dij[u] + E[u][j];
                }
            }
        }
        if(Dij[T] == INF) cout << "-1\n"; else cout << Dij[T] << endl;
    }
    return 0;
}
