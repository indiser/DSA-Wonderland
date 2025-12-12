#include<iostream>
#include<math.h>
#include<string>
using namespace std;

// WAF to reverse a word
string reverseInt(string s)
{
    string ans="";
    while (n!=1)
    {
       n=n%10;
       ans.push_back(n);
    }
    return ans;
    
}

int main()
{
    // With a loop 
    // int n;
    // bool b=false;
    // cout<<"The number is: "<<endl;
    // cin>>n;
    // for (int i = 0; i < n/2; i++)
    // {
    //     if(pow(2,i)==n)
    //     {
    //         b=true;
    //     }
        
    // }
    // if(b==true)
    //     cout<<"This is a power of 2"<<endl;
    // else
    //     cout<<"This is not a power of 2"<<endl;

    // With bitwise >> and << operator

    // int n;
    // cout<<"The number is: "<<endl;
    // cin>>n;
    
    cout<<reverseInt(125)<<endl;
}