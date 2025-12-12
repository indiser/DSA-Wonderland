#include<iostream>
#include<vector>
#include<string>
using namespace std;

//Horizental Scanning
//Time Complexity:O(n*m)
//Space Complexity:O(1)
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.size() == 0) return "";
//         string prefix = strs[0];
//         for (int i = 1; i < strs.size(); i++)
//             while (strs[i].find(prefix) != 0) {
//                 prefix = prefix.substr(0, prefix.length() - 1);
//                 if (prefix.empty()) return "";
//             }
//         return prefix;
//     }
// };

//Vertical Scanning
//Time Complexity:O(m*n)
//Space Complexity:O(1)
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.empty()) return "";
//         for (int i = 0; i < strs[0].size(); i++) {
//             char c = strs[0][i];
//             for (int j = 1; j < strs.size(); j++) {
//                 if (i == strs[j].size() || strs[j][i] != c)
//                     return strs[0].substr(0, i);
//             }
//         }
//         return strs[0];
//     }
// };


// Divide And Conqer
//Time Complexity:O(m*n)
//Space Complexity:O(mlogn)
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         if (strs.empty()) return "";
//         return longestCommonPrefix(strs, 0, strs.size() - 1);
//     }

// private:
//     string longestCommonPrefix(vector<string>& strs, int l, int r) {
//         if (l == r) {
//             return strs[l];
//         } else {
//             int mid = (l + r) / 2;
//             string lcpLeft = longestCommonPrefix(strs, l, mid);
//             string lcpRight = longestCommonPrefix(strs, mid + 1, r);
//             return commonPrefix(lcpLeft, lcpRight);
//         }
//     }

//     string commonPrefix(string left, string right) {
//         int min = std::min(left.length(), right.length());
//         for (int i = 0; i < min; i++) {
//             if (left[i] != right[i]) return left.substr(0, i);
//         }
//         return left.substr(0, min);
//     }
// };

// Binary Search
//Time Complexity:O(S.logm)(S=m*n)
//Space Complexity:O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int minLen = INT_MAX;
        for (string str : strs) minLen = min(minLen, (int)str.length());
        int low = 1;
        int high = minLen;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (isCommonPrefix(strs, middle))
                low = middle + 1;
            else
                high = middle - 1;
        }
        return strs[0].substr(0, (low + high) / 2);
    }

private:
    bool isCommonPrefix(vector<string>& strs, int len) {
        string str1 = strs[0].substr(0, len);
        for (int i = 1; i < strs.size(); i++)
            if (strs[i].find(str1) != 0) return false;
        return true;
    }
};

int main()
{
    vector<string> strs={"flower","flow","flight"};
    Solution s;
    cout<<s.longestCommonPrefix(strs)<<endl;
    return 0;
}