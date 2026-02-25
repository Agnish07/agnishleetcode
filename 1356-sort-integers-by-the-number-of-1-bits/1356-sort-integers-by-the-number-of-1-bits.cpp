class Solution {
public:
    static bool comp(int a, int b){
        int bita = __builtin_popcount(a);
        int bitb = __builtin_popcount(b);

        if(bita == bitb) return a < b;

        return bita < bitb;
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};