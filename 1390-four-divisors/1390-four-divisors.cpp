class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto num : nums){
            int cnt = 0;
            int csum = 0;
            for(int i = 1; i*i <= num; i++){
                if(num % i == 0){
                    cnt++;
                    csum += i;
                    if(i*i != num){
                        cnt++;
                        csum += num/i;
                    }
                }
            }
                if(cnt == 4){
                    ans += csum;
                }
 
        }
        return ans;
    }
};