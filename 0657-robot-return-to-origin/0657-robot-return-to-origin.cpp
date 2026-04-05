class Solution {
public:
    bool judgeCircle(string moves) {
        pair<int, int> p{0,0};

        for(auto ch : moves){
            if(ch == 'R') p.first++;
            else if(ch == 'L')p.first--;
            else if(ch == 'U')p.second++;
            else p.second--;
        }

        return (p.first == 0 && p.second == 0) ? true : false;
    }
};