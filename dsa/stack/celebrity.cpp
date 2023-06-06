//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            st.push(i);
        }
        
        while(st.size() != 1)
        {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();
            
            if(M[a][b])
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
        }
        
        int mightBeCeleb = st.top(); st.pop();
        
        // check for 0 through row
        for(int i=0; i<n; i++)
        {
            if(M[mightBeCeleb][i] !=0 )
                return -1;
        }
        
        // check for 1 through col
        for(int i=0 ; i<n; i++)
        {
            if(M[i][mightBeCeleb] != 1 && i!=mightBeCeleb)
                return -1;
        }
        
        return mightBeCeleb;
    }
};