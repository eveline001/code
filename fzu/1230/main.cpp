#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Range{
    int L, R;

    bool operator < (const Range& other) const{
        if(this->R != other.R) return this->R < other.R;
        return this->L < other.L;
    }
};

Range R[40001];

int main()
{
    int n, ed, tol;

    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){scanf("%d%d", &R[i].L, &R[i].R); if(R[i].L > R[i].R) swap(R[i].L, R[i].R);}
        sort(R, R + n);
        ed = R[0].R, tol = 1;
        for(int i = 1; i < n; i++) if(R[i].L > ed) tol++, ed = R[i].R;
        printf("%d\n", n - tol);
    }
    return 0;
}
