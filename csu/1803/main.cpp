#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, m;
    long long num, nm, mm;
    int x, y;

    while(scanf("%d%d", &n, &m) != EOF){
        nm = n / 2016;
        mm = m / 2016;
        num = (nm * mm) * 30576;
        x = n % 2016;
        for(int a = 1; a <= x; a++)
            for(int b = 1; b <= 2016; b++)
                if(a * b % 2016 == 0) num += mm;
        y = m % 2016;
        for(int a = 1; a <= 2016; a++)
            for(int b = 1; b <= y; b++)
                if(a * b % 2016 == 0) num += nm;
        for(int a = 1; a <= x; a++)
            for(int b = 1; b <= y; b++)
                if(a * b % 2016 == 0) num++;
        cout << num << endl;
    }
    return 0;
}
