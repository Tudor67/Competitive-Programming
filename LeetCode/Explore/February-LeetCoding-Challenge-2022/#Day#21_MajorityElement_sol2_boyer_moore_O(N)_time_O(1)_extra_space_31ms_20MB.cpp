class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();
        
        int candidate = nums[0];
        int candidateBal = 0;
        for(int num: nums){
            if(num == candidate){
                candidateBal += 1;
            }else{
                candidateBal -= 1;
            }
            if(candidateBal == -1){
                candidate = num;
                candidateBal = 1;
            }
        }
        
        int candidateCount = count(nums.begin(), nums.end(), candidate);
        if(candidateCount > N / 2){
            return candidate;
        }
        
        return INT_MIN;
    }
};