class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0;
        int n = gain.size();
        int maxg = 0;

        for(int i = 0; i < n; i++){
            sum += gain[i];

            if(sum > 0){
            maxg = max(sum,maxg);
            }
        }
        return maxg;
    }
};