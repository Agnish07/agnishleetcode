class Solution {
public:
    bool checkOnesSegment(string s) {
        if(s == "1") return true;
        int cnt = 0;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i]-'0' == 1){
                cnt++;
                while(s[i]-'0' == 1) i++;
            }
        }

        return cnt == 1 ? true : false;
    }
};