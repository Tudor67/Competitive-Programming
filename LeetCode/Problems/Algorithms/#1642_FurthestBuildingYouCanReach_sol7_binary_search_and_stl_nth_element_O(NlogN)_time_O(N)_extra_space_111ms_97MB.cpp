class Solution {
private:
    bool isValid(vector<int>& heights, int bricks, int ladders, const int TARGET_INDEX){
        vector<int> diffs;
        for(int i = 0; i + 1 <= TARGET_INDEX; ++i){
            if(heights[i] < heights[i + 1]){
                diffs.push_back(heights[i + 1] - heights[i]);
            }
        }

        if((int)diffs.size() <= ladders){
            return true;
        }

        nth_element(diffs.begin(), diffs.end() - ladders, diffs.end());

        long long bricksNeed = accumulate(diffs.begin(), diffs.end() - ladders, (long long)0);

        return (bricksNeed <= bricks);
    }

public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int N = heights.size();

        int l = 0;
        int r = N - 1;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(isValid(heights, bricks, ladders, mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }

        return r;
    }
};