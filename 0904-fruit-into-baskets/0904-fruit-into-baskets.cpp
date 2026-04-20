class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mpp;

        int r = 0;
        int l = 0;
        int maxl = 0;

        while(r < fruits.size()){
            mpp[fruits[r]]++; 
            if(mpp.size() > 2){
                mpp[fruits[l]]--;
                if(mpp[fruits[l]] == 0){
                    mpp.erase(fruits[l]);}
                    l++;
            }
            if(mpp.size() <= 2){
            int len = r-l+1;
            maxl = max(maxl, len);
            }
            r++;
        }

        return maxl;
    }
};