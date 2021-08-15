class Solution {
private:
    int getMaxPoints(int l, int r, int k, vector<int>& boxes, vector<vector<vector<int>>>& memo){
        // getMaxPoints(l, r, k, boxes): get max points by removing [k x boxes[l]] + boxes[l .. r]
        //                               with the mention that boxes[0 .. l - 1] are already removed
        //                               (except k boxes from boxes[0 .. l] which are equal to boxes[l])
        // So, we try to get max points by removing [k x boxes[l]] + boxes[l .. r]
        if(l > r){
            return 0;
        }
        if(l == r){
            return (k + 1) * (k + 1);
        }
        if(memo[l][r][k] != -1){
            return memo[l][r][k];
        }
        // Option 1 (remove boxes[l] together with the prefix [k x boxes[l]]):
        // (a) remove (k + 1) prefix boxes with the same value as boxes[l] (i.e., the prefix [(k + 1) x boxes[l]]);
        // (b) remove boxes[l + 1 .. r] (remember that boxes[0 .. l] are removed at this step);
        int maxPoints = (k + 1) * (k + 1) + getMaxPoints(l + 1, r, 0, boxes, memo);
        for(int m = l + 1; m <= r; ++m){
            if(boxes[l] == boxes[m]){
                // Option 2 (do not remove boxes[l] together with the prefix [k x boxes[l]]):
                // For each boxes[m] == boxes[l], with l + 1 <= m <= r:
                //   (a) remove boxes[l + 1 .. m - 1];
                //   (b) remove boxes[m .. r] knowing that we have only a prefix of (k + 1) boxes
                //                            equal to boxes[m] that are not removed yet;
                int points = getMaxPoints(l + 1, m - 1, 0, boxes, memo) + getMaxPoints(m, r, k + 1, boxes, memo);
                maxPoints = max(maxPoints, points);
            }
        }
        memo[l][r][k] = maxPoints;
        return maxPoints;
    }
    
public:
    int removeBoxes(vector<int>& boxes) {
        const int N = boxes.size();
        vector<vector<vector<int>>> memo(N, vector<vector<int>>(N, vector<int>(N, - 1)));
        return getMaxPoints(0, N - 1, 0, boxes, memo);
    }
};