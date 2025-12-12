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

class Solution
{
    public:
        void Traversal(ListNode *head)
        {
            while (head != NULL)
            {
                cout<<head->val<<" ";
                head=head->next;
            }
            
        }

        // Time Complexity: O(n) - traverse list once + compare n/2 elements
        // Space Complexity: O(n) - vector stores all n elements
        bool palindrom(ListNode *head)
        {
            vector<int> list;
            while(head!=NULL)
            {
                list.push_back(head->val);
                head=head->next;
            }

            int start=0,end=list.size()-1;

            while(start < end)
            {
                if(list[start] != list[end])
                {
                    return false;
                }
                start++;
                end--;
            }
            return true;

        }
        
        
};

int main()
{
    ListNode *head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(2);
    head->next->next->next=new ListNode(1);

    Solution s;
    s.Traversal(head);
    cout<<endl;
    if(s.palindrom(head))
    {
        cout<<"Palindrom"<<endl;
    }
    else
    {
        cout<<"Not Palindrom"<<endl;
    }
    return 0;
}