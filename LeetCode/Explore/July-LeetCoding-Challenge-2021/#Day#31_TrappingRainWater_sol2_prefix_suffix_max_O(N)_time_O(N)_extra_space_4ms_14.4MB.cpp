class Solution {
public:
    int trap(vector<int>& h) {
        if(h.empty()){
            return 0;
        }
        
        const int N = h.size();
        vector<int> prefMax(N);
        prefMax[0] = h[0];
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], h[i]);
        }
        
        vector<int> suffMax(N);
        suffMax[N - 1] = h[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMax[i] = max(h[i], suffMax[i + 1]);
        }
        
        int totalWater = 0;
        for(int i = 1; i < N - 1; ++i){
            int maxValidHeight = min(prefMax[i - 1], suffMax[i + 1]);
            totalWater += max(0, maxValidHeight - h[i]);
        }
        
        return totalWater;
    }
};