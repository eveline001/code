#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

using namespace std;

class Line{
public:
    double x;
    double y_up;
    double y_down;
    int    flag;

    Line(double x, double y_up, double y_down, double flag) : x(x), y_up(y_up), y_down(y_down), flag(flag) {}
    Line() {}

    operator < (const Line b) const{
        if(this->x != b.x){
            return this->x < b.x;
        }
        return this->flag > b.flag;
    }

    operator == (const Line b) const{
        return this->x == b.x
               && this->y_up == b.y_up
               && this->y_down == b.y_down
               && this->flag == b.flag;
    }
};

struct Node{
    int    cnt;
    double len[2];
};

map<double, int> Record;

double pos[2500];
Line   line[2500];
Node   Tree[2000 << 2];

void BuildUp(int l, int r, int rt){
    if(l == r){
        Tree[rt].cnt = 0;
        Tree[rt].len[0] = Tree[rt].len[1] = 0;
        return;
    }
    int m = (l + r) >> 1;
    BuildUp(l, m, rt << 1);
    BuildUp(m + 1, r, (rt << 1) | 1);
}

void PushUp(int l, int r, int rt){
    if(Tree[rt].cnt >= 1){
        Tree[rt].len[0] = pos[r + 1] - pos[l];
    }else if(l == r){
        Tree[rt].len[0] = 0;
    }else{
        Tree[rt].len[0] = Tree[rt << 1].len[0] + Tree[(rt << 1) | 1].len[0];
    }
    if(Tree[rt].cnt >= 2){
        Tree[rt].len[1] = pos[r + 1] - pos[l];
    }else if(l == r){
        Tree[rt].len[1] = 0;
    }else if(Tree[rt].cnt == 1){
        Tree[rt].len[1] = Tree[rt << 1].len[0] + Tree[(rt << 1) | 1].len[0];
    }else{
        Tree[rt].len[1] = Tree[rt << 1].len[1] + Tree[(rt << 1) | 1].len[1];
    }
}

void Update(int L, int R, int v, int l, int r, int rt){
    if(L == l && R == r){
        Tree[rt].cnt += v;
        PushUp(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if(R <= mid){
        Update(L, R, v, l, mid, rt << 1);
    }else if(L >= mid + 1){
        Update(L, R, v, mid + 1, r, (rt << 1) | 1);
    }else{
        Update(L, mid, v, l, mid, rt << 1);
        Update(mid + 1, R, v, mid + 1, r, (rt << 1) | 1);
    }
    PushUp(l, r, rt);
}

int main()
{
    int T, N, num;
    double x1, y1, x2, y2, ans;

    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &N);
        Record.clear();
        for(int i = 0 ; i < N; i++){
            scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            line[2*i].x          = x1;
            line[2*i].y_up       = y2;
            line[2*i].y_down     = y1;
            line[2*i].flag       =  1;
            line[2*i + 1].x      = x2;
            line[2*i + 1].y_up   = y2;
            line[2*i + 1].y_down = y1;
            line[2*i + 1].flag   = -1;
            if(!Record[y1]) Record[y1]++;
            if(!Record[y2]) Record[y2]++;
        }
        num = Record.size();
        sort(line, line + 2 * N);
        int temp = 0;
        for(auto it = Record.begin(); it != Record.end(); ++it, temp++){
            it->second = temp;
            pos[temp] = it->first;
        }
        BuildUp(1, num - 1, 1);
        ans = 0;
        for(int i = 0; i < 2*N; i++){
            Update(Record[line[i].y_down], Record[line[i].y_up] - 1, line[i].flag, 0, num - 1, 1);
            ans += Tree[1].len[1] * (line[i + 1].x - line[i].x);
        }
        printf("%.2f\n", ans);
    }
}
