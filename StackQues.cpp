#include<iostream>
#include<stack>
#include<string>
//#include<cstring>
using namespace std;

int main()
{
    //Reverse a String

    /*
    string a="abcdef";
    stack<char> stk;
    for(int i=0;i<a.length();i++)
    {
        stk.push(a[i]);
    }
    while(!stk.empty())
    {
        cout<<stk.top();
        stk.pop();
    }

    */

    //Reverse Letter of Words

    /*
    string n="hello world wow";
    stack<char> stk;
    //char *arr=new char[n.length()+1];
    //strcpy(arr,n.c_str());
    string::iterator it;
    for(it=n.begin();it!=n.end();it++)
    {

        if(*it==' ')
        {
            while(!stk.empty())
            {
                cout<<stk.top();
                stk.pop();
            }
            cout<<" ";
        }

        //if(it==n.end())
        //{
        //    while(!stk.empty())
        //    {
        //        cout<<stk.top();
        //        stk.pop();
        //    }
        //}
        else
        {
            stk.push(*it);
        }

    }

    while(!stk.empty())
    {
        cout<<stk.top();
        stk.pop();
    }

    */


    //Word Reverse
    string s="cat eats rats damn";
    stack<char> stk1;
    stack<char> stk2;

    string::iterator it;

    for(it=s.begin();it!=s.end();it++)
    {
        stk1.push(*it);
    }
    while(!stk1.empty())
    {
       stk2.push(stk1.top());
       stk1.pop();
       if(stk2.top()==' ')
       {
           stk2.pop();
           while(!stk2.empty())
           {
               cout<<stk2.top();
               stk2.pop();
           }
           cout<<" ";
       }
    }
    while(!stk2.empty())
    {
        cout<<stk2.top();
        stk2.pop();
    }
}
