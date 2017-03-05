#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, map<string, int> > Fruit;

map<string, int> temp;

int main()
{
    int T, n, i;
    string FruitName, Origin;
    int Num;

    ios_base::sync_with_stdio(false);

    cin >> T;
    while(T--)
    {
        cin >> n;
        for(i = 0; i < n; i++)
        {
            cin >> FruitName >> Origin >> Num;
            auto OriPtr = Fruit.find(Origin);
            if(OriPtr != Fruit.end()){
                auto NamPtr = OriPtr->second.find(FruitName);
                if(NamPtr != OriPtr->second.end()){
                    NamPtr->second += Num;
                    continue;
                }
            }
            Fruit[Origin][FruitName] = Num;
        }

        for(auto Oit = Fruit.begin(); Oit != Fruit.end(); ++Oit)
        {
            cout << Oit->first << endl;
            for(auto Nit = Oit->second.begin(); Nit != Oit->second.end(); ++Nit)
            {
                cout << "   |----" << Nit->first << '(' << Nit->second << ')' <<endl;
            }
        }
        Fruit.clear();
        if(T != 0)
        {
            cout << endl;
        }
    }
    return 0;
}
