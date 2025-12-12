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
        unordered_map<string,bool> memo;
        void insert(string word)
        {
            TrieNode *crawler=root;
            for(char c:word)
            {
                int index=c-'a';
                if(!crawler->children[index])
                {
                    crawler->children[index]= new TrieNode();
                }
                crawler=crawler->children[index];
            }
            crawler->isEndOfWord=true;
        }

        bool canBeFormed(string word)
        {
            if(word.empty())
            {
                return true;
            }
            if(memo.count(word))
            {
                return true;
            }
            TrieNode *crawler=root;
            
            for (int i = 0; i < word.size(); i++)
            {
                int index=word[i]-'a';
                if(crawler->children[index]==nullptr)
                {
                    memo[word]=false;
                    return false;
                }
                crawler=crawler->children[index];
                if(crawler->isEndOfWord)
                {
                    string suffix=word.substr(i+1);
                    if(canBeFormed(suffix))
                    {
                        memo[word]=true;
                        return true;
                    }
                }
            }
            memo[word]=false;
            return false;
        }

        vector<string> findAllConcatinations(vector<string> &list)
        {
            for(string s:list)
            {
                insert(s);
            }

            vector<string> ans;
            for(string word:list)
            {
                TrieNode *crawler=root;
                for(char c:word)
                {
                    crawler=crawler->children[c-'a'];
                }
                crawler->isEndOfWord=false;
                if(canBeFormed(word))
                {
                    ans.push_back(word);
                }
                crawler->isEndOfWord=true;
            }
            return ans;
        }
};

int main()
{
    vector<string> list={"cats","cat","dog","catsdog"};
    Trie trie;
    vector<string> ans=trie.findAllConcatinations(list);
    for(auto val:ans)
    {
        cout<<val<<endl;
    }

}