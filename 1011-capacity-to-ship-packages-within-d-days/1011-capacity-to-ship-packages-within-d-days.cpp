class Solution {
public:
    int loadcap(vector<int> &wt, int cap){
        int days = 1;
        int load = 0;

        for(int i = 0; i < wt.size(); i++){
            if(load+wt[i] > cap){
                days++;
                load = wt[i];
            }
            else{
                load += wt[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while(low <= high){
            int mid = low + ((high - low)/2);

            if(loadcap(weights,mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};