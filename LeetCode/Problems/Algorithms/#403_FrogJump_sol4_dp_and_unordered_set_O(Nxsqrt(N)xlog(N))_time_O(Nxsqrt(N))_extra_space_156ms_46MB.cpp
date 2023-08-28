class Solution {
public:
    bool canCross(vector<int>& stones) {
        const int N = stones.size();

        vector<unordered_set<int>> jumpSizesAt(N);
        jumpSizesAt[0] = {1};
        for(int i = 0; i < N && jumpSizesAt[N - 1].empty(); ++i){
            int currentPos = stones[i];
            for(int jumpSize: jumpSizesAt[i]){
                int nextPos = currentPos + jumpSize;
                int j = lower_bound(stones.begin() + i + 1, stones.end(), nextPos) - stones.begin();
                if(j < N && stones[j] == nextPos){
                    jumpSizesAt[j].insert(jumpSize - 1);
                    jumpSizesAt[j].insert(jumpSize);
                    jumpSizesAt[j].insert(jumpSize + 1);
                }
            }
        }

        return !jumpSizesAt[N - 1].empty();
    }
};