class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;
        res.reserve(N);
        for(int parity = 0; parity <= 1; ++parity){
            for(int num: nums){
                if(num % 2 == parity){
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};