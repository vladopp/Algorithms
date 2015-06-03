#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string input;
int len;

bool is_palindrome(string s)
{
    int start=0;
    int endd = len-1;

    while(start<endd)
    {
        if(s[start]!=s[endd])
            return false;
    start++;
    endd--;
    }

    return true;
}

int main()
{
    cout.sync_with_stdio(0);
    cout.tie(0);

    cin >> input;
    len=input.length();

    int cnt=0;
    for(int i=0; i<len; i++)
    {
        string rot = input.substr(i,len)+input.substr(0,i);
        if(is_palindrome(rot))
        {
            cout << rot << endl;
            cnt ++;
        }
    }

    if(!cnt)
        cout << "NONE" << endl;

    return 0;
}
