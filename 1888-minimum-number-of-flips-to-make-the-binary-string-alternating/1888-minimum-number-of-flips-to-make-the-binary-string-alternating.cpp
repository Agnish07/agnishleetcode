class Solution {
public:
    int minFlips(string s) {
        int res = INT_MAX;
        int n = s.size();
        int i = 0;
        int j = 0;
        
        int flip1 = 0;
        int flip2 = 0;

        while(j < 2*n){
            char c1 = j%2 ? '0' : '1';
            char c2 = j%2 ? '1' : '0';

            if(s[j%n] != c1) flip1++;
            if(s[j%n] != c2) flip2++;

            if(j-i+1 > n){
                char cr1 = i%2 ? '0' : '1';
                char cr2 = i%2 ? '1' : '0';

                if(s[i%n] != cr1)flip1--;
                if(s[i%n] != cr2)flip2--;

                i++;
            }

            if(j-i+1 == n) res = min({res,flip1,flip2});
            j++;
        }

        return res;
    }
};