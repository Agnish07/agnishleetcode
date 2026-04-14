class Solution {
public:

    long long solve(int i, int j, vector<int> &rob, vector<int> &pos, vector<vector<long long>> &dp){
        if(i >= rob.size()) return 0;
        if(j >= pos.size()) return 1e12;
        if(dp[i][j] != -1) return dp[i][j];

        long long take = abs(rob[i]-pos[j]) + solve(i+1, j+1, rob, pos, dp);
        long long nottake = solve(i, j+1, rob, pos, dp);

        return dp[i][j] = min(take, nottake);
    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        int n = robot.size();
        
        vector<int> pos;
        for(int i = 0; i < factory.size(); i++){
            int lim = factory[i][1];
            int fac = factory[i][0];

            for(int j = 0; j < lim; j++){
                pos.push_back(fac);
            }
        }

        int m = pos.size();
        
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));

        return solve(0, 0, robot, pos, dp);
    }
};