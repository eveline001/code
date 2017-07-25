//2648
#include <iostream>
#include <map>

using namespace std;

map<string, int> Prices;

int main()
{
    int n, m, i, j, price, max, ranked;
    string ShopName;
    map<string, int>::iterator it;

    while(cin >> n)
    {
        for(i = 0; i < n; i++)
        {
            cin >> ShopName;
            Prices[ShopName] = 0;
        }

        cin >> m;
        for(i = 0; i < m; i++)
        {
            for(j = 0; j < n; j++)
            {
                cin >> price >> ShopName;
                Prices[ShopName] += price;
            }

            it     = Prices.begin();
            max    = Prices["memory"];
            ranked = 0;
            for(; it != Prices.end(); ++it)
            {
                if(it->second > max)
                {
                    ranked++;
                }
            }
            cout << ranked+1 << endl;
        }
        Prices.clear();
    }
    return 0;
}
