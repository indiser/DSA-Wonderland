#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

class Solution
{
public:
    bool isAlien(vector<string> &words, string &order)
    {
        // Create character order mapping
        unordered_map<char, int> orderMap;
        for(int i = 0; i < order.size(); i++)
        {
            orderMap[order[i]] = i;
        }
        
        // Compare adjacent words
        for(int i = 0; i < words.size() - 1; i++)
        {
            if(!isValidOrder(words[i], words[i + 1], orderMap))
            {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool isValidOrder(string &word1, string &word2, unordered_map<char, int> &orderMap)
    {
        int i = 0, j = 0;
        
        while(i < word1.size() && j < word2.size())
        {
            if(orderMap[word1[i]] < orderMap[word2[j]])
            {
                return true; // word1 comes before word2
            }
            else if(orderMap[word1[i]] > orderMap[word2[j]])
            {
                return false; // word1 should come after word2
            }
            i++;
            j++;
        }
        
        // If all compared characters are equal, shorter word should come first
        return word1.size() <= word2.size();
    }
};

int main()
{
    cout << "=== Verify Alien Dictionary ===" << endl;
    
    Solution sol;
    
    // Test case 1: Valid alien dictionary order
    cout << "\nTest Case 1: Valid order" << endl;
    vector<string> words1 = {"hello", "leetcode"};
    string order1 = "hlabcdefgijkmnopqrstuvwxyz";
    
    cout << "Words: ";
    for(string word : words1)
        cout << "\"" << word << "\" ";
    cout << endl;
    cout << "Alien order: " << order1 << endl;
    
    bool result1 = sol.isAlien(words1, order1);
    cout << "Is valid alien dictionary order: " << (result1 ? "YES" : "NO") << endl;
    cout << "Explanation: 'h' comes before 'l' in alien order" << endl;
    
    // Test case 2: Invalid alien dictionary order
    cout << "\nTest Case 2: Invalid order" << endl;
    vector<string> words2 = {"word", "world", "row"};
    string order2 = "worldabcefghijkmnpqstuvxyz";
    
    cout << "Words: ";
    for(string word : words2)
        cout << "\"" << word << "\" ";
    cout << endl;
    cout << "Alien order: " << order2 << endl;
    
    bool result2 = sol.isAlien(words2, order2);
    cout << "Is valid alien dictionary order: " << (result2 ? "YES" : "NO") << endl;
    cout << "Explanation: 'd' comes after 'l' in alien order, so 'word' > 'world'" << endl;
    
    // Test case 3: Prefix case
    cout << "\nTest Case 3: Prefix case" << endl;
    vector<string> words3 = {"apple", "app"};
    string order3 = "abcdefghijklmnopqrstuvwxyz";
    
    cout << "Words: ";
    for(string word : words3)
        cout << "\"" << word << "\" ";
    cout << endl;
    cout << "Alien order: " << order3 << endl;
    
    bool result3 = sol.isAlien(words3, order3);
    cout << "Is valid alien dictionary order: " << (result3 ? "YES" : "NO") << endl;
    cout << "Explanation: Longer word 'apple' should come after shorter prefix 'app'" << endl;
    
    cout << "\nAlgorithm: Compare adjacent words character by character" << endl;
    cout << "using the given alien alphabet order" << endl;
    
    return 0;
}