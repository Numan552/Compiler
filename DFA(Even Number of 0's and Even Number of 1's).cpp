#include <iostream>
using namespace std;

int main()
{
    string s;

    cout<<"Enter binary string: ";
    cin>>s;

    int zero=0,one=0;

    for(char c:s)
    {
        if(c=='0')
            zero++;

        else if(c=='1')
            one++;

        else
        {
            cout<<"Invalid Input";
            return 0;
        }
    }

    if(zero%2==0 && one%2==0)
        cout<<"Accepted";

    else
        cout<<"Rejected";

    return 0;
}


/*
Enter binary string: 0011
Accepted

Enter binary string: 100
Rejected

*/
