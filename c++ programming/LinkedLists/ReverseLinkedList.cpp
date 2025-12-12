#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Time Complexity:O(n)
// Space Complexity:O(1)

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
    public:
        ListNode* reverseLinkedList(ListNode* head)
        {
            ListNode *prev=NULL;
            ListNode *curr=head;
            ListNode *next=NULL;

            while(curr != NULL)
            {
                next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            return prev;
        }
        void Traverse(ListNode *head)
        {
            while(head != NULL)
            {
                cout << head->val << " ";
                head = head->next;
            }
        }

};

int main()
{
    ListNode* head = new ListNode(1);
    ListNode* current = head;
    
    for(int i = 2; i <= 5; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    Solution s;
    s.Traverse(head);
    cout<<endl;
    head = s.reverseLinkedList(head);
    s.Traverse(head);
    return 0;
}
