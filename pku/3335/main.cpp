//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//const double eps = 1e-8;
//int tol, pn, dq[20005], top, bot;
//
//struct Point{
//    double x, y;
//
//    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
//};
//
//struct Line{
//    Point a, b;
//    double angle;
//
//    Line& operator = (const Line& other){
//        this->a.x   = other.a.x, this->a.y   = other.a.y;
//        this->b.x   = other.b.x, this->b.y   = other.b.y;
//        this->angle = other.angle;
//        return *this;
//    }
//};
//
//Point p[20005];
//Line  l[20005];
//
//inline int dbcmp(double k){
//    return fabs(k) < eps ? 0 : k > 0 ? 1 : -1;
//}
//
//inline double multi(Point O, Point A, Point B){
//    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
//}
//
//inline bool cmp(const Line& l1, const Line& l2){
//    int d = dbcmp(l1.angle - l2.angle);
//    return d ? d < 0 : dbcmp(multi(l1.a, l2.a, l2.b)) > 0;
//}
//
//void addLine(Line& l, double x1, double y1, double x2, double y2){
//    l.a.x = x1, l.a.y = y1;
//    l.b.x = x2, l.b.y = y2;
//    l.angle = atan2(y2 - y1, x2 - x1);
//}
//
//Point getIntersect(Line l1, Line l2){
//    double A1 = l1.b.y - l1.a.y;
//    double B1 = l1.a.x - l1.b.x;
//    double C1 = (l1.b.x - l1.a.x) * l1.a.y - (l1.b.y - l1.a.y) * l1.a.x;
//    double A2 = l2.b.y - l2.a.y;
//    double B2 = l2.a.x - l2.b.x;
//    double C2 = (l2.b.x - l2.a.x) * l2.a.y - (l2.b.y - l2.a.y) * l2.a.x;
//    Point p((C2 * B1 - C1 * B2) / (A1 * B2 - A2 * B1), (C1 * A2 - C2 * A1) / (A1 * B2 - A2 * B1));
//    return p;
//}
//
//bool judge(Line l0, Line l1, Line l2){
//     Point p = getIntersect(l1, l2);
//     return dbcmp(multi(p, l0.a, l0.b)) < 0;
//}
//
//void HalfPlaneIntersect(){
//    int i, j;
//
//    sort(l, l + tol, cmp);
//    for(i = 0, j = 0; i < tol; i++) if(dbcmp(l[i].angle - l[j].angle) > 0) l[++j] = l[i];
//    tol = j + 1, dq[0] = 0, dq[1] = 1, top = 1, bot = 0;
//    for(i = 2; i < tol; i++){
//        while(top > bot && judge(l[i], l[dq[top]], l[dq[top - 1]])) top--;
//        while(top > bot && judge(l[i], l[dq[bot]], l[dq[bot + 1]])) bot++;
//        dq[++top] = i;
//    }
//    while(top > bot && judge(l[dq[bot]], l[dq[top]], l[dq[top - 1]])) top--;
//    while(top > bot && judge(l[dq[top]], l[dq[bot]], l[dq[bot + 1]])) bot++;
//    dq[++top] = dq[bot];
//    for(pn = 0, i = bot; i < top; i++, pn++) p[pn] = getIntersect(l[dq[i + 1]], l[dq[i]]);
//}
//
//
//double getArea(){
//    if(pn < 3) return 0;
//    double area = 0;
//    for(int i = 1; i < pn - 1; i++) area += multi(p[0], p[i], p[i + 1]);
//    if(area < 0) area = -area;
//    return area / 2;
//}
//
//int main()
//{
//    int T, n, x0, y0, x1, y1, x2, y2;
//
//    scanf("%d", &T);
//    for(int cas = 1; cas <= T; cas++){
//        tol = 0;
//        scanf("%d", &n);
//        scanf("%d %d", &x1, &y1);
//        x0 = x1, y0 = y1;
//        for(int i = 1; i < n; i++){
//            scanf("%d %d", &x2, &y2);
//            addLine(l[tol++], x2, y2, x1, y1);
//            x1 = x2, y1 = y2;
//        }
//        addLine(l[tol++], x0, y0, x1, y1);
//        HalfPlaneIntersect();
//        printf("%s\n", pn < 3 ? "NO" : "YES");
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const double eps = 1e-10;
const double maxl = 1e10;
const int maxn = 105;
const int MAXN = 10000;

