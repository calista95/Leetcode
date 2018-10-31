#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isPair(char a, char b)
{
        switch(a)
                {
                        case '(' :
                                if (b == ')')
                                        return true;
                                break;
                        case '{' :
                                if (b == '}')
                                        return true;
                                break;
                        case '[' :
                                if (b == ']')
                                        return true;
                }
        return false;
}


bool isValid(string s)
{
        stack<char>myStack;
        for (int i=0; i<s.size(); i++)
        {
                if (myStack.empty() == true)
                        myStack.push(s[i]);
                else
                {
                        if ( isPair(myStack.top(), s[i]) == true)
                                myStack.pop();
                        else
                                myStack.push(s[i]);
                }
        }

        if (myStack.empty() == true)
                return true;
        else
                return false;
}


int main()
{
        //testing
        string s = "{}[]()"; //true
        cout << isValid(s) << endl;
        string b = "(]"; //false
        cout << isValid(b) << endl;
        string c = "{()}"; //true
        cout << isValid(c) << endl;
        string d = "([)]"; //false
        cout << isValid(d) << endl;

        return 0;
}
