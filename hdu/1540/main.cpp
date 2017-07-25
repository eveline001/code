#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node
{
    int l, r;
    int ls ,rs, ms;//分别表示左边最大连续，右边最大连续，以及整个区间内的最大连续长度
};

node s[50050 << 2];

int n, m;
int op[50010];

void InitTree(int l,int r,int k)
{
    s[k].l = l;
    s[k].r = r;
    s[k].ls = s[k].rs = s[k].ms = r - l + 1;//最开始的时候全都是连着的。所以长度为r-l+1
    if (l == r){
        return;
    }
    int mid = (l + r) >> 1;
    InitTree(l, mid, k << 1);
    InitTree(mid + 1, r, (k << 1) + 1);
}

void UpdataTree(int x,int flag,int k)//x表示修复或者破坏的数字，flag用来标记是破坏还是修复
{
    if(s[k].l == s[k].r){
        if (flag == 1){
            s[k].ls = s[k].rs = s[k].ms = 1;//修复
        }else{
            s[k].ls = s[k].rs = s[k].ms = 0;//破坏
        }
        return;
    }
    int mid = (s[k].l + s[k].r) >> 1;
    if(x <= mid){
        UpdataTree(x, flag, k << 1);
    }else{
        UpdataTree(x, flag, (k << 1) + 1);
    }
    if(s[k << 1].ls == s[k << 1].r - s[k << 1].l + 1){//左区间的左连续=左子树的长度，就说名左区间的数全部连续，（左子树区间满了），整个区间的左区间就应该加上有区间的左部分。
        s[k].ls = s[k << 1].ls + s[(k << 1) + 1].ls;
    }else{
        s[k].ls = s[k << 1].ls;
    }
    if(s[(k << 1) + 1].rs == s[(k << 1) + 1].r - s[(k << 1) + 1].l + 1){//同理
        s[k].rs = s[(k << 1) + 1].rs + s[k << 1].rs;
    }else{
        s[k].rs = s[(k << 1) + 1].rs;
    }
    s[k].ms = max(max(s[k << 1].ms, s[(k << 1) + 1].ms), s[k << 1].rs + s[(k << 1) + 1].ls);//整个区间内的最大连续应为：左子树最大区间，右子树最大区间，左右子树合并的中间区间，三者中取最大
}

int SearchTree(int x,int k)
{
    if(s[k].l == s[k].r
       || s[k].ms == 0
       ||s[k].ms == s[k].r - s[k].l + 1){//到了叶子节点或者该访问区间为空或者已满都不必要往下走了
        return s[k].ms;
    }
    int mid = (s[k].l + s[k].r) >> 1;
    if(x <= mid)
    {
        if (x >= s[k << 1].r - s[k << 1].rs + 1){//判断当前这个数是否在左区间的右连续中，其中s[2*k].r-s[2*k].rs+1代表左子树右边连续区间的左边界值，即有连续区间的起点
            return s[k << 1].rs + s[(k << 1) + 1].ls;//也可以SearchTree(x,2*k)+SearchTree(mid+1,2*k+1);
        }else{
            return SearchTree(x, k << 1);
        }
    }else{
        if(x <= s[(k << 1) + 1].l + s[(k << 1) + 1].ls - 1){//判断当前这个数是否在左区间的右连续中，其中s[2*k].r-s[2*k].rs+1代表左子树右边连续区间的左边界值，即有连续区间的起点
            return s[k << 1].rs + s[(k << 1) + 1].ls;//这种方法SearchTree(x,2*k+1)+SearchTree(mid,2*k);也是可以的，但是比较浪费时间
        }else{
            return SearchTree(x,(k << 1) + 1);
        }
    }
}

int main()
{
    int x;
    char ch[2];

    while(scanf("%d%d", &n, &m) != EOF){
        int top = 0;
        InitTree(1, n, 1);
        while(m--){
            scanf("%s", ch);
            if(ch[0] == 'D'){
                scanf("%d", &x);
                op[top++] = x;
                UpdataTree(x, 0, 1);
            }else if(ch[0] == 'Q'){
                scanf("%d", &x);
                printf("%d\n", SearchTree(x, 1));
            }else{
                if(x > 0){
                    x = op[--top];
                    UpdataTree(x, 1, 1);
                }
            }
        }
    }
    return 0;
}
