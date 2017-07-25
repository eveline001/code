#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);

struct Point{
    double x, y;
    int id, v;

    Point(double x = 0.0, double y = 0.0, int id = 0, int v = 0) : x(x), y(y), id(id), v(v) {}

    Point operator = (const Point& b){
        this->x = b.x, this->y = b.y, this->id = b.id, this->v = b.v;
        return *this;
    }

    bool operator == (const Point& b) const{
        return this->x == b.x && this->y == b.y && this->v == b.v;;
    }
};

inline double Cross(Point A, Point B, Point C){
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

inline double Distance(Point A, Point B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

Point P[501], C[501];
int total;

bool comp(Point A, Point B){
    double angle = Cross(P[0], A, B);
    if(angle > 0){
        return true;
    }
    if(angle < 0){
        return false;
    }
    return Distance(P[0], A) < Distance(P[0], B);
}

Point A[501];
int vis[501];
int temp;

int main()
{
    int cas = 1, n, maxv, N;
    while(scanf("%d", &n) != EOF && n){
        maxv = 0;
        for(int i = 0; i < n; i++){
            scanf("%lf%lf%d", &A[i].x, &A[i].y, &A[i].v);
            maxv = max(maxv, A[i].v);
            A[i].id = i;
        }
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(A[i] == A[j]){
                    A[j].v = 0;
                    vis[i] = vis[j] = -1;
                }
            }
        }
        N = 0;
        for(int i = 0; i < n; i++){
            if(A[i].v == maxv){
                P[N++]= A[i];
            }
        }
        for(int i = 1; i < N; i++){
            if(P[i].y < P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)){
                swap(P[i], P[0]);
            }
        }
        total = 0;
        if(maxv > 0 && N > 0){
            sort(P + 1, P + N, comp);
            C[0] = P[0];
            if(N > 1){
                C[1] = P[1];
                total = 1;
                for(int i = 2; i < N; i++){
                    while(total > 0 && Cross(C[total - 1], C[total], P[i]) < 0){
                        total--;
                    }
                    C[++total] = P[i];
                }
                temp = total;
                for(int i = N - 2; i >= 0; i--){
                    while(total != temp && Cross(C[total - 1], C[total], P[i]) < 0){
                        total--;
                    }
                    C[++total] = P[i];
                }
            }
        }
        for(int i = 0; i <= total; i++){
            if(vis[C[i].id] != -1){
                vis[C[i].id] = 1;
            }
        }
        printf("Case #%d: ", cas++);
        for(int i = 0; i < n; i++){
            printf("%d", (maxv > 0) && (vis[i] > 0));
        }
        printf("\n");
    }
    return 0;
}
