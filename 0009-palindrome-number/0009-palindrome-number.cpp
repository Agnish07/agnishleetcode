class Solution {
public:
    bool isPalindrome(int x) {
        int y = x;
        if(x < 0){
            return false;
        }
        long long ulta = 0;
        while(y > 0){
            int i = y%10;
            ulta = (ulta * 10) + i;
            y = y/10;
        }

        if(ulta == x){
            return true;
        }
        return false;
    }
};