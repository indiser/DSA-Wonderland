#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class TrieNode
{
    public:
        TrieNode *children[26];
        bool isEndOfWord;
        TrieNode()
        {
            isEndOfWord=false;
            for (int i = 0; i < 26; i++)
            {
                children[i]=nullptr;
            }
            
        }
};

class Trie
{
    public:
        TrieNode *root;
        Trie() {root=new TrieNode();};

        void insert(const string& word)
        {
            TrieNode *crawler=root;
            for(char c:word)
            {
                int index=c-'a';
                if(!crawler->children[index])
                {
                    crawler->children[index]=new TrieNode();
                }
                crawler=crawler->children[index];
            }
            crawler->isEndOfWord=true;
        }

        void findTopThree(TrieNode *node, const string& currentPrefix, vector<string> &suggestions)
        {
            if(suggestions.size() >= 3) return;
            
            if(node->isEndOfWord)
            {
                suggestions.push_back(currentPrefix);
            }
            
            for (int i = 0; i < 26 && suggestions.size() < 3; i++)
            {
                if(node->children[i])
                {
                    findTopThree(node->children[i], currentPrefix + char('a' + i), suggestions);
                }
            }
        }

        vector<vector<string>> generateSuggestions(vector<string> &wordList, string searchWord)
        {
            sort(wordList.begin(),wordList.end());
            for(const string& s : wordList)
            {
                insert(s);
            }

            vector<vector<string>> result;
            TrieNode *crawler = root;
            string currentPrefix = "";
            bool pathBroken = false;

            for(char c : searchWord)
            {
                currentPrefix += c;
                int index = c - 'a';
                
                if(pathBroken || !crawler || !crawler->children[index])
                {
                    pathBroken = true;
                    result.push_back({});
                }
                else
                {
                    crawler = crawler->children[index];
                    vector<string> suggestions;
                    findTopThree(crawler, currentPrefix, suggestions);
                    result.push_back(suggestions);
                }
            }
            return result;
        }
};

int main()
{
    vector<string> wordList={"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord="mouse";
    Trie trie;
    vector<vector<string>> result = trie.generateSuggestions(wordList, searchWord);
    
    for(int i = 0; i < result.size(); i++) {
        cout << "Prefix '" << searchWord.substr(0, i+1) << "': ";
        if(result[i].empty()) {
            cout << "No suggestions";
        } else {
            for(const string& word : result[i]) {
                cout << word << " ";
            }
        }
        cout << endl;
    }
    return 0;
}