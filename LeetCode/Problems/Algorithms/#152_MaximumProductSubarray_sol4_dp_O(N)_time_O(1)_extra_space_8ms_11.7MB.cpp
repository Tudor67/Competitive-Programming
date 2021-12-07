class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();
        
        // At step i:
        //    minProd: min product of a subarray ending with nums[i]
        //    maxProd: max product of a subarray ending with nums[i]
        //    answer: max product of a subarray of nums[0 .. i]
        int answer = nums[0];
        int minProd = nums[0];
        int maxProd = nums[0];
        for(int i = 1; i < N; ++i){
            int prevMinProd = minProd;
            minProd = min({minProd * nums[i], maxProd * nums[i], nums[i]});
            maxProd = max({prevMinProd * nums[i], maxProd * nums[i], nums[i]});
            answer = max(answer, maxProd);
        }
        
        return answer;
    }
};