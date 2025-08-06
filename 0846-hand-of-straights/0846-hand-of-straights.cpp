class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size()%groupSize != 0) return false;

        unordered_map<int, int> count;
        for (int card : hand) count[card]++;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &p : count) pq.push(p.first);

            while(!pq.empty()){
                int smallest = pq.top();
                for(int i = 0; i < groupSize; i++){
                    int curr = smallest+i;
                    if(count[curr] == 0) return false;
                    count[curr]--;

                    if(count[curr] == 0){
                        if(pq.top() != curr) return false;
                        pq.pop();
                    }
                }
            }
            return true;
    }
};