class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> prevXORValues = {0};
        unordered_set<int> currXORValues;

        for(int i = 1; i <= 3; ++i){
            currXORValues.clear();
            for(int xorVal: prevXORValues){
                for(int num: nums){
                    currXORValues.insert(xorVal ^ num);
                }
            }
            prevXORValues = currXORValues;
        }

        return currXORValues.size();
    }
};