class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        string wa;

        int i = 0, j = 0;
        int m = word1.length();
        int n = word2.length();

        while(i < m || j<n){

            if(i < m){
            wa += word1[i];
            i++;
            }

            if(j < n){
            wa += word2[j];
            j++;
            }
        }
        
        return wa;
    }
};