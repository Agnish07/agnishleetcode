class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxarea = 0;


        for(int i = 0; i < heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int ele = st.top();
                st.pop();
            

            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea,(heights[ele] *(nse-pse-1)));
            }
            st.push(i);
        }

        while(!st.empty()){
            int nse = heights.size();
            int ele = st.top();
            st.pop();

            int pse = st.empty() ? -1 : st.top();

            maxarea = max(maxarea,(heights[ele] * (nse-pse-1)));

        }

        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxarea = 0;
        vector<vector<int>> psum(n, vector<int>(m));

        for(int j = 0 ; j < m ; j++){
    for(int i = 0 ; i < n ; i++){
        if(matrix[i][j] == '1'){
            psum[i][j] = (i == 0 ? 1 : psum[i-1][j] + 1);
        } else {
            psum[i][j] = 0;
        }
    }
}

        for(int i = 0; i < n; i++){
            maxarea = max(maxarea, largestRectangleArea(psum[i]));
        }
        return maxarea;
    }
};