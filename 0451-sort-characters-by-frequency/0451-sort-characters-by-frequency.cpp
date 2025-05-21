class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mpp;

        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }

        int maxf = s.length();

        vector<vector<char>> buckets(maxf + 1);
        for(auto [ch, fq] : mpp){
            buckets[fq].push_back(ch);
        }

        string result;
        for (int i = maxf; i > 0; --i) {
            for (char ch : buckets[i]) {
                result.append(i, ch);  // repeat character 'i' times
            }
        }

        return result;



    }
};