class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n == 0) return ans;
        for(int i = 1; i <= n; i++){
        int a = i;
            int cnt = 0;
            while(a != 0){
                a = a & (a-1);
                cnt++;
            }
            ans.push_back(cnt);
        }

        return ans;
    }
};