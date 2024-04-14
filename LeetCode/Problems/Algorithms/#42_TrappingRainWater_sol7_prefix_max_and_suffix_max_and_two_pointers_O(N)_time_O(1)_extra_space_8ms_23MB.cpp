class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();

        int totalWater = 0;
        int prefMaxHeight = 0;
        int suffMaxHeight = 0;

        int l = 0;
        int r = N - 1;
        while(l <= r){
            prefMaxHeight = max(prefMaxHeight, height[l]);
            suffMaxHeight = max(suffMaxHeight, height[r]);
            if(prefMaxHeight <= suffMaxHeight){
                totalWater += (prefMaxHeight - height[l]);
                l += 1;
            }else{
                totalWater += (suffMaxHeight - height[r]);
                r -= 1;
            }
        }

        return totalWater;
    }
};