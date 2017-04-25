#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 5e4 + 7;

struct Line{
    int l, r;

    bool operator < (const Line& other){
        if(this->l != other.l) return this->l < other.l;
        return this->r < other.r;
    }
};

Line L[MAX];

int main()
{
    int n, ans, l, r, pos;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &l, &r);
        L[i].l = l, L[i].r = r;
    }
    sort(L, L + n);
    ans = 0;
    pos = L[0].r;
    for(int i = 1; i < n; i++){
        if(L[i].r >= pos){ans = max(ans, pos - L[i].l), pos = L[i].r;}
        else ans = max(ans, L[i].r - L[i].l);
    }
    printf("%d\n", ans);
    return 0;
}
