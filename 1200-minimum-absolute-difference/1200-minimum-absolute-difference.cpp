class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = 1;
        int mini = INT_MAX;
        vector<vector<int>> ans;

        while(i <= arr.size()-1 && j <= arr.size()-1){
            int diff = abs(arr[i]-arr[j]);
            if(mini == diff) ans.push_back({arr[i],arr[j]});
            else if(mini > diff){
                ans.erase(ans.begin(), ans.end());
                ans.push_back({arr[i],arr[j]});
                mini = diff;
            }
            i++;
            j++;
        }
        return ans;
    }
};