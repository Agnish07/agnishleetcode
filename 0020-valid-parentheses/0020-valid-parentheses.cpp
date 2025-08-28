class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else if(c == ')' || c == '}' || c == ']'){
                if(st.empty()) return false;

                else if (c == ')' && st.top() != '(' ||
                        c == '}' && st.top() != '{' || 
                        c == ']' && st.top() != '['){
                            return false;
                        }
                        st.pop();
            }
        }
        return true;
    }
};