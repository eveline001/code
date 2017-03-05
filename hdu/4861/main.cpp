#include <iostream>

using namespace std;

int m[65536];

int main()
{
    int k, p;

    while(cin >> k >> p)
    {
        if((k / (p-1) ) % 2 == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
