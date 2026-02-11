class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> last;
        unordered_map<int,int> firstPos;

        vector<int> contrib(n, 0);
        int prefix = 0, ans = 0;

        firstPos[0] = -1;

        for(int i = 0; i < n; i++){
            int x = nums[i];
            int val = (x % 2 == 0 ? 1 : -1);

            if(last.count(x)) {
                contrib[last[x]] = 0;   // remove old contribution
            }

            contrib[i] = val;
            last[x] = i;
        }

        prefix = 0;
        for(int i = 0; i < n; i++){
            prefix += contrib[i];
            if(firstPos.count(prefix))
                ans = max(ans, i - firstPos[prefix]);
            else
                firstPos[prefix] = i;
        }

        return ans;
    }
};