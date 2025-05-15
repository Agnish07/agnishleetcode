class Solution {
public:
    bool calcu(vector<int> &arr, int d,int t){
        int sum = 0;
        for(int i = 0 ; i < arr.size(); i++){
            sum += ceil((double)arr[i]/d);
        }
        if(sum <= t) return true;
        else return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low  = 1;
        int high = *max_element(nums.begin(),nums.end());
        int ans = -1;

        while(low <= high){
            int mid = low + ((high - low)/2);

            if(calcu(nums,mid,threshold)){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }

};