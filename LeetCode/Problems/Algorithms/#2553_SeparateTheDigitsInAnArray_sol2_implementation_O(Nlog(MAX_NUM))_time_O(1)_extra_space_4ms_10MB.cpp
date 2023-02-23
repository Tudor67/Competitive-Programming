class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;
        for(int i = N - 1; i >= 0; --i){
            for(int x = nums[i]; x > 0; x /= 10){
                res.push_back(x % 10);
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};