#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        if(n % 3 == 0){
            cout << "Cici\n";
        }else{
            cout << "Kiki\n";
        }
    }
    return 0;
}
