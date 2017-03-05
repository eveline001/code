#include <iostream>

using namespace std;

int main()
{
    int T, N, i, j, a, ans, max, b, fb, e, min, s;

    cin >> T;

    for(i = 1; i <= T; i++){
        cin >> N;
        max = 0;
        ans = 0;
        fb  = 1;
        b   = N;
        for(j = 1; j <= N; j++){
            cin >> a;
            if(j == 1){
                min = a;
                s   = 1;
            }else{
                if(min < a)
                {
                    min = a;
                    s   = j;
                }
            }
            if(a >= 0){
                if(max < 0){
                    fb = j;
                    max = 0;
                }
                max += a;
                if(max >= ans){
                    ans = max;
                    b = fb;
                    e = j;
                }
            }else{
                max += a;
            }
        }
        if(fb < e){
            b = fb;
        }
        if(min >= 0){
            cout << "Case " << i << ":\n"
                 << ans << ' ' << b << ' ' << e << endl;
        }else{
            cout << "Case " << i << ":\n"
                 << min << ' ' << s << ' ' << s << endl;
        }
        if(i != T)
        {
            cout << endl;
        }
    }
}
