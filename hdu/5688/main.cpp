#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

map<string, int> D;

int main()
{
    int N;
    string name;

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> name;
        sort(name.begin(), name.end());
        cout << D[name] << '\n';
        D[name]++;
    }
    return 0;
}
