class Solution {
public:

    string solve(string &s){
        int sum = 0;
        int start = 0;
        vector<string> specials;

        for(int i = 0; i < s.size(); i++){
            sum = s[i] == '1' ? sum+1 : sum-1;
            if(sum == 0){
                string inner = s.substr(start+1, i-start-1);
                specials.push_back("1" + solve(inner) + "0");
                start = i+1;
            }
        }

        sort(begin(specials), end(specials), greater<string>());

        string result;

        for(string &str : specials){
            result += str;
        }

        return result;
    }

    string makeLargestSpecial(string s) {
        return solve(s);
    }
};