class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> answer(N);
        answer[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            answer[i] = nums[i] * answer[i + 1];
        }
        
        int prefixProduct = 1;
        for(int i = 0; i < N - 1; ++i){
            answer[i] = prefixProduct * answer[i + 1];
            prefixProduct *= nums[i];
        }
        answer[N - 1] = prefixProduct;
        
        return answer;
    }
};