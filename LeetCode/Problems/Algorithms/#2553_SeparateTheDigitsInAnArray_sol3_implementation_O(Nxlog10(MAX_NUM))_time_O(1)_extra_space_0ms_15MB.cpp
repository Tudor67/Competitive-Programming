class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;
        for(int i = N - 1; i >= 0; --i){
            int num = nums[i];
            while(num > 0){
                res.push_back(num % 10);
                num /= 10;
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};