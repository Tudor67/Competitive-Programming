class Solution {
private:
    int min_moves(const vector<int>& NUMS, const int& START_IDX){
        const int N = NUMS.size();
        int moves = 0;
        for(int i = START_IDX; i < N; i += 2){
            int left_num = (i > 0 ? NUMS[i - 1] : 1e9);
            int right_num = (i < N - 1 ? NUMS[i + 1] : 1e9);
            int line = min(left_num, right_num);
            if(NUMS[i] >= line){
                moves += (NUMS[i] - line + 1);
            }
        }
        return moves;
    }
    
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int moves0 = min_moves(nums, 0);
        int moves1 = min_moves(nums, 1);
        return min(moves0, moves1);
    }
};