class Solution {
public:
    void rotate(vector<vector<int>>& mat){
        int n = mat.size();
        int m = mat[0].size();

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < m; j++){
                swap(mat[i][j], mat[j][i]);
            }
        }

        for(int i = 0; i < n; i++){
            reverse(mat[i].begin(), mat[i].end());
        }
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        int m = mat[0].size();

        for(int c = 0; c < 4; c++){
        bool eq = true;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] != target[i][j]){
                    eq = false;
                    break;
                }
            }
            if(!eq) break;
            }   
                if(eq) return true;
                rotate(mat);
        }
                return false;

    }
};