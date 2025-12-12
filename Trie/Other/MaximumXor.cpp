#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[2];
    TrieNode()
    {
        children[0]=nullptr;
        children[1]=nullptr;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); };

    void insert(int num)
    {
        TrieNode *crawler = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (crawler->children[bit] == nullptr)
            {
                crawler->children[bit] = new TrieNode();
            }
            crawler = crawler->children[bit];
        }
    }
    int findMaximumXor(vector<int> &num)
    {
        if(num.empty()) return 0;

        int max_xor_found = 0;
        for(int val:num)
        {
            insert(val);
        }

        for (int val : num)
        {
            int current_max_xor = 0;
            TrieNode *crawler = root;
            for (int i = 31; i >= 0; i--)
            {
                int bit = (val >> i) & 1;
                int opposite_bit = 1 - bit;
                current_max_xor <<= 1;

                if(crawler->children[opposite_bit]!=nullptr)
                {
                    current_max_xor |= 1;
                    crawler=crawler->children[opposite_bit];
                }
                else
                {
                    crawler=crawler->children[bit];
                }
            }
            max_xor_found=max(max_xor_found,current_max_xor);
        }
        return max_xor_found;
    }
};

int main()
{
    vector<int> num = {3, 10, 5, 25, 2, 8};
    TrieNode *root = new TrieNode();
    Trie trie;
    cout<<trie.findMaximumXor(num)<<endl;
}