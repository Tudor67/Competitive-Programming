class Solution {
private:
    static bool incUnitsPerBoxComp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int boxTypesSize = boxTypes.size();
        
        int maxUnits = 0;
        make_heap(boxTypes.begin(), boxTypes.end(), incUnitsPerBoxComp);
        
        while(boxTypesSize > 0 && truckSize > 0){
            int numberOfBoxes = boxTypes.front()[0];
            int unitsPerBox = boxTypes.front()[1];
            
            int takenBoxes = min(truckSize, numberOfBoxes);
            maxUnits += takenBoxes * unitsPerBox;
            truckSize -= takenBoxes;
            
            pop_heap(boxTypes.begin(), boxTypes.begin() + boxTypesSize, incUnitsPerBoxComp);
            boxTypesSize -= 1;
        }
        
        return maxUnits;
    }
};