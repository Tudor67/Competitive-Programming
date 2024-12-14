class Solution {
private:
    bool isSmallest(vector<int>& nums, int i, vector<bool>& isMarked){
        if(i - 1 >= 0 && !isMarked[i - 1] && nums[i - 1] < nums[i]){
            return false;
        }
        if(i + 1 < (int)nums.size() && !isMarked[i + 1] && nums[i] > nums[i + 1]){
            return false;
        }
        return true;
    }

public:
    long long findScore(vector<int>& nums) {
        const int N = nums.size();

        long long score = 0;
        vector<bool> isMarked(N, false);

        for(auto [start, end, direction]: vector<array<int, 3>>{{0, N, 1}, {N - 1, -1, -1}}){
            for(int i = start; i != end; i += direction){
                if(!isMarked[i] && isSmallest(nums, i, isMarked)){
                    isMarked[max(0, i - 1)] = true;
                    isMarked[i] = true;
                    isMarked[min(i + 1, N - 1)] = true;
                    score += nums[i];
                }
            }
        }

        return score;
    }
};