class Solution {
private:
    int sortAndGetMaxDiff(vector<int>& v, int rightBorder){
        const int N = v.size();
        
        make_heap(v.begin(), v.end());
        for(int i = N; i >= 1; --i){
            pop_heap(v.begin(), v.begin() + i);
        }
        
        int maxDiff = max(v.front(), rightBorder - v.back());
        for(int i = 1; i < N; ++i){
            maxDiff = max(maxDiff, v[i] - v[i - 1]);
        }
        
        return maxDiff;
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MODULO = 1e9 + 7;
        
        int maxDiffH = sortAndGetMaxDiff(horizontalCuts, h);
        int maxDiffV = sortAndGetMaxDiff(verticalCuts, w);
        
        return (maxDiffH * 1LL * maxDiffV) % MODULO;
    }
};