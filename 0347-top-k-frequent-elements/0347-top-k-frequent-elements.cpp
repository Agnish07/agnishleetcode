class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> mpp;
         priority_queue<pair<int,int>> pq;
        
         for(int i = 0; i < nums.size();i++){
            mpp[nums[i]]++;
         }

         for(auto& [num,freq] : mpp){
            pq.push({freq,num});
         }

         vector<int> ans;

         while(k > 0 && !pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);

            k--;

         }

         return ans;

    }
};