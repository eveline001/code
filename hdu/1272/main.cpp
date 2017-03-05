/*
//WA 不保证每个点都是联通的，以下代码至少在一个单独的点和一个有环的图的情况下WA
#include <iostream>
#include <set>

using namespace std;

class Edge{
public:
    Edge(int x, int y) : x(x < y ? x : y), y(x < y ? y : x){
    }

    int x;
    int y;

    Edge operator = (const Edge& a){
        x = a.x;
        y = a.y;
    }

    bool operator == (const Edge& b) const{
        if(this->x == b.x && this->y == b.y) return true;
        return false;
    }

    bool operator < (const Edge& b) const{
        if(this->x < b.x) return true;
            else if(this->x == b.x) return this->y < b.y;
                else return false;
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

set<Edge> Edges;

set<int> Points;

int main()
{
	int a, b;

    while(cin >> a >> b)
    {
        if(a == -1 && b  == -1) return 0;
        if(a == 0 && b == 0)
        {
            if(Points.size()-1 == Edges.size()) cout << "Yes\n";
                else cout << "No\n";
            Edges.clear();
            Points.clear();
            continue;
        }
        Points.insert(a);
        Points.insert(b);
        if(a != b)Edges.insert(Edge(a, b));
    }
}
*/

//并查集将两端点放入集合，存在一条边两端点在同一集合时即为成环
//390ms 20160607
#include <iostream>
#include <cstring>

using namespace std;

int p[100010];

int FindFather(int x){
    if(p[x] == -1) return p[x] = x;
    if(p[x] ==  x) return x;
    return p[x] = FindFather(p[x]);
}

int Link(int a, int b){
    int fa = FindFather(a);
    int fb = FindFather(b);

    if(fa == fb) return -1;
    return p[fb] = p[fa];
}

int main(){
    int a, b, i, count;

    memset(p, -1, sizeof(p));
    while(cin >> a >> b){
        if(a == -1 && b == -1) return 0;
        if(a ==  0 && b ==  0){
            count = 0;
            for(i = 0; i < 10010; i++){
                if(p[i] == i) count++;
                if(count >= 2){
                    cout << "No\n";
                    break;
                }
            }
            if(count <= 1) cout << "Yes\n";
            memset(p, -1, sizeof(p));
            continue;
        }
        if(Link(a, b) == -1){
            while(!(a == 0 && b ==0)) cin >> a >> b;
            cout << "No\n";
            memset(p, -1, sizeof(p));
            continue;
        }
    }
    return 0;
}


//78ms 2016101
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

int Fa[100001];

int FindFather(int x){
    if(Fa[x] == -1){
        return Fa[x] = x;
    }
    if(Fa[x] == x){
        return x;
    }
    return Fa[x] = FindFather(Fa[x]);
}

int Merge(int a, int b){
    int fa = FindFather(a),
        fb = FindFather(b);

    if(fa == fb){
        return 0;
    }

    return Fa[fa] = Fa[fb];
}

void skip(){
    int a, b;

    while(scanf("%d%d", &a, &b) && a && b);
}

int main()
{
    vector<int> v;
    int a, b, count;

    memset(Fa, -1, sizeof(Fa));
    v.clear();
    while(scanf("%d%d", &a, &b) && a != -1 && b != -1){
        if(a == 0 && b == 0){
            count = 0;
            for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
                if(Fa[*it] == *it){
                    count++;
                }
                if(count >= 2){
                    printf("No\n");
                    break;
                }
            }
            if(count <= 1){
                printf("Yes\n");
            }
            memset(Fa, -1, sizeof(Fa));
            v.clear();
            continue;
        }
        v.push_back(a);
        v.push_back(b);
        if(!Merge(a, b)){
            printf("No\n");
            skip();
            memset(Fa, -1, sizeof(Fa));
            v.clear();
        }
    }
}
