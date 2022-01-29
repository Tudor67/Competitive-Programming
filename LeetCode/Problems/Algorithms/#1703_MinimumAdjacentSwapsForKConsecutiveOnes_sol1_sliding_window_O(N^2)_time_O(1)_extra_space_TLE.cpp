class Solution {
private:
    int computeRangeMinMoves(vector<int>& nums, int l, int r, int k){
        if(r - l + 1 == k){
            return 0;
        }
        
        // range1: [l .. MID_ONE_POS]
        int leftMoves = 0;
        int leftOnes = 0;
        while(l <= r && leftOnes <= k / 2){
            leftOnes += nums[l];
            if(nums[l] == 0){
                leftMoves += leftOnes;
            }
            l += 1;
        }
        
        // range2: [MID_ONE_POS .. r]
        int rightMoves = 0;
        int rightOnes = 0;
        while(r >= l){
            rightOnes += nums[r];
            if(nums[r] == 0){
                rightMoves += rightOnes;
            }
            r -= 1;
        }
        
        return leftMoves + rightMoves;
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int answer = INT_MAX;
        int ones = 0;
        int i = 0;
        for(int j = 0; j < N; ++j){
            ones += nums[j];
            while(ones > k || nums[i] == 0){
                ones -= nums[i];
                i += 1;
            }
            if(ones == k && nums[j] == 1){
                answer = min(answer, computeRangeMinMoves(nums, i, j, k));
            }
            if(answer == 0){
                break;
            }
        }
        
        return answer;
    }
};