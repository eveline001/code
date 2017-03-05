#include <iostream>

using namespace std;

int main()
{
    int T, n, a, ans;
    cin >> T;
    for(int cas = 1; cas <= T; cas++){
        cin >> n;
        ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a;
            ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}
