class Solution {
private:
    int computeMaxDiff(const vector<int>& V, const int& RIGHT_BORDER){
        const int N = V.size();
        int maxDiff = max(V.front(), RIGHT_BORDER - V.back());
        for(int i = 1; i < N; ++i){
            maxDiff = max(V[i] - V[i - 1], maxDiff);
        }
        return maxDiff;
    }
    
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int MODULO = 1e9 + 7;
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int maxHeight = computeMaxDiff(horizontalCuts, h);
        int maxWidth = computeMaxDiff(verticalCuts, w);
        
        return (1LL * maxHeight * maxWidth) % MODULO;
    }
};