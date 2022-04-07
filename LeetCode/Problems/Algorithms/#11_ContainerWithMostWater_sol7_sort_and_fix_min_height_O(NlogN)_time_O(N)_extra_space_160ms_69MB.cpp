class Solution {
public:
    int maxArea(vector<int>& height) {
        const int N = height.size();
        
        vector<pair<int, int>> sortedHeightIdx(N);
        for(int i = 0; i < N; ++i){
            sortedHeightIdx[i] = {height[i], i};
        }
        
        sort(sortedHeightIdx.begin(), sortedHeightIdx.end());
        
        vector<int> suffMinIdx(N);
        vector<int> suffMaxIdx(N);
        suffMinIdx[N - 1] = sortedHeightIdx[N - 1].second;
        suffMaxIdx[N - 1] = sortedHeightIdx[N - 1].second;
        for(int i = N - 2; i >= 0; --i){
            suffMinIdx[i] = min(sortedHeightIdx[i].second, suffMinIdx[i + 1]);
            suffMaxIdx[i] = max(sortedHeightIdx[i].second, suffMaxIdx[i + 1]);
        }
        
        int res = 0;
        for(int i = 0; i < N; ++i){
            int l = suffMinIdx[i];
            int r = suffMaxIdx[i];
            int area = min(height[l], height[r]) * (r - l);
            res = max(res, area);
        }
        
        return res;
    }
};