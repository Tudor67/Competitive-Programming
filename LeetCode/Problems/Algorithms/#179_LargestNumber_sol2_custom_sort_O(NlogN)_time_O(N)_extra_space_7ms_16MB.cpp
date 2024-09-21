class Solution {
public:
    string largestNumber(vector<int>& nums) {
        const int N = nums.size();
        
        if(count(nums.begin(), nums.end(), 0) == N){
            return "0";
        }

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(),
             [](int lhs, int rhs){
                return (to_string(lhs) + to_string(rhs)) > (to_string(rhs) + to_string(lhs));
             });

        string res;
        for(int num: sortedNums){
            res += to_string(num);
        }

        return res;
    }
};