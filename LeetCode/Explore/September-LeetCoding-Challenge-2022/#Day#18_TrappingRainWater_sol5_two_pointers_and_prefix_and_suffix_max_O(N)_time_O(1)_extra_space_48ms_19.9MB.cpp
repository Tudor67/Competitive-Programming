class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        
        int totalWater = 0;
        int l = 0;
        int r = N - 1;
        int prefMax = height[0];
        int suffMax = height[N - 1];
        
        while(l <= r){
            prefMax = max(prefMax, height[l]);
            suffMax = max(suffMax, height[r]);
            if(prefMax <= suffMax){
                totalWater += (prefMax - height[l]);
                l += 1;
            }else{
                totalWater += (suffMax - height[r]);
                r -= 1;
            }
        }
        
        return totalWater;
    }
};