class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i = 0 ; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size();j++){
                if(nums1[i] == nums2[j]){
                    int cnt = count(ans.begin(), ans.end(), nums2[j]);
                        if(cnt == 0){
                            ans.push_back(nums2[j]);
                    }
                }
            }
        }
        return ans;

    }
};