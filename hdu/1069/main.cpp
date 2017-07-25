#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int INF = 0x7fffffff;

struct Node{
    int a, b, c;

    Node(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}

    Node& operator = (const Node& other){
        this->a = other.a, this->b = other.b, this->c = other.c;
        return *this;
    }

    bool operator < (const Node& other) const{
        if(this->a == other.a && this->b == other.b) return this->c < other.c;
        if(this->a == other.a) return this->b < other.b;
        return this->a < other.a;
    }
};

vector<Node> v;

inline void AddNode(int x, int y, int z){
    v.push_back(Node(x, y, z));
    v.push_back(Node(y, x, z));
}

int dp[200];

int main()
{
    int n, a, b, c, cas = 0, maxlen;

    while(scanf("%d", &n) != EOF && n){
        v.clear();
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &a, &b, &c);
            v.push_back(Node(a, b, c)); v.push_back(Node(a, c, b));
            v.push_back(Node(b, a, c)); v.push_back(Node(b, c, a));
            v.push_back(Node(c, a, b)); v.push_back(Node(c, b, a));
        }
        sort(v.begin(), v.end());
        maxlen = 0;
        for(int i = 0; i < 6 * n; i++) dp[i] = v[i].c;
        for(int i = 1; i < 6 * n; i++){
            for(int j = 0; j < i; j++){
                if(v[i].a > v[j].a && v[i].b > v[j].b) dp[i] = max(dp[i], dp[j] + v[i].c);
            }
            maxlen = max(maxlen, dp[i]);
        }
        ++cas;
        printf("Case %d: maximum height = %d\n", cas, maxlen);
    }
    return 0;
}
