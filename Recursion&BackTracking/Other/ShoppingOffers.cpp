#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution
{
    public:
        int shoppingOffers(vector<int> &prices, vector<vector<int>> &specialOffers, vector<int> &needs)
        {
            map<vector<int>,int> memo;
            return solve(prices, specialOffers, needs, memo);
        }
    private:
        int solve(const vector<int> &prices,const vector<vector<int>> &specialOffers, vector<int> &needs, map<vector<int>,int> &memo)
        {
            if(memo.count(needs)) return memo[needs];

            int minCost=0;
            for (int i = 0; i < needs.size(); i++)
            {
                minCost+=needs[i]*prices[i];
            }

            for(const auto& offers:specialOffers)
            {
                vector<int> nextNeeds=needs;
                bool offerIsUsable=true;

                for (int i = 0; i < needs.size(); i++)
                {
                    if(nextNeeds[i]<offers[i])
                    {
                        offerIsUsable=false;
                        break;
                    }
                    nextNeeds[i]-=offers[i];
                }
                
                if(offerIsUsable)
                {
                    int offerPrice=offers.back();
                    int totalCostWithOffer=offerPrice+solve(prices,specialOffers,nextNeeds,memo);

                    minCost=min(minCost,totalCostWithOffer);
                }
            }
            memo[needs]=minCost;
            return minCost;
        }

};

int main()
{
    vector<int> prices = {2, 3}; // apple=$2, banana=$3
    vector<vector<int>> specialOffers = {
        {1, 1, 4} // Buy 1 apple, 1 banana for $4
    };
    vector<int> needs = {2, 3}; // Need 2 apples, 3 bananas
    Solution s;
    cout<<s.shoppingOffers(prices,specialOffers,needs)<<endl;
}