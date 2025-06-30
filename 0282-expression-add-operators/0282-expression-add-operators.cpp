class Solution {
public:

    void func(int ind, vector<string> &ans, string path, string num,long long calc, long long prev, int target){
        if(ind == num.length()){
            if(calc == target){
                ans.push_back(path);
            }
            return;
        }

        for(int i = ind; i < num.size(); i++){
            if(i != ind && num[ind] == '0') break;

            string currstr = num.substr(ind, i - ind + 1);
            long long curr = stoll(currstr);

            if(ind == 0){
                func(i + 1, ans, path + currstr, num, curr,curr,target);
            }
            else{
            func(i+1, ans, path + '+' + currstr, num, calc + curr, curr, target);
            func(i+1, ans, path + '-' + currstr, num, calc - curr, -curr, target);
            func(i+1, ans, path + '*' + currstr, num, calc - prev + prev * curr,  prev * curr, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        string path = "";
        func(0, ans, path, num, 0, 0, target);
        return ans;
    }
};