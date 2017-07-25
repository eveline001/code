#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MOD = 10007;

int Sum[100000 << 2][3];

int set[100000 << 2], add[100000 << 2], mul[100000 << 2];

void Set(int val, int l, int r, int rt){
    if(val >= MOD){
        val %= MOD;
    }
    Sum[rt][0] = (r - l + 1) * val % MOD;
    Sum[rt][1] = Sum[rt][0] * val % MOD;
    Sum[rt][2] = Sum[rt][1] * val % MOD;
    set[rt] = val;
    mul[rt] = 1;
    add[rt] = 0;
    return;
}

void Mul(int val, int l, int r, int rt){
    if(val >= MOD){
        val %= MOD;
    }
    Sum[rt][0] = Sum[rt][0] * val % MOD;
    Sum[rt][1] = Sum[rt][1] * val % MOD * val % MOD;
    Sum[rt][2] = Sum[rt][2] * val % MOD * val % MOD * val % MOD;
    mul[rt] = mul[rt] * val % MOD;
    add[rt] = add[rt] * val % MOD;
    return;
}

void Add(int val, int l, int r, int rt){
    if(val >= MOD){
        val %= MOD;
    }
    Sum[rt][2] = (Sum[rt][2] + 3 * Sum[rt][1] % MOD * val % MOD + 3 * Sum[rt][0] * val % MOD * val % MOD + (r - l + 1) * val % MOD * val % MOD * val % MOD) % MOD;
    Sum[rt][1] = (Sum[rt][1] + 2 * Sum[rt][0] % MOD * val % MOD + (r - l + 1) * val % MOD * val % MOD) % MOD;
    Sum[rt][0] = (Sum[rt][0] + (r - l + 1) * val % MOD) % MOD;
    add[rt] = (add[rt] + val) % MOD;
    return;
}

void PushDown(int l, int r, int rt){
    int mid = (l + r) >> 1;
    if(set[rt]){
        Set(set[rt], l, mid, rt << 1);
        Set(set[rt], mid + 1, r, rt << 1 | 1);
        set[rt] = 0;
    }
    if(mul[rt] != 1){
        Mul(mul[rt], l, mid, rt << 1);
        Mul(mul[rt], mid + 1, r, rt << 1 | 1);
        mul[rt] = 1;
    }
    if(add[rt]){
        Add(add[rt], l, mid, rt << 1);
        Add(add[rt], mid + 1, r, rt << 1 | 1);
        add[rt] = 0;
    }
}

void PushUp(int rt){
    Sum[rt][0] = (Sum[rt << 1][0] + Sum[rt << 1 | 1][0]) % MOD;
    Sum[rt][1] = (Sum[rt << 1][1] + Sum[rt << 1 | 1][1]) % MOD;
    Sum[rt][2] = (Sum[rt << 1][2] + Sum[rt << 1 | 1][2]) % MOD;
}

void Update(int L, int R, int val, int flag, int l, int r, int rt){
    if(L <= l && R >= r){
        if(flag == 1){
            Add(val, l, r, rt);
        }else if(flag == 2){
            Mul(val, l, r, rt);
        }else{
            Set(val, l, r, rt);
        }
        return;
    }
    PushDown(l, r, rt);
    int mid = (l + r) >> 1;
    if(L <= mid){
        Update(L, R, val, flag, l, mid, rt << 1);
    }
    if(R > mid){
        Update(L, R, val, flag, mid + 1, r, rt << 1 | 1);
    }
    PushUp(rt);
}

int Query(int L, int R, int val, int l, int r, int rt){
    int res = 0;
    if(L <= l && R >= r){
        return Sum[rt][val - 1] % MOD;
    }
    PushDown(l, r, rt);
    int mid = (l + r) >> 1;
    if(L <= mid){
        res += Query(L, R, val, l, mid, rt << 1);
        if(res >= MOD){
            res %= MOD;
        }
    }
    if(R > mid){
        res += Query(L, R, val, mid + 1, r, rt << 1 | 1);
        if(res >= MOD){
            res %= MOD;
        }
    }
    return res;
}

int main()
{
    int n, m, op, x, y, c;

    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        memset(set, 0, sizeof(set));
        memset(add, 0, sizeof(add));
        for(int i = 0; i < (n << 2); i++){
            mul[i] = 1;
        }
        memset(Sum, 0, sizeof(Sum));
        for(int i = 0; i < m; i++){
            scanf("%d%d%d%d", &op, &x, &y, &c);
            if(op == 4){
                printf("%d\n", Query(x, y, c, 1, n, 1));
            }else{
                Update(x, y, c, op, 1, n, 1);
            }
        }
    }
    return 0;
}
