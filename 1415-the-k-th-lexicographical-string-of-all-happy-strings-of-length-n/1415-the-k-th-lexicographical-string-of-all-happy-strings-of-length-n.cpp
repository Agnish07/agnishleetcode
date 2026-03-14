class Solution {
public:

    void solve(string curr,int &count, int &k, int n, string &res){
        if(!curr.empty() && curr.size() == n){
            count++;
            if(count == k){
                res = curr;
            }
            return;
        }

        for(char ch = 'a'; ch <= 'c'; ch++){
            if(!curr.empty() && curr.back() == ch) continue;
            curr.push_back(ch);
            solve(curr,count, k, n, res);
            curr.pop_back();
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        string res = "";
        int cnt = 0;
        solve(curr,cnt,k,n,res);
        if(cnt < k) return "";
        return res;
    }
};