#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
    unordered_map<string,int> m={{"Geeks",1},{"for",2},{"C++",3}};
    for(auto i:m)
    {
        cout<<i.first<<":"<<i.second<<endl;
    }
    //inserting elements
    map<int,string> m1;
    m1[1]="Geeks";
    m1.insert({2,"for"});
    m1.insert({3,"C++"});
    for(auto i:m1)
    {
        cout<<i.first<<":"<<i.second<<endl;
    }

    // Accessing Elements
    cout<<m["Geeks"]<<endl;
    cout<<m1.at(2)<<endl;

    //Updation
    m["Geeks"]=4;
    m1.at(2)="forGeeks";
    cout<<m["Geeks"]<<endl;
    cout<<m1.at(2)<<endl;

    //Finding
    auto it=m1.find(3);
    if(it!=m1.end())
    {
        cout<<it->first<<":"<<it->second<<endl;
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    // Traversing
    for(auto i=m1.begin();i!=m1.end();i++)
    {
        cout<<i->first<<":"<<i->second<<endl;
    }

    //Deleting
    m1.erase(2);
    m.erase(m.begin());
    for(auto i:m1)
    {
        cout<<i.first<<":"<<i.second<<endl;
    }
    return 0;
}