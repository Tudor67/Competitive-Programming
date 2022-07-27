class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        const int N = boxTypes.size();
        
        // counter
        int maxUnitsPerBox = 0;
        for(const vector<int>& BOX_TYPE: boxTypes){
            int unitsPerBox = BOX_TYPE[1];
            maxUnitsPerBox = max(maxUnitsPerBox, unitsPerBox);
        }
        
        vector<int> count(maxUnitsPerBox + 1);
        for(const vector<int>& BOX_TYPE: boxTypes){
            int numberOfBoxes = BOX_TYPE[0];
            int unitsPerBox = BOX_TYPE[1];
            count[unitsPerBox] += numberOfBoxes;
        }
        
        // greedy
        int maxUnits = 0;
        for(int unitsPerBox = maxUnitsPerBox; unitsPerBox > 0 && truckSize > 0; --unitsPerBox){
            int takenBoxes = min(truckSize, count[unitsPerBox]);
            maxUnits += takenBoxes * unitsPerBox;
            truckSize -= takenBoxes;
        }
        
        return maxUnits;
    }
};