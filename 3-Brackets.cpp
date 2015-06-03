#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

string input;
long sum;
int len;
int braces[3];
int bracesopen[3];

bool validate(char ch)
{
    if(ch=='{')
    {
        if(braces[0] || braces[1] || braces[2])
            return true;
        braces[2]++;
		bracesopen[2]++;
    }

    else if(ch=='[')
    {
		if(bracesopen[0] || bracesopen[1])
			return true;
		bracesopen[1]++;
		braces[1]++;
    }

    else if(ch=='(')
    {
		if(bracesopen[0] || (bracesopen[2] && !bracesopen[1]))
			return true;
		bracesopen[0]++;
		braces[0]++;
    }

    else if(ch=='}')
	{
		if(bracesopen[0] || bracesopen[1] || bracesopen[2]==0)
			return true;
		bracesopen[2]--;
    }

    else if(ch==']')
    {
		if(bracesopen[0] || bracesopen[1]==0)
			return true;
		bracesopen[1]--;
    }

    else if(ch==')')
    {
		if(bracesopen[0]==0)
			return true;
		bracesopen[0]--;
    }

	return false;
}

int Calculate(const string& str)
{
	if(str=="")
		return 0;

	int multipl;
	if(bracesopen[2] && bracesopen[1] && bracesopen[0])
		multipl=4;
	else if((bracesopen[1] && bracesopen[0]) || (bracesopen[2] && bracesopen[1]))
		multipl=2;
	else
		multipl=1;

	int numb=atoi(str.c_str());

	return (numb*multipl);
}


int main()
{
    cin >> input;
    len = input.length();

    if(isdigit(input[0]) or isdigit(input[len-1]))
    {
        cout << "NO" << endl;
        return 0;
    }

    char outermost_brace = input[0];
    for(int i=1; i<len; i++)
    {
        if(input[i]==outermost_brace)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    char endbrace;
    if(outermost_brace!='(')
        endbrace = outermost_brace + 2;
    else
        endbrace = outermost_brace++;

    if(input[len-1] != endbrace)
    {
        cout << "NO" << endl;
        return 0;
    }

    int Result=0;
	string CurNumb="";
	for(int i=0;i<len;i++)
	{
		if(!isdigit(input[i]))
		{
			Result+=Calculate(CurNumb);
			CurNumb="";

			if(validate(input[i]))
			{
				cout << "NO" << endl;
				return 0;
			}
        }
        else
		{
			CurNumb+=input[i];
		}
	}

	cout << Result << endl;


    return 0;
}
