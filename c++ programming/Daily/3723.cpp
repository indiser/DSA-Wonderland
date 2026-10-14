// Date: 14/05/2026
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;

// TLE
// class Solution
// {
//     public:
//         int sumOfDigits(int n)
//         {
//             int sum = 0;

//             while(n != 0)
//             {
//                 int last = n % 10;
//                 sum += last;
//                 n /= 10;
//             }
//             return sum;
//         }
//         int countDigit(int n)
//         {
//             if(n == 0) return 1;

//             int count = 0;

//             while (n != 0)
//             {
//                 n /= 10;
//                 ++count;
//             }
//             return count;
//         }
//         int sumSqaure(int n)
//         {
//             int sq = 0;
//             while(n != 0)
//             {
//                 int last = n % 10;
//                 sq += last * last;
//                 n /= 10;
//             }
//             return sq;
//         }
//         string maxSumOfSqaures(int num, int sum)
//         {
//             int n = 0;
//             int maxSum = INT_MIN;
//             int bestN = INT_MIN;

//             while(countDigit(n) <= num)
//             {
//                 if(countDigit(n) == num && sumOfDigits(n) == sum)
//                 {
//                     int sq = sumSqaure(n);
//                     if(sq >= maxSum)
//                     {
//                         maxSum = sq;
//                         bestN = n;
//                     }
//                 }
//                 n++;
//             }

//             return (bestN != INT_MIN) ? to_string(bestN) : "";
//         }
// };

// Time Complexity: O(num)
// Space Compelxity: O(1)
class Solution
{
    public:
        string maxSumOfSqaures(int num, int sum)
        {
            if (sum > 9 * num) {
                return "";
            }
            int r = sum % 9;
            string ans(sum / 9, '9');
            if (r > 0) {
                ans.push_back('0' + r);
            }
            ans.append(num - (int)ans.size(), '0');
            return ans;
        }
};

int main()
{
    int num = 2;
    int sum = 3;

    Solution s;
    cout << s.maxSumOfSqaures(num, sum)<< endl;

    return 0;
}