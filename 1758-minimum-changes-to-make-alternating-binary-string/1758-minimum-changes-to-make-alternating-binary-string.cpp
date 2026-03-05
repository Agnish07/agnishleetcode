class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        int prev = 0;
        int n = s.size();

        for(int i = 0; i < s.size(); i++){
            int bit = s[i] - '0';
            if(bit == prev){
                bit = 1 - prev;
                cnt++;
            }
            prev = bit;
        }

        return min(cnt, (n-cnt));
    }
};