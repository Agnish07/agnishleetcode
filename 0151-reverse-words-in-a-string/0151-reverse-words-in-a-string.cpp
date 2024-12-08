class Solution {
public:
    string reverseWords(string s) {

        // string str;
        // stringstream ss(s);

        // vector <string> v;

        // while(getline(ss, str, ' ')){
        //     v.push_back(str);
        // }
        // string ans;
        // for(int i = v.size()-1; i >= 0; i--){
        //     ans.append(v[i]);
        //     if(i != 0){
        //     ans.append(" ");
        //     }
        // }

        // return ans;


        int i = 0;
        int j = 0;
        int n = s.size();
        while(i < n){
            while(i < n && s[i] == ' '){
                    i++;
            }
            if(i < n){
                if(j != 0){
                    s[j++] = ' ';
                }
                int k = i;
                while(k < n && s[k] != ' '){
                    s[j++] = s[k++];
                }
                reverse(s.begin() + j - (k-i), s.begin()+j);
                i = k;
            }
        }
        s.erase(s.begin() + j, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};