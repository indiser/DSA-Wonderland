#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<int> nums={-10,-3,-5,-6,-20};

    int firstMax=INT_MIN;
    int secondMax=INT_MIN;
    int thirdMax=INT_MIN;

    for(int val:nums)
    {
        if(val > firstMax)
        {
            thirdMax=secondMax;
            secondMax=firstMax;
            firstMax=val;
        }
        else if(val > secondMax)
        {
            thirdMax=secondMax;
            secondMax=val;
        }
        else if(val > thirdMax)
        {
            thirdMax=val;
        }
    }

    cout<<"The product of three greatest candidate is:"<<(firstMax*secondMax*thirdMax)<<endl;
    return 0;
}