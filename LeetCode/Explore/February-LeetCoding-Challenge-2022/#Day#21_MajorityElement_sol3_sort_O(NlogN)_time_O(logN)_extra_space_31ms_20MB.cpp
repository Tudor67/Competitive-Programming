class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();
        
        sort(nums.begin(), nums.end());
        
        int candidate = nums[N / 2];
        int candidateCount = count(nums.begin(), nums.end(), candidate);
        
        if(candidateCount > N / 2){
            return candidate;
        }
        
        return INT_MIN;
    }
};