#include<iostream>
using namespace std;

int main()
{
    string s="abcde";
    string::iterator it;
    it=s.begin();
    cout<<*it;
    it++;
    cout<<*it;
    it=s.end();
    cout<<*(it-1);

    //char *n= (s.end());
    //cout<<n;
}
