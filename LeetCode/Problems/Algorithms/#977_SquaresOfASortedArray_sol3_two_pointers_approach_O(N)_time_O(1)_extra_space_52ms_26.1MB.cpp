class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const int N = nums.size();
        
        int l = -1;
        int r = 0;
        while(r < N && nums[r] < 0){
            r += 1;
            l = r - 1;
        }
        
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            if(0 <= l && r < N){
                if(-nums[l] <= nums[r]){
                    answer[i] = nums[l] * nums[l];
                    l -= 1;
                }else{
                    answer[i] = nums[r] * nums[r];
                    r += 1;
                }
            }else{
                if(0 <= l){
                    answer[i] = nums[l] * nums[l];
                    l -= 1;
                }else{
                    answer[i] = nums[r] * nums[r];
                    r += 1;
                }
            }
        }
        
        return answer;
    }
};