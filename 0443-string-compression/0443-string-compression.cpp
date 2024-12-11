class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        int sizee = chars.size();

        for( int i = 0; i < sizee;){
            const char letter = chars[i];
            int count = 0;
            while( i < chars.size() && chars[i] == letter){
                ++count;
                ++i;
            }
            chars[ans++] = letter;
            if(count > 1){
                for(const char c : to_string(count)){
                    chars[ans++] = c;
                }
            }
        }
        return ans;
    
    }
};