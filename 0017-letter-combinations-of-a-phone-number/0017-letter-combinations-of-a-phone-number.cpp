class Solution {
public:

    void func(int ind, string &digits, vector<string> &ans, unordered_map<char, string> &mp, string temp){
        if(ind >= digits.length()){
            ans.push_back(temp);
            return;
        }

        string str = mp[digits[ind]];

        for(int i = 0; i < str.length(); i++){
            temp.push_back(str[i]);
            func(ind + 1, digits, ans, mp, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return{};

        unordered_map<char, string> mp;
        vector<string> result;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        func(0, digits, result,mp, "");

        return result;
    }
};