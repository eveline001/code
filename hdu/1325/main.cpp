#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void ReSet(int F[], int n){
    for(int i = 1; i <= n; i++){
        F[i] = i;
    }
}

int FindFather(int F[], int x){
    if(F[x] == x){
        return x;
    }else{
        return FindFather(F, F[x]);
    }
}

int Merge(int F[], int a, int b){
    int Fa = FindFather(F, a),
        Fb = FindFather(F, b);

    if(Fa != Fb){
        return F[Fb] = F[Fa];
    }else{
        return -1;
    }
}

int F[1001];
bool vis[1001];

int main()
{
    int u, v, RootNum, cas = 1;
    bool IsTree;

    while(true){
        IsTree = true;
        memset(vis, false, sizeof(vis));
        ReSet(F, 1000);
        RootNum = 0;
        while(scanf("%d%d", &u, &v) != EOF && (u || v)){
            if(u < 0 || v < 0){
                return 0;
            }
            vis[u] = true;
            if(vis[v] && FindFather(F, v) != v){
                IsTree = false;
            }
            vis[v] = true;
            if(FindFather(F, u) != FindFather(F, v)){
                Merge(F, u, v);
            }else{
                IsTree = false;
            }
        }
        for(int i = 1; i <= 1000; i++){
            if(vis[i] && F[i] == i){
                RootNum++;
            }
        }
        if((IsTree && RootNum <= 1)){
            printf("Case %d is a tree.\n", cas++);
        }else{
            printf("Case %d is not a tree.\n", cas++);
        }
    }
    return 0;
}


/*
//MD´íÔÚÄÄ= =
#include <iostream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

struct Edge{
    Edge(int x = 0, int y = 0) : x(x), y(y){
    }

    int x;
    int y;

    Edge operator = (const Edge& a){
        this->x = a.x;
        this->y = a.y;
        return *this;
    }

    bool operator == (const Edge& b) const{
        if(this->x == b.x && this->y == b.y){
            return true;
        }
        return false;
    }

    bool operator < (const Edge& b) const{
        if(this->x < b.x){
            return true;
        }else if(this->x == b.x){
            return this->y < b.y;
        }else{
            return false;
        }
    }

    bool operator > (const Edge& b) const{
        return b < *this;
    }

    bool operator <= (const Edge& b) const{
        return !(*this > b);
    }

    bool operator >= (const Edge& b) const{
        return !(*this < b);
    }

    bool operator != (const Edge& b) const{
        return !(*this == b);
    }
};

map<int ,int> in;
set<int> S;
set<Edge> SE;

int main()
{
    int u, v, NodeNum, EdgeNum = 0, cas = 1, before;
    bool IsTree = true;

    S.clear();
    SE.clear();
    in.clear();
    while(scanf("%d%d", &u, &v) != EOF){
        if(u < 0 || v < 0){
            return 0;
        }
        if(u == 0 && v == 0){
            NodeNum = S.size();
            if((IsTree && NodeNum == EdgeNum + 1) || (NodeNum == 0 && EdgeNum == 0)){
                printf("Case %d is a tree.\n", cas++);
            }else{
                printf("Case %d is not a tree.\n", cas++);
            }
            IsTree = true;
            NodeNum = EdgeNum = 0;
            S.clear();
            SE.clear();
            in.clear();
            continue;
        }
        in[v]++;
        S.insert(u);
        S.insert(v);
        before = SE.size();
        SE.insert(Edge(u, v));
        SE.insert(Edge(v, u));
        if(SE.size() == before){
            IsTree = false;
        }
        if(u != v){
            EdgeNum++;
        }
        if(in[v] >= 2){
            IsTree = false;
        }
    }
    return 0;
}
*/
