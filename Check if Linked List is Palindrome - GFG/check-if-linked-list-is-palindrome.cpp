//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
{
    Node *first=head;
    Node *second=head;
    Node *mid=NULL;
    while(second!=NULL && second->next!=NULL)
    {
        first=first->next;
        second=second->next->next;
    }
    
    if(second!=NULL)
    {
        first=first->next;
        mid=first;
    }
    else
    {
     mid=first;   
    }
    
    Node *prev=NULL;
    Node *next=NULL;
    Node *curr=mid;
    
    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    
    
    while(prev!=NULL)
    {
        if(prev->data!=head->data)
        return false;
        prev=prev->next;
        head=head->next;
    }
    
    
    
    return true;
}

};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends