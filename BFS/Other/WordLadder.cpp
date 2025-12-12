#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution
{
    public:
        int paths(vector<string> &ladder, string start, string end)
        {
            unordered_set<string> dict(ladder.begin(),ladder.end());

            if(dict.find(end)==dict.end())
            {
                return 0;
            }

            queue<string> q;
            q.push(start);
            int level=1;

            while(!q.empty())
            {
                int size=q.size();

                for (int i = 0; i < size; i++)
                {
                    string curr=q.front();
                    q.pop();

                    if(curr==end)
                    {
                        return level;
                    }

                    for (int j = 0; j < curr.length(); j++)
                    {
                        char originalCharecter=curr[j];

                        for(char c='A'; c <= 'Z'; c++)
                        {
                            curr[j]=c;
                            if(dict.find(curr) != dict.end())
                            {
                                q.push(curr);
                                dict.erase(curr);
                            }
                        }

                        curr[j]=originalCharecter;
                    }
                    
                }
                level++;
                
            }
            return 0;
        }
};

int main()
{
    vector<string> ladder= {"COT", "COG", "DOG", "CAT", "DOT"};
    string start="CAT";
    string end="DOG";

    Solution s;
    cout<<s.paths(ladder,start,end)<<endl;
}