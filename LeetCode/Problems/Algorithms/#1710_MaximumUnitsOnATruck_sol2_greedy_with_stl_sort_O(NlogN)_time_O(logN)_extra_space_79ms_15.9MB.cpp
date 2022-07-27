class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        const int N = boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(),
            [](const vector<int>& LHS, const vector<int>& RHS){
                return (LHS[1] > RHS[1]);
            });
        
        int maxUnits = 0;
        for(int i = 0; i < N && truckSize > 0; ++i){
            int takenBoxes = min(truckSize, boxTypes[i][0]);
            int unitsPerBox = boxTypes[i][1];
            maxUnits += takenBoxes * unitsPerBox;
            truckSize -= takenBoxes;
        }
        
        return maxUnits;
    }
};