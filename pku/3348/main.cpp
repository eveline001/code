#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1e-8;

int n, pn, dq[10010], top, bot;

struct Point{
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    Point operator = (const Point& b){
        this->x = b.x, this->y = b.y;

        return *this;
    }
};

struct Line{
    Point a, b;
    double angle;

    Line& operator = (const Line& l){
        a.x   = l.a.x;
        a.y   = l.a.y;
        b.x   = l.b.x;
        b.y   = l.b.y;
        angle = l.angle;
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

Point p[10010];
Line  l[10010];

int dblcmp(double k){
    if(fabs(k) < eps) return 0;
    return k > 0 ? 1 : -1;
}

double multi(Point p0, Point p1, Point p2){
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}

bool cmp(const Line& l1, const Line& l2){
    int d = dblcmp(l1.angle - l2.angle);
    if(!d) return dblcmp(multi(l1.a, l2.a, l2.b)) > 0;
    return d < 0;
}

void addLine(Line& l, double x1, double y1, double x2, double y2){
    l.a.x = x1;
    l.a.y = y1;
    l.b.x = x2;
    l.b.y = y2;
    l.angle = atan2(y2 - y1, x2 - x1);
}

Point getIntersect(Line l1, Line l2){
    double A1 = l1.b.y - l1.a.y;
    double B1 = l1.a.x - l1.b.x;
    double C1 = (l1.b.x - l1.a.x) * l1.a.y - (l1.b.y - l1.a.y) * l1.a.x;
    double A2 = l2.b.y - l2.a.y;
    double B2 = l2.a.x - l2.b.x;
    double C2 = (l2.b.x - l2.a.x) * l2.a.y - (l2.b.y - l2.a.y) * l2.a.x;
    Point p((C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1), (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1));
    return p;
}

bool judge(Line l0, Line l1, Line l2){
     Point p;
     p = getIntersect(l1, l2);
     return dblcmp(multi(p, l0.a, l0.b)) < 0;
}

void HalfPlaneIntersect(){
    int i, j;

    sort(l, l + n, cmp);
    for(i = 0, j = 0; i < n; i++)
        if(dblcmp(l[i].angle - l[j].angle) > 0)
            l[++j] = l[i];
    n     = j + 1;
    dq[0] = 0;
    dq[1] = 1;
    top   = 1;
    bot   = 0;
    for(i = 2; i < n; i++){
        while(top > bot && judge(l[i], l[dq[top]], l[dq[top - 1]])){
            top--;
        }
        while(top > bot && judge(l[i], l[dq[bot]], l[dq[bot + 1]])){
            bot++;
        }
        dq[++top] = i;
    }
    while(top > bot && judge(l[dq[bot]], l[dq[top]], l[dq[top - 1]])){
        top--;
    }
    while(top > bot && judge(l[dq[top]], l[dq[bot]], l[dq[bot + 1]])){
        bot++;
    }
    dq[++top] = dq[bot];
    for(pn = 0, i = bot; i < top; i++, pn++){
        p[pn] = getIntersect(l[dq[i + 1]], l[dq[i]]);
    }
}

double getArea(){
    if(pn < 3) return 0;
    double area = 0;
    for(int i = 1; i < pn - 1; i++)
        area += multi(p[0], p[i], p[i + 1]);
    if(area < 0) area = -area;
    return area / 2;
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
        for(int i = 1; i <= total; i++){
            addLine(l[i - 1], C[i - 1].x, C[i - 1].y, C[i].x, C[i].y);
        }
        addLine(l[total], C[total].x, C[total].y, C[0].x, C[0].y);
        n = total + 1;
        HalfPlaneIntersect();
        printf("%.0f\n", getArea() / 50.0 - 0.5);
    }
}
