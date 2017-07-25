#include <iostream>
#include <string>

using namespace std;

string add(string a, string b){
    string c;

    return c;
}

string a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> a >>b;
        cout << "Case " << t << ":\n" << a << " + " << b << " = " << add(a, b) << endl << endl;
    }
}
