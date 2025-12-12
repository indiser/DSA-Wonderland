#include<iostream>
#include<vector>
using namespace std;

//Expected outcome:(One Pass)
//Time Complexity:O(n)
//Space Complexity:O(1)

int onePass(vector<int> &arr)
{
    int firstMax=-1,secondMax=-1,thirdMax=-1;

    for(int val:arr)
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
    return thirdMax;
}

int main()
{
    vector<int> nums={1,14,2,16,10,20};
    cout<<"Third max:"<<onePass(nums)<<endl;
    return 0;
}