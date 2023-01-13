class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        const int R = ranges.size();

        for(int val = left; val <= right; ++val){
            bool found = false;
            for(int i = 0; i < R && !found; ++i){
                if(ranges[i][0] <= val && val <= ranges[i][1]){
                    found = true;
                }
            }
            if(!found){
                return false;
            }
        }

        return true;
    }
};