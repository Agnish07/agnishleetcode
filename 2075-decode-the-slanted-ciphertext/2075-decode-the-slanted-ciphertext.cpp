class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int col = n/rows;

        string ans;

        for(int c = 0; c < col; c++){
            for(int j = c ; j < n; j += col+1){
                ans += encodedText[j];
            }
        }

        while(!ans.empty() && ans.back() == ' '){
            ans.pop_back();
        }

        return ans;
    }
};