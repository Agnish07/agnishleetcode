class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxd = 0;

        for(auto c : s){
            if(c == '('){
                cnt++;
                maxd = max(maxd,cnt);
            }
            else if(c == ')') cnt--;
        }
        return maxd;
    }
};