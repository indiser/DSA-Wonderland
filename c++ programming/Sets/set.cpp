#include<iostream>
#include<set>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main()
{
    set<int> s={1,2,3,4};

    // Traverse-1
    // for (auto i = s.begin(); i != s.end(); i++)
    // {
    //     cout<<*i<<endl;
    // }

    // Traverse-2
    // for(auto val:s)
    // {
    //     cout<<val<<endl;
    // }

    // Accessing an Element
    auto i1=s.begin(); //Acessing the first elemnt
    auto i2=next(i1,2); //Accessing the third element
    // cout<<*i1<<" "<<*i2<<endl;
    
    //Inserting
    // s.insert(5);
    s.emplace(5);
    // for(auto val:s)
    // {
    //     cout<<val<<endl;
    // }

    //Deleting
    s.erase(2);
    for(auto val:s)
    {
        cout<<val<<endl;
    }
    return 0;
}