class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        const int R = ranges.size();

        int maxVal = ranges[0][1];
        for(const vector<int>& RANGE: ranges){
            int r = RANGE[1];
            maxVal = max(maxVal, r);
        }

        if(maxVal < right){
            return false;
        }

        vector<int> diff(maxVal + 2);
        for(const vector<int>& RANGE: ranges){
            int l = RANGE[0];
            int r = RANGE[1];
            diff[l] += 1;
            diff[r + 1] -= 1;
        }

        int activeRanges = 0;
        for(int val = 0; val <= right; ++val){
            activeRanges += diff[val];
            if(left <= val && val <= right && activeRanges == 0){
                return false;
            }
        }

        return true;
    }
};