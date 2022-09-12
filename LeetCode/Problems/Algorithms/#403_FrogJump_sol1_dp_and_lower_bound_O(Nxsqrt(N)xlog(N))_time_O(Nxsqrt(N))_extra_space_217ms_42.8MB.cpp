class Solution {
public:
    bool canCross(vector<int>& stones) {
        const int N = stones.size();
        
        if(stones[1] != 1){
            return false;
        }
        
        unordered_set<int> jumpSizesAt[N];
        jumpSizesAt[1] = {1, 2};
        
        for(int i = 1; i < N - 1 && jumpSizesAt[N - 1].empty(); ++i){
            int currentPos = stones[i];
            for(int jumpSize: jumpSizesAt[i]){
                int nextPos = currentPos + jumpSize;
                int j = lower_bound(stones.begin() + i, stones.end(), nextPos) - stones.begin();
                if(j < N && stones[j] == nextPos){
                    jumpSizesAt[j].insert(jumpSize);
                    jumpSizesAt[j].insert(jumpSize + 1);
                    if(jumpSize - 1 >= 1){
                        jumpSizesAt[j].insert(jumpSize - 1);
                    }
                }
            }
        }
        
        return !jumpSizesAt[N - 1].empty();
    }
};