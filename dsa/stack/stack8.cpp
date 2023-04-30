// valid parenthesis
#include <iostream>
using namespace std;
#include<stack>
#include<string>

bool isValid(string s) {

        stack<char> st;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];

            //opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                //closing bracket - ch
                if(!st.empty()) {
                    char topCh = st.top();
                    if(ch == ')' && topCh =='(') {
                        //matching brackets
                        st.pop();
                    }
                    else if(ch == '}' && topCh =='{') {
                        //matching brackets
                        st.pop();
                    }
                    else if(ch == ']' && topCh =='[') {
                        //matching brackets
                        st.pop();
                    }
                    else {
                        //brackets not matching
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }

        if(st.empty()) {
            //valid 
            return true;
        }
        else {
            return false;
        }
        
    }

int main() {
  string s1 = "())";
  string s2 = "(())";
  string s3 = "()";
  if(isValid(s1))
    cout << "True";
  else
    cout << "False";
}