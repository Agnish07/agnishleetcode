class Solution {
public:
    bool check(long long mid, vector<int>& wt, long long mh){
        long long h = 0;
        for(int t : wt){
            h += 1LL * (sqrt(((1LL * 2 * mid)/t) + 0.25) - 0.5);
            
            if(h >= mh) return true;
        }

        return h >= mh;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int tmax = INT_MIN;
        for(auto t : workerTimes){
            tmax = max(tmax, t);
        }
        long long ans = INT_MAX;
        long long l = 1;
        long long h = 1LL * tmax * mountainHeight * (mountainHeight + 1) / 2;

        while(l <= h){
            long long mid = l+(h-l)/2;

            if(check(mid, workerTimes, mountainHeight)){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return ans;
    }
};