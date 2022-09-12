class Solution {
public:
    bool canCross(vector<int>& stones) {
        const int N = stones.size();
        
        if(stones[1] != 1){
            return false;
        }
        
        unordered_map<int, unordered_set<int>> jumpSizesAt;
        jumpSizesAt[stones[1]] = {1, 2};
        for(int i = 2; i < N; ++i){
            jumpSizesAt[stones[i]] = {};
        }
        
        for(int i = 1; i < N - 1 && jumpSizesAt[stones[N - 1]].empty(); ++i){
            int currentPos = stones[i];
            for(int jumpSize: jumpSizesAt[currentPos]){
                int nextPos = currentPos + jumpSize;
                if(jumpSizesAt.count(nextPos)){
                    jumpSizesAt[nextPos].insert(jumpSize);
                    jumpSizesAt[nextPos].insert(jumpSize + 1);
                    if(jumpSize - 1 >= 1){
                        jumpSizesAt[nextPos].insert(jumpSize - 1);
                    }
                }
            }
        }
        
        return !jumpSizesAt[stones[N - 1]].empty();
    }
};