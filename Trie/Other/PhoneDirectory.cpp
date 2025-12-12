#include<iostream>
#include<vector>
#include<unordered_map>
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

        void insert(string word)
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
        void collectContacts(TrieNode *node, string currentPrefix, vector<string> &result)
        {
            if(node->isEndOfWord)
            {
                result.push_back(currentPrefix);
            }
            for (int i = 0; i < 26; i++)
            {
                if(node->children[i])
                {
                    collectContacts(node->children[i], currentPrefix + char('a' + i), result);
                }
            }
        }
        vector<string> suggestPrefix(string prefix)
        {
            TrieNode *crawler = root;
            vector<string> ans;
            
            for(char c : prefix)
            {
                int index = c - 'a';
                if(!crawler->children[index])
                {
                    return ans; // No words with this prefix
                }
                crawler = crawler->children[index];
            }
            
            collectContacts(crawler, prefix, ans);
            return ans;
        }
};

int main()
{
    vector<string> list={"david", "daniel", "emma", "emily"};
    string prefix="da";
    
    Trie trie;
    for(string contact : list) {
        trie.insert(contact);
    }
    
    vector<string> suggestions = trie.suggestPrefix(prefix);
    cout << "Contacts with prefix '" << prefix << "': ";
    for(string contact : suggestions) {
        cout << contact << " ";
    }
    cout << endl;
    
    return 0;
}