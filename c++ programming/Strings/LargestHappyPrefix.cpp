#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Time Complexity:O(n^2)
//Space Complexity:O(1)
// class Solution
// {
//     public:
//         string happyPrefix(string &str)
//         {
//             int res=0;
//             int len=str.length();

//             for (int i = 0; i < len; i++)
//             {
//                 int j=len-i;
//                 bool flag=true;
//                 for (int k = 0; k < i; k++)
//                 {
//                     if(str[k] != str[k+j])
//                     {
//                         flag=false;
//                         break;
//                     }
//                 }
//                 if(flag==true)
//                     res=i;
//             }
//             return str.substr(0,res);
//         }
// };


//Time Complexity:O(n)
//Space Complexity:O(n)
class Solution
{
public:
    string happyPrefix(string &str)
    {
        int n = str.length();
        vector<int> lps(n);

        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;

        // lps[0] is always 0
        lps[0] = 0;

        int i = 1;
        while (i < str.length())
        {

            // If characters match, increment the size of lps
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }

            // If there is a mismatch
            else
            {
                if (len != 0)
                {

                    // Update len to the previous lps value
                    // to avoid reduntant comparisons
                    len = lps[len - 1];
                }
                else
                {

                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }

        // Last element of lps array will store the length of
        // longest prefix that is also suffix of entire string
        return str.substr(0,lps[n - 1]);
    }
};

int main()
{
    string str = "level";
    Solution s;
    cout << s.happyPrefix(str) << endl;
    return 0;
}