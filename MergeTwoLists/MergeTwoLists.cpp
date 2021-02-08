// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    // code here
    Node* temp = new Node(-1);
    Node *head = temp;
    Node *tempA = head_A;
    Node *tempB = head_B;
    while(tempA && tempB)
    {
        if(tempA->data < tempB->data)
        {
            temp->next = tempA;
            tempA = tempA->next;
        }
        else {
            temp->next = tempB;
            tempB = tempB->next;
        }
        
        
        temp = temp->next;
    }
    if(tempA == NULL)
    {
        while(tempB)
        {
            temp->next = tempB;
            tempB = tempB->next;
            temp = temp->next;
        }
    }
    if(tempB == NULL)
    {
        while(tempA)
        {
            temp->next = tempA;
            tempA = tempA->next;
            temp = temp->next;
        }
    }
    return head->next;
}  