class Solution {
public:
    int maxArea(vector<int>& heights) {
        const int N = heights.size();

        int res = 0;
        int l = 0;
        int r = N - 1;

        while(l < r){
            res = max(res, (r - l) * min(heights[l], heights[r]));
            if(heights[l] <= heights[r]){
                l += 1;
            }else{
                r -= 1;
            }
        }

        return res;
    }
};