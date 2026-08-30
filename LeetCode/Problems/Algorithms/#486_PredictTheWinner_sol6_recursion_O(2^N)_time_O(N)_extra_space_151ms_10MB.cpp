class Solution {
private:
    int f(int l, int r, vector<int>& nums){
        if(l > r){
            return 0;
        }
        return max(nums[l] - f(l + 1, r, nums),
                   nums[r] - f(l, r - 1, nums));
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        return (f(0, (int)nums.size() - 1, nums) >= 0);
    }
};