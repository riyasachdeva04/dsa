
// string isSubset(int a1[], int a2[], int n, int m) {
    
//     unordered_map<int, int> M1;
    
//     for(int i=0; i<n; i++)
//     {
//         int elem = a1[i];
//         M1[elem] += 1;
//     }
    
//     for(int i=0; i<m; i++)
//     {
//         int elem = a2[i];
//         if(M1[elem] >= 1)
//         {
//             M1[elem] --;
//             continue;
//         }
            
//         if(M1[elem] == 0)
//             return "No";
//     }
//     return "Yes";
    
// }

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};


// } Driver Code Ends
/*
// structure of the node is as follows

struct Node
{
	int data;
	struct Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

*/
class Solution
{
    public:
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        // code here
        map<int, Node*> map;
        
        // hash 1st
        Node* curr = head1;
        
        while(curr != NULL)
        {
            map[curr->data] = curr;
            curr = curr->next;
        }
        
        // hash 2nd
        curr = head2;
        
        while(curr != NULL)
        {
            map[curr->data] = curr;
            curr = curr->next;
        }
        Node* UL = NULL;
        curr = NULL;
        
        // iterate map & make final UL
        for(auto it = map.begin(); it!=map.end(); it++)
        {
            if(curr == NULL)
            {
                UL = it->second;
                curr = UL;
                
            }
            else
            {
                curr->next = it->second;
                curr = curr->next;
            }
        }
        curr->next = NULL;
        return UL;
    }
};