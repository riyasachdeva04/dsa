class Solution {
public:
    int minAddToMakeValid(string s) {

        int open = 0;
        stack<int> st;
        st.push(0);

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '(')
            {
                st.push(st.top() + 1);
                open++;
            }

            if(s[i] == ')')
            {
                if(open != 0)
                {
                    st.pop();
                    open--;
                }
                else
                    st.push(st.top() + 1);
            }

        }
        int ans = st.top();
        return ans;
    }
};