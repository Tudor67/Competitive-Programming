class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int answer = nums[0];
        int prevMaxPosProd = 1;
        int maxPosProd = 1;
        int minNegProd = 1;
        for(int num: nums){
            prevMaxPosProd = maxPosProd;
            maxPosProd = max({num, num * maxPosProd, num * minNegProd});
            minNegProd = min({num, num * prevMaxPosProd, num * minNegProd});
            answer = max(maxPosProd, answer);
        }
        return answer;
    }
};