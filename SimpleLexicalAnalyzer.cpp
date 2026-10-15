#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iomanip>
#include <cctype>

using namespace std;

struct Token
{
    string token;
    string type;
};

int main()
{
    set<string> keywords = {
        "int","float","char","double","if","else","for","while",
        "return","void","break","continue","switch","case",
        "default","do","long","short"
    };

    vector<Token> table;

    cout << "Enter program (Type END to finish):\n";

    string code, line;

    while(getline(cin,line))
    {
        if(line=="END")
            break;

        code += line;
        code += '\n';
    }

    bool singleComment=false;
    bool multiComment=false;

    for(int i=0;i<code.size();i++)
    {
        // Single line comment
        if(!multiComment && i+1<code.size() &&
           code[i]=='/' && code[i+1]=='/')
        {
            while(i<code.size() && code[i]!='\n')
                i++;
            continue;
        }

        // Multi-line comment start
        if(!multiComment && i+1<code.size() &&
           code[i]=='/' && code[i+1]=='*')
        {
            multiComment=true;
            i++;
            continue;
        }

        // Multi-line comment end
        if(multiComment)
        {
            if(i+1<code.size() &&
               code[i]=='*' && code[i+1]=='/')
            {
                multiComment=false;
                i++;
            }
            continue;
        }

        // Ignore whitespace
        if(isspace(code[i]))
            continue;

        // Identifier / Keyword
        if(isalpha(code[i]) || code[i]=='_')
        {
            string word;

            while(i<code.size() &&
                 (isalnum(code[i]) || code[i]=='_'))
            {
                word+=code[i];
                i++;
            }

            i--;

            if(keywords.count(word))
                table.push_back({word,"Keyword"});
            else
                table.push_back({word,"Identifier"});
        }

        // Number
        else if(isdigit(code[i]))
        {
            string num;

            while(i<code.size() &&
                 (isdigit(code[i]) || code[i]=='.'))
            {
                num+=code[i];
                i++;
            }

            i--;

            table.push_back({num,"Constant"});
        }

        // Two-character operators
        else if(i+1<code.size())
        {
            string two=code.substr(i,2);

            if(two=="==" || two=="<=" || two==">=" ||
               two=="!=" || two=="++" || two=="--" ||
               two=="&&" || two=="||")
            {
                table.push_back({two,"Operator"});
                i++;
                continue;
            }

            // Single-character operators
            if(code[i]=='+' || code[i]=='-' ||
               code[i]=='*' || code[i]=='/' ||
               code[i]=='=' || code[i]=='<' ||
               code[i]=='>' || code[i]=='%')
            {
                string op;
                op+=code[i];
                table.push_back({op,"Operator"});
            }

            // Symbols
            else if(code[i]=='(' || code[i]==')' ||
                    code[i]=='{' || code[i]=='}' ||
                    code[i]=='[' || code[i]==']' ||
                    code[i]==';' || code[i]==',')
            {
                string sym;
                sym+=code[i];
                table.push_back({sym,"Symbol"});
            }
        }
    }

    cout<<"\n-------------------------------\n";
    cout<<left<<setw(20)<<"Token"<<"Type\n";
    cout<<"-------------------------------\n";

    for(auto t:table)
        cout<<left<<setw(20)<<t.token<<t.type<<endl;

    return 0;
}

/*

// This is a sample program

int main()
{
    int a = 10;
    float b = 20;

    /* This is
       a multi-line comment */

/*    if(a >= b)
    {
        a++;
    }

    return 0;
}
END

output
-------------------------------
Token               Type
-------------------------------
int                 Keyword
main                Identifier
(                   Symbol
)                   Symbol
{                   Symbol
int                 Keyword
a                   Identifier
=                   Operator
10                  Constant
;                   Symbol
float               Keyword
b                   Identifier
=                   Operator
20                  Constant
;                   Symbol
if                  Keyword
(                   Symbol
a                   Identifier
>=                  Operator
b                   Identifier
)                   Symbol
{                   Symbol
a                   Identifier
++                  Operator
;                   Symbol
}                   Symbol
return              Keyword
0                   Constant
;                   Symbol
}                   Symbol

*/
