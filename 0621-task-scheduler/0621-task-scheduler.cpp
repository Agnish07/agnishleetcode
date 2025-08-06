class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> hash(26,0);

        for(int i = 0; i < tasks.size(); i++){
            hash[tasks[i] - 'A']++;
        }
        sort(hash.begin(), hash.end());
        int maxval = hash[25] - 1;
        int idle = maxval*n;

        for(int i = 24; i >= 0; i--){
            int m = min(hash[i], maxval);
            idle = idle - m;
        }

        return idle > 0 ? idle+tasks.size() : tasks.size();
    }
};