class Solution {
public:
    bool possible(vector<int> &arr, int day, int k, int m){
        int count = 0;
        int nob = 0;

        for(int i = 0; i < arr.size();i++){
            if(day >= arr[i]){
                count ++;
            }
            else{
                nob += count/k;
                count = 0;
            }
        }
        nob += count/k;
        if(nob >= m) return true;
        else return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();
        if((long long)n < (long long)m*(long long)k) return -1;
        int ans = -1;

        while(low <= high){
            int mid = low + ((high - low)/2);
            
            if(possible(bloomDay,mid,k,m)){
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