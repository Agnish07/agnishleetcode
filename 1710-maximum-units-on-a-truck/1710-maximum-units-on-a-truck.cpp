class Solution {
public:
    bool static comp(const vector<int>& box1,const vector<int>& box2){
        double r1 = (double)box1[1];
        double r2 = (double)box2[1];
        return r1 > r2;
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), comp);
        double total = 0.0;

        for(int i = 0; i < boxTypes.size(); i++){
            if(boxTypes[i][0] <= truckSize){
                total += (boxTypes[i][0]*boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            }
            else{
                total += truckSize*boxTypes[i][1];
                break;
            }
        }
        return total;
    }
};