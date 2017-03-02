#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

struct Point{
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator = (const Point& b){
        this->x = b.x, this->y = b.y;

        return *this;
    }
};

inline double Cross(Point A, Point B, Point C){
    return (B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y);
}

inline double Distance(Point A, Point B){
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}

Point P[10010], C[10010];
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

int main()
{
    int N;
    while(scanf("%d", &N) != EOF){
        for(int i = 0; i < N; i++){
            scanf("%lf%lf", &P[i].x, &P[i].y);
        }
        for(int i = 1; i < N; i++){
            if(P[i].y < P[0].y || (P[i].y == P[0].y && P[i].x < P[0].x)){
                swap(P[i], P[0]);
            }
        }
        sort(P + 1, P + N, comp);
        C[0] = P[0];
        C[1] = P[1];
        total = 1;
        for(int i = 2; i < N; i++){
            while(total > 0 && Cross(C[total - 1], C[total], P[i]) <= 0){
                total--;
            }
            C[++total] = P[i];
        }
        double area = 0;
        for(int i = 1; i < total; i++){
            area += abs(Cross(C[0], C[i], C[i + 1]));
        }
        printf("%.0f\n", area / 100.0 - 0.5);
    }
    return 0;
}
