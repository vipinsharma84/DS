#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temphead = NULL;
        ListNode* revtemp = NULL;
        ListNode* next = NULL;
        ListNode* temp = head;
        for (int i = 1; i < m; i++)
        {
            temphead = temp;
            temp = temp->next;
        }
        revtemp = temp;
        for (int i =1; i <= n-m; i++)
        {
            temp = temp->next;
        }
        next = temp->next;
        temp->next = NULL;
        temp = reverseList(revtemp);
        if(m>1)
        {
            temphead->next = temp;
        }
        else
        {
            temphead = temp;
            head = temp;
        }
        while(temphead->next != NULL)
        {
            temphead = temphead->next;
        }
        temphead->next = next;
        return head;
        
    }
    
    ListNode* reverseList(ListNode *head)
    {
        if(head == NULL) return NULL;
        if(head->next == NULL)
        return head;
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};

int main()
{
    Solution Test;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(5);
    ListNode* res = Test.reverseBetween(head,1,2);
    while(res)
    {
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}