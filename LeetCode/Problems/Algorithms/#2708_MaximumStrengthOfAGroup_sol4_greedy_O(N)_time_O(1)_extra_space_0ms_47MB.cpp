class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        const long long INF = 1e15;

        // Main idea: compute the product of all positive nums (posProd)
        //            compute the product of all negative nums (negProd)
        //            if we have an odd number of negative nums remove the maxNegNum from negProd
        //            try to combine posProd with (negProd / maxNegNum) to maximize the result
        long long posProd = 1;
        long long negProd = 1;
        long long maxNegNum = -INF;
        int posCount = 0;
        int negCount = 0;
        for(long long num: nums){
            if(num < 0){
                negProd *= num;
                maxNegNum = max(maxNegNum, num);
                negCount += 1;
            }else if(num > 0){
                posProd *= num;
                posCount += 1;
            }
        }

        long long res = MAX_NUM;
        if(negCount >= 2){
            res = max({res, posProd * max(negProd, negProd / maxNegNum)});
        }else if(posCount >= 1){
            res = max(res, posProd);
        }

        return res;
    }
};