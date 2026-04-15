class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int res = INT_MAX;
        int n = words.size();
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int dist = abs(i - startIndex);
                int cdist = n-dist;

                res = min({res, dist, cdist});
            }
        }

        return res == INT_MAX ? -1 : res;
    }
};