class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nge;  // stores next greater element for each number in nums2
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];

            // Pop smaller or equal elements from the stack
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }

            // If stack is empty, no greater element; else, top is the NGE
            nge[num] = st.empty() ? -1 : st.top();

            st.push(num);
        }

        vector<int> result;
        for (int num : nums1) {
            result.push_back(nge[num]);
        }

        return result;
    }
};
