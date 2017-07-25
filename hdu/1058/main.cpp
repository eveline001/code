
#include <iostream>
#include <set>

using namespace std;

set<long long> temp;

long long ans[5843];

int main()
{
    int n;

    temp.insert(1);
    auto ptr = temp.begin();
    while(temp.size() <= 8192)
    {
        temp.insert(*ptr*2);
        temp.insert(*ptr*3);
        temp.insert(*ptr*5);
        temp.insert(*ptr*7);
        ++ptr;
    }

    int i = 1;
    for(auto it = temp.begin(); i <= 5842; i++, ++it)
    {
        ans[i] = *it;
    }

    while(cin >> n)
    {
        if(n == 0)
            return 0;

        if(n%100 == 11 || n%100 == 12 || n%100 ==13)
        {
            cout << "The " << n << "th humble number is " << ans[n] << ".\n";
            continue;
        }

        switch(n % 10)
        {
            case 1:cout << "The " << n << "st humble number is " << ans[n] << ".\n"; break;
            case 2:cout << "The " << n << "nd humble number is " << ans[n] << ".\n"; break;
            case 3:cout << "The " << n << "rd humble number is " << ans[n] << ".\n"; break;
            default:cout << "The " << n << "th humble number is " << ans[n] << ".\n";
        }
    }
    return 0;
}
