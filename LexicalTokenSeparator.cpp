#include <iostream>
#include <string>
#include <set>
#include <cctype>

using namespace std;

int main()
{
    set<string> keywords = {
        "if", "else", "for", "while", "int", "float",
        "char", "double", "return", "void", "break",
        "continue", "switch", "case", "default", "do"
    };

    string s;

    cout << "Enter expression: ";
    getline(cin, s);

    string word = "";
    string number = "";

    cout << "\nKeyword : ";
    bool found = false;

    // Print Keywords
    for (int i = 0; i <= s.length(); i++)
    {
        if (i < s.length() && (isalpha(s[i]) || s[i] == '_'))
        {
            word += s[i];
        }
        else
        {
            if (!word.empty())
            {
                if (keywords.count(word))
                {
                    cout << word << " ";
                    found = true;
                }
                word = "";
            }
        }
    }

    if (!found)
        cout << "None";

    cout << "\nIdentifier : ";
    word = "";
    found = false;

    // Print Identifiers
    for (int i = 0; i <= s.length(); i++)
    {
        if (i < s.length() && (isalpha(s[i]) || s[i] == '_'))
        {
            word += s[i];
        }
        else
        {
            if (!word.empty())
            {
                if (!keywords.count(word))
                {
                    cout << word << " ";
                    found = true;
                }
                word = "";
            }
        }
    }

    if (!found)
        cout << "None";

    cout << "\nConstant : ";
    found = false;
    number = "";

    // Print Constants
    for (int i = 0; i <= s.length(); i++)
    {
        if (i < s.length() && isdigit(s[i]))
        {
            number += s[i];
        }
        else
        {
            if (!number.empty())
            {
                cout << number << " ";
                found = true;
                number = "";
            }
        }
    }

    if (!found)
        cout << "None";

    cout << "\nOperator : ";
    found = false;

    // Print Operators
    for (int i = 0; i < s.length(); i++)
    {
        if (i + 1 < s.length())
        {
            string two = s.substr(i, 2);

            if (two == "==" || two == "<=" || two == ">=" || two == "!=")
            {
                cout << two << " ";
                found = true;
                i++;
                continue;
            }
        }

        if (s[i] == '+' || s[i] == '-' || s[i] == '*' ||
            s[i] == '/' || s[i] == '=' || s[i] == '<' ||
            s[i] == '>')
        {
            cout << s[i] << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << "\nSymbol : ";
    found = false;

    // Print Symbols
    for (char c : s)
    {
        if (c == '(' || c == ')' || c == '{' || c == '}' ||
            c == '[' || c == ']' || c == ';' || c == ',')
        {
            cout << c << " ";
            found = true;
        }
    }

    if (!found)
        cout << "None";

    cout << endl;

    return 0;
}
