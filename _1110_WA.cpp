#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const double PI=3.1415926;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        double x,y;
        cin>>x>>y;
        cout<<"Property "<<i<<": This property will begin eroding in year "<<ceil(PI*(x*x+y*y)/100.0)<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
    return 0;
}