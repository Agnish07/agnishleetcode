class Solution {
public:
    long long func(vector<int> &arr, int hr){
        long long total = 0;
        for(int i = 0; i < arr.size();i++){
            total += ceil((double)arr[i]/hr);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            long long mid = low + ((high - low)/2);

            long long total = func(piles,mid);
            if(total <= h){
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