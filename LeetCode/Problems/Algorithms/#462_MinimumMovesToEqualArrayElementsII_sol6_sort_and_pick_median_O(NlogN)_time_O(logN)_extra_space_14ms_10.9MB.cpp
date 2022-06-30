class Solution {
public:
    int minMoves2(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int median = nums[N / 2];
        
        int minMoves = 0;
        for(int num: nums){
            minMoves += abs(num - median);
        }
        
        return minMoves;
    }
};