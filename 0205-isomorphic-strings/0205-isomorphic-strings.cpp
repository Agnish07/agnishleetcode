class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for(int i = 0 ; i < s.length(); i++){
            if((st.find(s[i]) != st.end() && st[s[i]] != t[i]) || 
                (ts.find(t[i]) != ts.end() && ts[t[i]] != s[i])){
                    return false; 
            }
                st[s[i]] = t[i];
                ts[t[i]] = s[i];

        }
        return true;
    }
};