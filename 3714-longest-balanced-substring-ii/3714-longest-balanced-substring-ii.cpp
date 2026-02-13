class Solution {
public:
    int solve(string s, char c1, char c2, char skip){
        int maxi = 0;
        for(int i = 0; i < s.size(); i++){
            while(i < s.size() && s[i] == skip) i++;
            if(i >= s.size()) break;
            int p = i;

            while(i < s.size() && s[i] != skip)i++;
            int q = i-1;
            int x = 0;
            int y = 0;

            unordered_map<int, int> mpp;
            mpp[0] = p-1;

            for(int j = p; j <= q; j++){
                char ch = s[j];
                if(ch == c1) x++;
                else y++;
                int key = x-y;

                if(mpp.find(key) != mpp.end()){
                    maxi = max(maxi, j-mpp[key]);
                }
                else{
                    mpp[key] = j;
                }
            }
        }

        return maxi;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxi = 1;
        int curr = 1;

        for(int i = 1; i < n; i++){
            
            if(s[i] != s[i-1]) curr = 1;
            else curr++;
            maxi = max(maxi, curr);
        }

        unordered_map<string ,int> mpp;

        mpp["0,0"] = -1;
        int a = 0, b = 0, c = 0;

        for(int i = 0; i < n; i++){
            char ch = s[i];
            if(ch == 'a') a++;
            else if (ch == 'b') b++;
            else c++;

            string diff1 = to_string(a-b);
            string diff2 = to_string(a-c);

            string key = diff1 + "," + diff2;

            if(mpp.find(key) != mpp.end()){
                maxi = max(maxi, i-mpp[key]);
            }
            else{
                mpp[key] = i;
            }
        }

        maxi = max(maxi, solve(s, 'a', 'b', 'c'));
        maxi = max(maxi, solve(s, 'b', 'c', 'a'));
        maxi = max(maxi, solve(s, 'a', 'c', 'b'));

        return maxi;

    }
};