class Solution {
private:
    int computeMaxConsecutiveBars(vector<int> v){
        const int N = v.size();

        sort(v.begin(), v.end());

        int maxConsecutiveBars = 0;
        int consecutiveBars = 0;
        for(int i = 0; i < N; ++i){
            if(i == 0 || v[i - 1] + 1 == v[i]){
                consecutiveBars += 1;
            }else{
                consecutiveBars = 1;
            }
            maxConsecutiveBars = max(maxConsecutiveBars, consecutiveBars);
        }

        return maxConsecutiveBars;
    }

public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int h = 1 + computeMaxConsecutiveBars(hBars);
        int w = 1 + computeMaxConsecutiveBars(vBars);
        int x = min(h, w);
        return x * x;
    }
};