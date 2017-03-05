#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

const int inf = 1e9;

struct Line{
    int x, y_down, y_up, flag;

    operator < (const Line& b) const{
        if(this->x == b.x){
            if(this->flag == b.flag){
                if(this->y_down == b.y_down){
                    return this->y_up < b.y_up;
                }else{
                    return this->y_down < b.y_down;
                }
            }else{
                return this->flag > b.flag;
            }
        }else{
            return this->x < b.x;
        }
    }

    Line(int x = 0, int y_down = 0, int y_up = 0, int flag = 1) : x(x), y_down(y_down), y_up(y_up), flag(flag) {}
};

Line L[5000 << 1];
int  T[20000 << 2];//统计下底边总长度
int  segnum[20000 << 2];//统计没有被覆盖的竖边个数
bool lseg[20000 << 2], rseg[20000 << 2];//表示某个区间最左边和最右边是否有下底边多于上底边
int  mark[20000 << 2];//表示下底边比上底边多的个数

void Upfather(int l, int r, int rt){
    if(mark[rt]){
        T[rt] = r - l + 1;
        lseg[rt] = rseg[rt] = true;
        segnum[rt] = 2;//该区间被一条底边全部覆盖,可用竖边为2
    }else if(l == r){
        T[rt] = segnum[rt] = 0;
        lseg[rt] = rseg[rt] = false;
    }else{
        T[rt] = T[rt << 1] + T[(rt << 1) | 1];
        segnum[rt] = segnum[rt << 1] + segnum[(rt << 1) | 1];
        lseg[rt] = lseg[rt << 1];
        rseg[rt] = rseg[(rt << 1) | 1];
        if(rseg[rt << 1] && lseg[(rt << 1) | 1]){
            segnum[rt] -= 2;//两个矩形相交(底边区域有重合)则减少两条竖边
        }
    }
}

void Update(int L,int R,int v,int l, int r, int rt){
    if(L <= l && r <= R){
        mark[rt] += v;
        Upfather(l, r, rt);
        return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, v,l, mid, rt << 1);
    }
    if(R > mid){
        Update(L, R, v, mid+1, r, (rt << 1) | 1);
    }
    Upfather(l, r, rt);
}

int main()
{
    int n, x1, x2, y1, y2, top, down, ans, prelen;

    while(scanf("%d", &n) != EOF){
        top = -inf;
        down = inf;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            L[i << 1] = Line(x1, y1, y2, 1);
            L[(i << 1) | 1]= Line(x2, y1, y2, -1);
            top = max(top, y2);
            down = min(down, y1);
        }
        sort(L, L + (n << 1));
        ans = prelen = 0;
        for(int i = 0; i < (n << 1); i++){
            Update(L[i].y_down, L[i].y_up - 1, L[i].flag, down, top, 1);
            ans += segnum[1] * (L[i + 1].x - L[i].x);//竖边增加的总长
            ans += T[1] - prelen > 0 ? T[1] - prelen : prelen - T[1];//底边增加的总长
            prelen = T[1];
        }
        printf("%d\n",ans);
    }
}


/*
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=20000+10;
int sum[MAX<<2];//统计下底边总长度
int segnum[MAX<<2];//统计没有被覆盖的竖边个数
bool lseg[MAX<<2],rseg[MAX<<2];//表示某个区间最左边和最右边是否有下底边多于上底边
int mark[MAX<<2];//表示下底边比上底边多的个数

struct seg{
    int l,r,h,d;
    seg(){}
    seg(int x1,int x2,int H,int c):l(x1),r(x2),h(H),d(c){}
    bool operator <(const seg&a)const{
        if(h == a.h)return d>a.d;//这里一定不能去掉,比如这组数据:2 0 0 4 4 0 4 4 8
        return h<a.h;
    }
}s[MAX];

void Upfather(int n,int left,int right){
    if(mark[n]){
        sum[n]=right-left+1;
        lseg[n]=rseg[n]=true;
        segnum[n]=2;//该区间被一条底边全部覆盖,可用竖边为2
    }
    else if(left == right)sum[n]=lseg[n]=rseg[n]=segnum[n]=0;
    else{
        sum[n]=sum[n<<1]+sum[n<<1|1];
        segnum[n]=segnum[n<<1]+segnum[n<<1|1];
        lseg[n]=lseg[n<<1];
        rseg[n]=rseg[n<<1|1];
        if(rseg[n<<1] && lseg[n<<1|1])segnum[n]-=2;//两个矩形相交(底边区域有重合)则减少两条竖边
    }
}

void Update(int L,int R,int d,int n,int left,int right){
    if(L<=left && right<=R){
        mark[n]+=d;
        Upfather(n,left,right);
        return;
    }
    int mid=left+right>>1;
    if(L<=mid)Update(L,R,d,n<<1,left,mid);
    if(R>mid)Update(L,R,d,n<<1|1,mid+1,right);
    Upfather(n,left,right);
}

int main(){
    int n,x1,x2,y1,y2;
    while(cin>>n){
        int k=0,left=INF,right=-INF;
        for(int i=0;i<n;++i){
            cin>>x1>>y1>>x2>>y2;
            s[k++]=seg(x1,x2,y1,1);
            s[k++]=seg(x1,x2,y2,-1);
            left=min(left,x1);
            right=max(right,x2);
        }
        sort(s,s+k);
        int ans=0,last=0;
        for(int i=0;i<k;++i){
            if(s[i].l<s[i].r)Update(s[i].l,s[i].r-1,s[i].d,1,left,right);
            ans+=segnum[1]*(s[i+1].h-s[i].h);//竖边增加的总长
            ans+=abs(sum[1]-last);//底边增加的总长
            last=sum[1];
        }
        printf("%d\n",ans);
    }
}
*/
