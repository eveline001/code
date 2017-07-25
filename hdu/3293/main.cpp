#include <iostream>
#include <algorithm>

using namespace std;

struct WEAPONS
{
    string Origin;
    string Level;
    string Name;
};

WEAPONS Weapons[501];

bool comp(WEAPONS A, WEAPONS B)
{
    if(A.Origin != B.Origin){
        return A.Origin < B.Origin;
    }else{
        if(A.Level != B.Level){
            if(A.Level == "wonderful")
            {
                return true;
            }
            if(A.Level == "good")
            {
                return B.Level != "wonderful";
            }
            return false;
        }else{
            return A.Name < B.Name;
        }
    }
}

int main()
{
    int n, i, T = 0;
    while(cin >> n)
    {
        T++;

        if(n == 0)
        {
            cout << "Case " << T << '\n';
            continue;
        }

        for(i = 0; i < n; i++)
        {
            cin >> Weapons[i].Name >> Weapons[i].Origin >> Weapons[i].Level;
        }

        sort(&Weapons[0], &Weapons[0]+n, comp);

        string Origin = Weapons[0].Origin;

        cout << "Case " << T << '\n';
        cout << Origin << ":\n";
        for(i = 0; i < n; i++)
        {
            if(Origin != Weapons[i].Origin)
            {
                Origin = Weapons[i].Origin;
                cout << Origin << ":\n";
            }
            cout << "          " << Weapons[i].Name << " "  << Weapons[i].Level << endl;
        }
    }
}
