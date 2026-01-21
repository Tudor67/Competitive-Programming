class Solution {
private:
    int computeMaxGap(vector<int> v){
        const int N = v.size();

        sort(v.begin(), v.end());

        int maxGap = 0;
        int l = 0;
        while(l < N){
            int r = l;
            while(r + 1 < N && v[r] + 1 == v[r + 1]){
                r += 1;
            }
            maxGap = max(maxGap, r - l + 2);
            l = r + 1;
        }

        return maxGap;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxHGap = computeMaxGap(hBars);
        int maxVGap = computeMaxGap(vBars);
        int gap = min(maxHGap, maxVGap);
        return (gap * gap);
    }
};