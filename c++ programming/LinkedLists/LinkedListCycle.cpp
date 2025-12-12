#include<iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val=0;
        next=nullptr;
    }
    ListNode(int x)
    {
        val=x;
        next=nullptr;
    }
};

class Solution
{
    public:
        void Traverse(ListNode *head)
        {
            while(head != NULL)
            {
                cout<<head->val<<" ";
                head=head->next;
            }
        }

        // Time Complexity: O(n) - at most n iterations before pointers meet or reach end
        // Space Complexity: O(1) - only two pointer variables used
        bool hasCycle(ListNode *head)
        {
            if(!head || !head->next) return false;
            
            ListNode *slow=head;
            ListNode *fast=head;

            while(slow && fast && fast->next)
            {
                slow=slow->next;
                fast=fast->next->next;
                if(slow==fast) return true;
            }
            return false;
        }

};

int main()
{
    ListNode *head=new ListNode(3);
    head->next=new ListNode(2);
    head->next->next=new ListNode(0);
    head->next->next->next=new ListNode(-4);
    
    // Create cycle: last node points back to second node
    head->next->next->next->next = head->next;

    Solution s;
    // s.Traverse(head); // Commented out - would cause infinite loop
    cout << (s.hasCycle(head) ? "LL has a cycle" : "LL does not have a cycle") << endl;
}