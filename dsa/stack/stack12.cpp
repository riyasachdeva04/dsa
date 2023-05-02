#include<iostream>
using namespace std;
#include<stack>
#include<string>
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int len;
        int maxlen = 0;
        for(int i=0 ; i<s.length() ; i++)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    len = i - st.top();
                    maxlen = max(len, maxlen);
                }
            }
        }
        return maxlen;
    }
};