class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length() < str2.length()){
            return gcdOfStrings(str2, str1);
        }

        if(str1 + str2 != str2 + str1){
            return "";
        }

        int gcdval = std::gcd(str1.size(), str2.size());

        return str1.substr(0, gcdval);
    }
};