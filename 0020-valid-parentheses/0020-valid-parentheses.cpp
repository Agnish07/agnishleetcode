using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        unordered_map<char, char> closetoopen{
            {')' , '('},
            {']', '['},
            {'}', '{'}
        };
        for(char c : s){
            if(closetoopen.count(c)){
                if(!stack.empty() && stack.top() == closetoopen[c]){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
};