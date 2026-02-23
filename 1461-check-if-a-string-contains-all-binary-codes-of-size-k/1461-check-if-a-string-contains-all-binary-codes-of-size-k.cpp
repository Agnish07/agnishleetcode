class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i = k;
        int states = pow(2, k);

        unordered_set<string> st;

        while(i <= s.size()){
            string sub = s.substr(i-k, k);
            st.insert(sub);
            if(st.size() == states) return true;
            i++;
        }

        return st.size() == states ? true : false;
    }
};