#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> M;
map<string, int>::iterator it, ans;

int main()
{
    string s;
    int n, max;
    ios_base::sync_with_stdio(false);
    while(cin >> n, n){
        M.clear();
        for(int i = 0; i < n; i++){
            cin >> s;
            M[s]++;
        }
        it = M.begin();
        max = it->second;
        ans = it;
        for(;it != M.end(); ++it){
            if(it->second > max){
                max = it->second;
                ans = it;
            }
        }
        cout << ans->first << endl;
    }
}
