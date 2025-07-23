class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        vector<int> lastseen(3,-1);

        for(int i = 0; i < s.length(); i++){
            lastseen[s[i] - 'a'] = i;
            if(lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1){
                cnt += 1 + *min_element(lastseen.begin(), lastseen.end());
            }
        }
        return cnt;
    }
};