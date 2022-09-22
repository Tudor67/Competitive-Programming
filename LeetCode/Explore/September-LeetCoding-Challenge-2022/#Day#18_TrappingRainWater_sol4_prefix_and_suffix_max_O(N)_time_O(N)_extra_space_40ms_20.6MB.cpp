class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        
        vector<int> prefMax(N);
        prefMax[0] = height[0];
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], height[i]);
        }
        
        vector<int> suffMax(N);
        suffMax[N - 1] = height[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMax[i] = max(height[i], suffMax[i + 1]);
        }
        
        int totalWater = 0;
        for(int i = 1; i < N - 1; ++i){
            int heightLimit = min(prefMax[i], suffMax[i]);
            int contrib = heightLimit - height[i];
            totalWater += contrib;
        }
        
        return totalWater;
    }
};