#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct Characters{
    int val;
    int cnt;

    Characters(int val = 0, int cnt = 0) : val(val), cnt(cnt) {}

    operator < (const Characters& other) const{
        return this->val > other.val;
    }
};

Characters C[26];

int main()
{
    int T, n, val, cnt, ans, Tol, This, detVal;

    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        ans = Tol = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &val, &cnt);
            C[i] = Characters(val, cnt);
        }
        sort(C, C + n);
        detVal = This = 0;
        while(true){
            if(This >= n){
                break;
            }
            if(C[This].cnt == 0){
                This++;
            }else{
                detVal += C[This].val;
                if(detVal > 0){
                    ans += detVal;
                    C[This].cnt--;
                    Tol--;
                }else{
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
