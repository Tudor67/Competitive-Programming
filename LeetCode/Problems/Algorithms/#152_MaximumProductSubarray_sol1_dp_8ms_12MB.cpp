class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        int answer = nums[0];
        
        if(N > 1){
            vector<int> min_neg(N, 0);
            vector<int> max_pos(N, 0);
            
            min_neg[0] = min(0, nums[0]);
            max_pos[0] = max(0, nums[0]);
            
            for(int i = 1; i < N; ++i){
                if(nums[i] < 0){
                    min_neg[i] = min(nums[i], nums[i] * max_pos[i - 1]);
                    max_pos[i] = nums[i] * min_neg[i - 1];
                }else if(nums[i] > 0){
                    min_neg[i] = nums[i] * min_neg[i - 1];
                    max_pos[i] = max(nums[i], nums[i] * max_pos[i - 1]);
                }
            }
            
            answer = *max_element(max_pos.begin(), max_pos.end());
        }
        
        return answer;
    }
};