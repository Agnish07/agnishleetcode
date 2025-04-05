class Solution {
public:
    string rem(string s){
        string result;
        for(auto c : s){
            if(isalnum(c)){
                result += tolower(c);
            }
        }
        return result;
    }
    void fn(int l, int r, string& s){

        if(r <= l){
            return;
        }

        char c = s[l];
        s[l] = s[r];
        s[r] = c;

        fn(l+1, r-1, s);

    }
    bool isPalindrome(string s) {
        s = rem(s);

        string res = s;
        fn(0,s.length()-1,res);

        return (res == s);

    }
};