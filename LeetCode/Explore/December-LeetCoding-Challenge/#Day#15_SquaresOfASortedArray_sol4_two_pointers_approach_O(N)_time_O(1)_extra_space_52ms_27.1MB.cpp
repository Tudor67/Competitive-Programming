class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int N = nums.size();
        
        int splitPos = 0;
        while(splitPos < N && nums[splitPos] < 0){
            splitPos += 1;
        }
        
        vector<int> answer;
        int l = splitPos - 1;
        int r = splitPos;
        while(0 <= l && r < N){
            if(-nums[l] <= nums[r]){
                answer.push_back(nums[l] * nums[l]);
                l -= 1;
            }else{
                answer.push_back(nums[r] * nums[r]);
                r += 1;
            }
        }
        
        while(0 <= l){
            answer.push_back(nums[l] * nums[l]);
            l -= 1;
        }
        
        while(r < N){
            answer.push_back(nums[r] * nums[r]);
            r += 1;
        }
        
        return answer;
    }
};