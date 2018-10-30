#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;


int reverse(int x)
{
        string myString = to_string(x);
        int size = myString.size();
        string temp;

        bool isNegative = false;
        for (int i=size-1; i>=0; i--)
        {
                if (myString[i] == '-')
                        isNegative = true;
                else if (myString[i] == '0' && i==size-1)
                        int j=0; //do anything! this is really just a filter statement
                else
                        temp+=(myString[i]);
        }

        //convert string back to int
        stringstream geek(temp);
        int final = 0;
        geek >> final;

        if (isNegative == true)
                final = final*(-1);

        if (final >= 2147483647 || final <= -2147483647)
                return 0;
        else
                return final;
}

int main()
{
        cout << reverse(123) << endl;
        cout << reverse(-123) << endl;
        cout << reverse(120) << endl;

        return 0;
}

