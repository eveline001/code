#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 7;

struct Node{
    int num, cost;

    Node(int num = 0, int cost = 0) : num(num), cost(cost) {}

    Node& operator = (const Node& other){
        this->num = other.num, this->cost = other.cost;
        return *this;
    }

    bool operator < (const Node& other) const{
        return this->cost > other.cost;
    }
};

Node Ori[MAXN];
priority_queue<Node> Q;

int main()
{
    int n, l, d;
    char c[16];
    long long cost, len, pre, need;

    while(scanf("%d", &n) != EOF){
        cost = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%s%d", &l, c, &d);
            if(c[0] == ')'){
                Ori[i] = Node(l, d);
            }else{
                cost += (long long)l * d;
                Ori[i] = Node(l, -d);
            }
        }
        len = pre = need = 0;
        Node p, q;
        while(!Q.empty()) Q.pop();
        for(int i = 0; i < n; i++){
            p = Ori[i];
            len += p.num;
            need = (len + 1) / 2 - pre;
            pre = (len + 1) / 2;
            Q.push(p);
            while(need > 0 && !Q.empty()){
                q = Q.top();
                Q.pop();
                if(q.num > need){
                    q.num -= need;
                    cost += need * q.cost;
                    need = 0;
                    Q.push(q);
                }else{
                    cost += (long long)q.num * q.cost;
                    need -= q.num;
                }
            }
        }
        printf("%lld\n", cost);
    }
    return 0;
}
