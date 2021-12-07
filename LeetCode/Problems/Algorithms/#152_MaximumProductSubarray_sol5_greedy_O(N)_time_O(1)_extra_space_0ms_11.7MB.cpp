class Solution {
private:
    int maxPrefProdOfNonZeroSubarray(vector<int>& nums){
        int answer = *max_element(nums.begin(), nums.end());
        int maxPrefProd = 1;
        for(int num: nums){
            if(num == 0){
                maxPrefProd = 1;
            }else{
                maxPrefProd *= num;
                answer = max(answer, maxPrefProd);
            }
        }
        return answer;
    }
    
public:
    int maxProduct(vector<int>& nums) {
        reverse(nums.begin(), nums.end());
        int maxSuffProd = maxPrefProdOfNonZeroSubarray(nums);
        
        reverse(nums.begin(), nums.end());
        int maxPrefProd = maxPrefProdOfNonZeroSubarray(nums);
        
        return max({maxPrefProd, maxSuffProd});
    }
};