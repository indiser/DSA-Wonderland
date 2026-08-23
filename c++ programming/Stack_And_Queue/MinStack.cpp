#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<climits>
using namespace std;


/*
 * Time Complexity: O(1) for all operations (push, pop, top, getMin)
 * Space Complexity: O(n) where n is the number of elements in the stack
 */
class MinStack
{
    public:
        stack<int> st,min_st;
        MinStack()
        {

        }
        void push(int val)
        {
            st.push(val);
            if(min_st.empty() || val <= min_st.top())
                min_st.push(val);
            else
                min_st.push(min_st.top());
        }
        void pop()
        {
            st.pop();
            min_st.pop();
        }
        int top()
        {
            return st.top();
        }
        int getMin()
        {
            return min_st.top();
        }
};


int main()
{
    cout<<"Test Case 1: Basic operations"<<endl;
    MinStack *mst = new MinStack();
    mst->push(-2);
    mst->push(0);
    mst->push(-3);
    cout<<"Top: "<<mst->top()<<" (Expected: -3)"<<endl;
    cout<<"Min: "<<mst->getMin()<<" (Expected: -3)"<<endl;
    mst->pop();
    cout<<"Min after pop: "<<mst->getMin()<<" (Expected: -2)"<<endl;
    cout<<"Top: "<<mst->top()<<" (Expected: 0)"<<endl;
    
    cout<<"\nTest Case 2: Duplicate minimums"<<endl;
    MinStack *mst2 = new MinStack();
    mst2->push(5);
    mst2->push(1);
    mst2->push(1);
    mst2->push(3);
    cout<<"Min: "<<mst2->getMin()<<" (Expected: 1)"<<endl;
    mst2->pop();
    cout<<"Min after pop: "<<mst2->getMin()<<" (Expected: 1)"<<endl;
    mst2->pop();
    cout<<"Min after 2nd pop: "<<mst2->getMin()<<" (Expected: 1)"<<endl;
    mst2->pop();
    cout<<"Min after 3rd pop: "<<mst2->getMin()<<" (Expected: 5)"<<endl;
    
    cout<<"\nTest Case 3: Single element"<<endl;
    MinStack *mst3 = new MinStack();
    mst3->push(42);
    cout<<"Top: "<<mst3->top()<<" (Expected: 42)"<<endl;
    cout<<"Min: "<<mst3->getMin()<<" (Expected: 42)"<<endl;
    
    cout<<"\nTest Case 4: Negative numbers"<<endl;
    MinStack *mst4 = new MinStack();
    mst4->push(-5);
    mst4->push(-10);
    mst4->push(-3);
    cout<<"Min: "<<mst4->getMin()<<" (Expected: -10)"<<endl;
    mst4->pop();
    cout<<"Min after pop: "<<mst4->getMin()<<" (Expected: -10)"<<endl;
    
    return 0;
}