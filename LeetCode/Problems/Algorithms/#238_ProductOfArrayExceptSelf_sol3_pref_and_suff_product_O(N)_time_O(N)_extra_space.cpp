class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> suffixProduct(N);
        suffixProduct[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffixProduct[i] = nums[i] * suffixProduct[i + 1];
        }
        
        vector<int> answer(N);
        int prefixProduct = 1;
        for(int i = 0; i < N - 1; ++i){
            answer[i] = prefixProduct * suffixProduct[i + 1];
            prefixProduct *= nums[i];
        }
        answer[N - 1] = prefixProduct;
        
        return answer;
    }
};