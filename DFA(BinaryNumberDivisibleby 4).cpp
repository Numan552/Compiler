#include <iostream>
using namespace std;

int main()
{
    string s;

    cout<<"Enter binary number: ";
    cin>>s;

    int value=0;

    for(char c:s)
    {
        if(c!='0' && c!='1')
        {
            cout<<"Invalid";
            return 0;
        }

        value=value*2+(c-'0');
    }

    if(value%4==0)
        cout<<"Accepted";

    else
        cout<<"Rejected";

    return 0;
}
