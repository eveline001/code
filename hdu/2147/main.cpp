#include <iostream>

using namespace std;

int main()
{
    int n, m;
    while(cin >> n >> m)
    {
        if(n == 0 && m == 0){
            break;
        }
        if(n % 2 ==1 && m % 2 == 1){
            cout << "What a pity!\n";
        }else{
            cout << "Wonderful!\n";
        }
    }
    return 0;
}
