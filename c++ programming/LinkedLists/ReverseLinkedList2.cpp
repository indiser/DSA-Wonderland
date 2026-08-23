

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Time Complexity: O(n) - where n is the number of nodes in the linked list
Space Complexity: O(1) - constant extra space using only a few pointers
*/

class Solution
{
    public:
        void Traverse(ListNode *head)
        {
            if (!head) return;

            while(head != NULL)
            {
                cout<<head->val<<" ";
                head=head->next;
            }
        }
        ListNode *reverseList(ListNode *head, int left, int right)
        {
            if(!head || left == right) return head;

            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *prev = dummy;

            // Move to position before left
            for(int i = 1; i < left; i++) {
                prev = prev->next;
            }

            ListNode *curr = prev->next;
            ListNode *next = curr->next;

            // Reverse nodes between left and right
            for(int i = 0; i < right - left; i++) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            return dummy->next;
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
    ListNode *result=s.reverseList(head,2,4);
    s.Traverse(result);
    return 0;
}