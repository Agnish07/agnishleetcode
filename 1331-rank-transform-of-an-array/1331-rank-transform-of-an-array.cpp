class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        priority_queue<pair<int,int>> pq;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            pq.push({-arr[i], i});
        }
        int rank = 0;
        int prev = INT_MAX;
        vector<int> ans(n,0);
        while(!pq.empty()){
            auto it = pq.top();
            if(it.first == prev){
                ans[it.second] = rank;
            }
            else{
                rank++;
                ans[it.second] = rank;
                prev = it.first;
            }
            pq.pop();
        }
        return ans;
    }
};