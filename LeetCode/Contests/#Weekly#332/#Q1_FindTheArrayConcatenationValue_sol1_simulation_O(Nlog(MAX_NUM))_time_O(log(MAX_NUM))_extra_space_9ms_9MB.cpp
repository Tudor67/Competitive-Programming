class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        const int N = nums.size();
        
        long long res = 0;
        for(int i = 0, j = N - 1; i <= j; ++i, --j){
            string s = to_string(nums[i]);
            if(i != j){
                s += to_string(nums[j]);
            }
            res += stoi(s);
        }
        
        return res;
    }
};