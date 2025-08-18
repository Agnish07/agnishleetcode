class Solution {
public:
    static bool comp(vector<int>& val1, vector<int>& val2){
        return val1[1] < val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        int cnt = 1;
        int n = intervals.size();
        int lastendtime = intervals[0][1];

        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= lastendtime){
                cnt++;
                lastendtime = intervals[i][1];
            }
        }

        return n - cnt;

    }
};