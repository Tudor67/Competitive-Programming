class Solution {
public:
    int maximizeWin(vector<int>& p, int k) {
        const int N = p.size();

        // Step 1: compute max prizes we can win with one segment from prefix p[0 .. j]
        vector<int> prefMax(N, 1);
        int i = 0;
        for(int j = 1; j < N; ++j){
            while(p[j] - p[i] > k){
                i += 1;
            }
            prefMax[j] = max(j - i + 1, prefMax[j - 1]);
        }

        // Step 2: compute max prizes we can win with one segment from suffix p[j .. N - 1]
        vector<int> suffMax(N, 1);
        i = N - 1;
        for(int j = N - 2; j >= 0; --j){
            while(p[i] - p[j] > k){
                i -= 1;
            }
            suffMax[j] = max(i - j + 1, suffMax[j + 1]);
        }

        // Step 3: combine one segment from prefix with one segment from suffix
        //         take the maximum combination
        int maxPrizes = prefMax[0];
        for(int j = 0; j + 1 < N; ++j){
            maxPrizes = max(maxPrizes, prefMax[j] + suffMax[j + 1]);
        }

        return maxPrizes;
    }
};