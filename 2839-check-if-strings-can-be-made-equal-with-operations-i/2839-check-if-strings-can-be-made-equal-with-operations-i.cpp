class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int i = 0;
        int j = 2;

        int n = s1.size();

        while(j < n){
            if((s1[i] == s2[i] && s1[j] == s2[j]) || (s1[i] == s2[j] && s1[j] == s2[i])){
                i++;
                j++;
            }
            else return false;
            
        }

        return true;
    }
};