class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        if (nums1.size() > nums2.size())
        return intersect(nums2, nums1);
        unordered_map<int, int> count;

        // for(int i = 0; i < nums1.size(); i++){
        //     for(int j = 0; j < nums2.size(); j++){
        //         if(nums2[j] == nums1[i]){
        //             ans.push_back(nums2[j]);
        //         }
        //     }
        // }

        for(const int num : nums1){
            count[num]++;
        }

        for(const int num: nums2){
            if(const auto it = count.find(num);
             it != count.cend() && it->second --> 0){
                ans.push_back(num);
            }
        }
        return ans;
    }
};