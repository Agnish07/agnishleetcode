class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        // sort(letters.begin(), letters.end());
        int low = 0;
        int high = letters.size()-1;
        if(letters[high] <= target) return ans;

        while(low <= high){
            int mid = (high+low)/2;

            if(letters[mid] <= target){
                low = mid+1;
            }
            else{
                ans = letters[mid];
                high = mid-1;
            }
        }

        return ans;
    }
};