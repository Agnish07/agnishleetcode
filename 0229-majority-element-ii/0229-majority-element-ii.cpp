class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int cnt1 = 0; int cnt2 = 0; int el1; int el2;
       vector<int> ans;

       for(int i = 0 ; i < nums.size(); i++){
        if(cnt1 == 0 && nums[i] != el2){
            cnt1 = 1;
            el1 = nums[i];
        }
        else if(cnt2 == 0 && nums[i] != el1){
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1) cnt1++;
        else if(nums[i] == el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
       }
        cnt1 = 0; cnt2 = 0;
       for(int i = 0; i < nums.size(); i++){
        if(nums[i] == el1){
            cnt1++;
        }
        else if(nums[i] == el2){
            cnt2++;
        }
       }
       if(cnt1 >= (nums.size()/3) + 1){
        ans.push_back(el1);
       }
        if(cnt2 >= (nums.size()/3) + 1){
        ans.push_back(el2);
       }
       return ans;
    }
};