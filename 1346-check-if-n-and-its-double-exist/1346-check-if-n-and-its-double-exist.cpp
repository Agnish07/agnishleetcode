class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        bool ans = false;
        for(int i = 0; i < arr.size(); i++){
            for(int j = i+1; j < arr.size(); j++){
                if(2*arr[i] == arr[j] || 2*arr[j] == arr[i]){
                    ans = true;
                }
            }
        }
        return ans;
    }
};