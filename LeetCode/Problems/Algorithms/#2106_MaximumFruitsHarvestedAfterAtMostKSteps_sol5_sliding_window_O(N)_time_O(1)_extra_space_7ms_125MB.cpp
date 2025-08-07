class Solution {
private:
    int computeMinSteps(int l, int r, int startPos){
        return r - l + min(abs(l - startPos), abs(r - startPos));
    }

public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        const int N = fruits.size();

        int res = 0;
        int wSum = 0;
        int r = 0;
        for(int l = 0; l < N; ++l){
            if(abs(fruits[l][0] - startPos) <= k){
                r = max(r, l);
                while(r < N && computeMinSteps(fruits[l][0], fruits[r][0], startPos) <= k){
                    wSum += fruits[r][1];
                    r += 1;
                }
                res = max(res, wSum);
                wSum -= fruits[l][1];
            }
        }

        return res;
    }
};