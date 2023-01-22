class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        unordered_set<int> primesSet;

        for(int num: nums){
            for(int i = 2; i * i <= num; ++i){
                while(num % i == 0){
                    num /= i;
                    primesSet.insert(i);
                }
            }
            if(num > 1){
                primesSet.insert(num);
            }
        }

        return primesSet.size();
    }
};