int A[maxn], B[maxn], C[maxn];
int tol, pn, dq[20005], top, bot, n;

struct Point{
    double x, y;

    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};

struct Line{
    Point a, b;
    double angle;

    Line& operator = (const Line& other){
        this->a.x   = other.a.x, this->a.y   = other.a.y;
        this->b.x   = other.b.x, this->b.y   = other.b.y;
        this->angle = other.angle;
        return *this;
    }
};

Point p[20005];
Line  l[20005];

inline int dbcmp(double k){
    return fabs(k) < eps ? 0 : k > 0 ? 1 : -1;
}

inline double multi(Point O, Point A, Point B){
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

inline bool cmp(const Line& l1, const Line& l2){
    int d = dbcmp(l1.angle - l2.angle);
    return d ? d < 0 : dbcmp(multi(l1.a, l2.a, l2.b)) > 0;
}

void addLine(Line& l, double x1, double y1, double x2, double y2){
    l.a.x = x1, l.a.y = y1;
    l.b.x = x2, l.b.y = y2;
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
     Point p = getIntersect(l1, l2);
     return dbcmp(multi(p, l0.a, l0.b)) <= 0;
}

bool HalfPlaneIntersect(){
    int i, j;

    sort(l, l + tol, cmp);
    for(i = 0, j = 0; i < tol; i++) if(dbcmp(l[i].angle - l[j].angle) > 0) l[++j] = l[i];
    tol = j + 1, dq[0] = 0, dq[1] = 1, top = 1, bot = 0;
    for(i = 2; i < tol; i++){
        while(top > bot && judge(l[i], l[dq[top]], l[dq[top - 1]])) top--;
        while(top > bot && judge(l[i], l[dq[bot]], l[dq[bot + 1]])) bot++;
        dq[++top] = i;
    }
    while(top > bot && judge(l[dq[bot]], l[dq[top]], l[dq[top - 1]])) top--;
    while(top > bot && judge(l[dq[top]], l[dq[bot]], l[dq[bot + 1]])) bot++;
    return top - bot > 1 ? true : false;
    dq[++top] = dq[bot];
    for(pn = 0, i = bot; i < top; i++, pn++) p[pn] = getIntersect(l[dq[i + 1]], l[dq[i]]);
}


double getArea(){
    if(pn < 3) return 0;
    double area = 0;
    for(int i = 1; i < pn - 1; i++) area += multi(p[0], p[i], p[i + 1]);
    if(area < 0) area = -area;
    return area / 2;
}

void solve() {
    int i, j;
    double x1, y1, x2, y2, a, b, c;
    tol = 0;
    addLine(l[tol++], 0, 0, maxl, 0);
    addLine(l[tol++], maxl, 0, maxl, maxl);
    addLine(l[tol++], maxl, maxl, 0, maxl);
    addLine(l[tol++], 0, maxl, 0, 0);
    for (i = 0; i < n; i++) {
         bool flag = false, tol = 4;
         for (j = 0; j < n; j++)
            if (i != j) {
                a = 1.0 / A[j] - 1.0 / A[i];
                b = 1.0 / B[j] - 1.0 / B[i];
                c = 1.0 / C[j] - 1.0 / C[i];
                int d1 = dbcmp(a);
                int d2 = dbcmp(b);
                int d3 = dbcmp(c);
                if (!d1) {
                    if (!d2) {
                        if (d3 <= 0) {
                            flag = true; break;
                        }
                        continue;
                    }
                    x1 = 0, x2 = d2, y1 = y2 = - c / b;
                } else {
                    if (!d2) { x1 = x2 = - c / a, y1 = 0, y2 = -d1;}
                    else { x1 = 0, y1 = - c / b, x2 = d2, y2 = -(c + a * x2) / b;}
                }
                addLine(l[tol++], x1, y1, x2, y2);
            }
         if (flag || HalfPlaneIntersect()) printf ("No\n");
         else printf ("Yes\n");
    }
}
int main()
{
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        scanf ("%d%d%d", &A[i], &B[i], &C[i]);
    solve();

    return 0;
}
