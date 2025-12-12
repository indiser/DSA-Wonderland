#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int buyAndSell(vector<int> &prices)
    {
        int len = prices.size();
        // int start = 0, end = len-1;
        int maxProfit = 0,bestBuy=prices[0];

        // while (start < end)
        // {
        //     int profit = prices[end] - prices[start];
        //     maxProfit = max(maxProfit, profit);
        //     start++;
        //     end--;
        // }

        for (int i = 1; i < len; i++)
        {
            if(bestBuy>prices[i])
                bestBuy=prices[i];

            maxProfit=max(maxProfit,prices[i]-bestBuy);
        }
        
        return maxProfit;
    }
};

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices={7,6,4,3,1};
    Solution s;
    cout<<s.buyAndSell(prices)<<endl;
    return 0;
}