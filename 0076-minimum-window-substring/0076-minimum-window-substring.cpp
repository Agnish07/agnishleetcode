class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, minlen = INT_MAX, cnt = 0, sind = -1;
        vector<int> hash(256, 0), freq(256, 0);
        
        for(int i = 0; i < t.size(); i++){
            hash[t[i]]++;
            freq[t[i]]++;
        }

        while(r < s.size()){
            if(freq[s[r]] > 0){
                hash[s[r]]--;
                if(hash[s[r]] >= 0) cnt++;
            }

            while(cnt == t.size()){
                if(r - l + 1 < minlen){
                    minlen = r - l + 1;
                    sind = l;
                }

                if(freq[s[l]] > 0){
                    hash[s[l]]++;
                    if(hash[s[l]] > 0) cnt--;
                }
                l++;
            }
            r++;
        }
        
        return sind == -1 ? "" : s.substr(sind, minlen);
    }
};
