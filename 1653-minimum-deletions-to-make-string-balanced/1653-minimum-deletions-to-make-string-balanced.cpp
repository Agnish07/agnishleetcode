class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> aright(n, 0);

        for(int i = n-2; i >= 0; i--){
            aright[i] = aright[i+1];
            if(s[i+1] == 'a'){
                aright[i] += 1;
            }
        }

        int bleft = 0;
        int res = INT_MAX;

        for(int i = 0; i < n; i++){
            int ans = bleft+aright[i];
            res = min(res, ans);
            if(s[i] == 'b') bleft += 1;

        }

        return res;
    }
};