#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution
{
    public:
        bool containsZero(string str)
        {
            for(char c: str)
            {
                if(c == '0') return true;
            }
            return false;
        }
        long long digitsProduct(long long n)
        {
            if(n == 0) return 1;
            return (n % 10) * digitsProduct(n / 10);
        }
        string smallestNumber(string n, long long t)
        {
            int num = stoi(n);
            string smallest = "";

            while(true)
            {
                if(containsZero(to_string(num))) 
                {
                    num++;
                    continue;
                }

                if(digitsProduct(num) % t == 0)
                {
                    smallest = to_string(num);
                    break;
                }
                num++;
            }

            return (smallest.empty()) ? "-1" : smallest;
        }
};

int main()
{
    string n = "11111";
    long long t = 26;

    Solution s;
    cout << s.smallestNumber(n, t) <<endl;

    return 0;
}