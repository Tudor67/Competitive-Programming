class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        const int N = nums.size();

        vector<int> res;
        for(int num: nums){
            string numStr = to_string(num);
            for(char c: numStr){
                res.push_back(c - '0');
            }
        }

        return res;
    }
};