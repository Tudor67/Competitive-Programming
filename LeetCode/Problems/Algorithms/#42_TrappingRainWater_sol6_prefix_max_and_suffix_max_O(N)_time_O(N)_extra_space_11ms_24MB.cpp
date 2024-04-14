class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();

        vector<int> prefMaxHeight(N);
        prefMaxHeight[0] = height[0];
        for(int i = 1; i < N; ++i){
            prefMaxHeight[i] = max(prefMaxHeight[i - 1], height[i]);
        }

        vector<int> suffMaxHeight(N);
        suffMaxHeight[N - 1] = height[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMaxHeight[i] = max(height[i], suffMaxHeight[i + 1]);
        }

        int totalWater = 0;
        for(int i = 0; i < N; ++i){
            int maxValidHeight = min(prefMaxHeight[i], suffMaxHeight[i]);
            totalWater += (maxValidHeight - height[i]);
        }

        return totalWater;
    }
};