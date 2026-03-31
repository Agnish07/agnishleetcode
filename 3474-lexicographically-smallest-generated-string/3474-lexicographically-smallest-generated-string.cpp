class Solution {
public:
    bool isSame(int i, int m, string& word, string& str){
        for(int j = 0; j < m; j++){
            if(i + j >= word.size() || word[i + j] != str[j]) return false;
        }

        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        int N = n+m-1;

        string word(N, '$');

        vector<bool> canchange(N, false);

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                int ind = i;
                for(int j = 0; j < m; j++){
                    if(word[ind] != '$' && word[ind] != str2[j]){
                        return "";
                    }
                    word[ind] = str2[j];
                    ind++;
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            if(word[i] == '$'){
                word[i] = 'a';
                canchange[i] = true;
            }
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){

                if(isSame(i, m, word, str2)){
                    bool changed = false;

                    for(int k = i+m-1; k >= i; k--){
                        if(canchange[k] == true){
                            word[k] = 'b';
                            changed = true;
                            break;
                        }
                    }

                    if(changed == false) return "";
                }

            }
        }

        return word;

    }
};