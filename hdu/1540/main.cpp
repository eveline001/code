#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Node{
    int LeftConti, RightConti, MaxConti;
};

Node Tree[50000 << 2];
int Stack[50000];
int top;

void InitTree(int l, int r, int rt){
    if(l == r){
        Tree[rt].MaxConti = Tree[rt].LeftConti = Tree[rt].RightConti = 1;
        return;
    }
    Tree[rt].MaxConti = Tree[rt].LeftConti = Tree[rt].RightConti = r - l + 1;
    int mid = (l + r) >> 1;
    InitTree(l, mid, rt << 1);
    InitTree(mid + 1, r, (rt << 1) | 1);
}

void Update(int x, int flag, int l, int r, int rt){
    if(l == r){
        Tree[rt].MaxConti = Tree[rt].LeftConti = Tree[rt].RightConti = flag;
        return;
    }
    int mid = (l + r) >> 1;
    if(x <= mid){
        Update(x, flag, l, mid, rt << 1);
    }else{
        Update(x, flag, mid + 1, r, (rt << 1) | 1);
    }
    if(Tree[rt << 1].LeftConti == mid - l + 1){
        Tree[rt].LeftConti = Tree[rt << 1].LeftConti + Tree[(rt << 1) | 1].LeftConti;
    }else{
        Tree[rt].LeftConti = Tree[rt << 1].LeftConti;
    }
    if(Tree[(rt << 1) | 1].RightConti == r - mid){
        Tree[rt].RightConti = Tree[(rt << 1) | 1].RightConti + Tree[rt << 1].RightConti;
    }else{
        Tree[rt].RightConti = Tree[(rt << 1) | 1].RightConti;
    }
    Tree[rt].MaxConti = max(max(Tree[rt << 1].MaxConti, Tree[(rt << 1) | 1].MaxConti), Tree[rt << 1].RightConti + Tree[(rt << 1) | 1].LeftConti);
}

int Research(int x, int l, int r, int rt){
    if(l == r
       || Tree[rt].MaxConti == 0
       || Tree[rt].MaxConti == r - l + 1){
        return Tree[rt].MaxConti;
    }
    int mid = (l + r) >> 1;
    if(x <= mid){
        if(x >= mid - Tree[rt << 1].RightConti + 1){
            return Tree[rt << 1].RightConti + Tree[(rt << 1) | 1].LeftConti;
        }else{
            return Research(x, l, mid, rt << 1);
        }
    }else{
        if(x <= mid + Tree[(rt << 1) | 1].LeftConti){
            return Tree[rt << 1].RightConti + Tree[(rt << 1) | 1].LeftConti;
        }else{
            return Research(x, mid + 1, r, (rt << 1) | 1);
        }
    }
}

int main()
{
    int n, m, x;
    char op[2];

    while(scanf("%d%d", &n, &m) != EOF){
        top = 0;
        InitTree(1, n, 1);
        for(int i = 0; i < m; i++){
            scanf("%s", op);
            if(op[0] == 'D'){
                scanf("%d", &x);
                Update(x, 0, 1, n, 1);
                Stack[top++] = x;
            }else if(op[0] == 'Q'){
                scanf("%d", &x);
                printf("%d\n", Research(x, 1, n, 1));
            }else{
                if(top >= 1){
                    Update(Stack[--top], 1, 1, n, 1);
                }
            }
        }
    }
    return 0;
}
