class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int n = max(a.size(), b.size());

        for(int i = 0; i < n; i++){
            int digita = 0;
            int digitb = 0;
            if(i < a.size()) digita = a[i] - '0';
            if(i < b.size()) digitb = b[i] - '0';

            int tot = digita + digitb + carry;
            ans.push_back((tot % 2)+'0');
            carry = tot/2;
        }

        if(carry)  ans.push_back('1');
        reverse(ans.begin(), ans.end());

        return ans;
    }
};