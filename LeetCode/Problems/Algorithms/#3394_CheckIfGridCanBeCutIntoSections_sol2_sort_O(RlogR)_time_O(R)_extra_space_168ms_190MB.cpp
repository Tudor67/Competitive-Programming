class Solution {
private:
    bool checkValidCuts(vector<vector<int>>& rectangles, int dim){
        vector<int> p(rectangles.size());
        iota(p.begin(), p.end(), 0);
        sort(p.begin(), p.end(),
             [&](int lhs, int rhs){
                return (rectangles[lhs][dim] < rectangles[rhs][dim]);
             });

        const int INF = 2e9;
        int validCutsCount = 0;
        int maxEndPos = -INF;
        for(int i: p){
            int startPos = rectangles[i][dim];
            int endPos = rectangles[i][dim + 2];
            if(maxEndPos != -INF && maxEndPos <= startPos){
                validCutsCount += 1;
            }
            maxEndPos = max(maxEndPos, endPos);
        }

        return (validCutsCount >= 2);
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return (checkValidCuts(rectangles, 0) ||
                checkValidCuts(rectangles, 1));
    }
};