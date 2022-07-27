class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        const int N = boxTypes.size();
        
        // count sort: decreasing order of unitsPerBox
        int maxUnitsPerBox = 0;
        for(const vector<int>& BOX_TYPE: boxTypes){
            int unitsPerBox = BOX_TYPE[1];
            maxUnitsPerBox = max(maxUnitsPerBox, unitsPerBox);
        }
        
        vector<int> count(maxUnitsPerBox + 1);
        for(const vector<int>& BOX_TYPE: boxTypes){
            int unitsPerBox = BOX_TYPE[1];
            count[unitsPerBox] += 1;
        }
        
        for(int u = maxUnitsPerBox - 1; u >= 0; --u){
            count[u] += count[u + 1];
        }
        
        vector<int> p(N);
        for(int i = N - 1; i >= 0; --i){
            int unitsPerBox = boxTypes[i][1];
            count[unitsPerBox] -= 1;
            p[count[unitsPerBox]] = i;
        }
        
        // greedy
        int maxUnits = 0;
        for(int i = 0; i < N && truckSize > 0; ++i){
            int takenBoxes = min(truckSize, boxTypes[p[i]][0]);
            int unitsPerBox = boxTypes[p[i]][1];
            maxUnits += takenBoxes * unitsPerBox;
            truckSize -= takenBoxes;
        }
        
        return maxUnits;
    }
};