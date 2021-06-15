class Solution {
private:
    static bool decUnitsPerBoxComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] > RHS[1]);
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        const int N = boxTypes.size();
        
        sort(boxTypes.begin(), boxTypes.end(), decUnitsPerBoxComp);
        
        int maxUnits = 0;
        for(int i = 0; truckSize > 0 && i < N; ++i){
            int boxes = min(boxTypes[i][0], truckSize);
            int units = boxes * boxTypes[i][1];
            maxUnits += units;
            truckSize -= boxes;
        }
        
        return maxUnits;
    }
};