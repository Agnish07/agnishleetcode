class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> ret;
        for(int i = 1; i < nums.size()+1; i++){
            if(s.find(i) == s.end()){
                  ret.push_back(i)  ;
            }
        }
        return ret;
    }
};