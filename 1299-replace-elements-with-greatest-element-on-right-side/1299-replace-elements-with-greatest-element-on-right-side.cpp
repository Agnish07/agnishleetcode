class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxn;
        int n = arr.size();

        for(int i = 0; i < n; i ++){
                int j;
                int res = -1;
            for( j = i+1; j < n; j++){

                    maxn = arr[j];
                    res = max(maxn, res);
            }
                    arr[i] = res;
        }
        arr[n-1] = -1;
        return arr;
    }
};