#include<iostream>
#include<vector>
#include<unordered_map>
#include<random>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, bool> map;
        RandomizedSet() 
        {
        
        }
    
        bool insert(int val) 
        {
            if(map.find(val) != map.end()) return false;
            map[val]=true;
            return true;
        }
    
        bool remove(int val) 
        {
            return map.erase(val) > 0;
        }
    
        int getRandom() 
        {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dist(0, map.size()-1);
            auto it=map.begin();
            advance(it, dist(gen));
            return it->first;
        }
};

int main()
{
    RandomizedSet *rs = new RandomizedSet();
    for (int i = 0; i < 8; i++)
    {
        rs->insert(i);
    }
    cout << rs->getRandom()<<endl;
    return 0;
}