class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        auto cmp = [&](int &a, int &b){
            return positions[a] < positions[b];
        };

        int n = positions.size();

        vector<int> actInd(n);
        for(int i = 0; i < n; i++){
            actInd[i] = i;
        }

        sort(actInd.begin(), actInd.end(), cmp);

        vector<int> res;
        stack<int> st;

        for(int &curr : actInd){
            if(directions[curr] == 'R') st.push(curr);
            else {
                while(!st.empty() && healths[curr] > 0){
                    int top = st.top();
                    st.pop();

                    if(healths[top] > healths[curr]){
                        healths[top] -= 1;
                        healths[curr] = 0;
                        st.push(top);
                    }

                    else if(healths[top] < healths[curr]){
                        healths[curr] -= 1;
                        healths[top] = 0;

                    }
                    else{
                        healths[curr] = 0;
                        healths[top] = 0;
                    }
                }
            }
        }


        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                res.push_back(healths[i]);
            }
        }

        return res;

    }
};