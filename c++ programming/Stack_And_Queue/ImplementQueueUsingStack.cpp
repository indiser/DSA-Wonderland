#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class MyQueue
{
    public:
        stack<int> s1,s2;
        MyQueue()
        {

        }

        void push(int x)
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
            s1.push(x);
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
        }

        int pop()
        {
            int ans=s1.top();
            s1.pop();
            return ans;
        }

        int peek()
        {
            return s1.top();
        }

        bool empty()
        {
            return s1.empty();
        }

};

int main()
{
    MyQueue queue;
    queue.push(1);
    queue.push(2);
    cout << queue.pop() << endl;
    cout << queue.peek() << endl;
    return 0;
}
