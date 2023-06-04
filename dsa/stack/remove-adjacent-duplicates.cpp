class Solution {
public:
    string removeDuplicates(string s) {

        stack<char> st;
        for(auto v:s)
        {
            if(!st.empty() && st.top() == v)
                st.pop();
            else
                st.push(v);
        }

        string ans;

        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};