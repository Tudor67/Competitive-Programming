class Solution {
private:
    bool isValid(vector<int>& heights, int bricks, int ladders, const int& TARGET_POS){
        vector<int> diffs;
        for(int i = 0; i < TARGET_POS; ++i){
            if(heights[i] < heights[i + 1]){
                diffs.push_back(heights[i + 1] - heights[i]);
            }
        }
        sort(diffs.begin(), diffs.end());
        while(!diffs.empty() && ladders >= 1){
            ladders -= 1;
            diffs.pop_back();
        }
        while(!diffs.empty()){
            bricks -= diffs.back();
            diffs.pop_back();
            if(bricks < 0){
                return false;
            }
        }
        return true;
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