class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return -1;
        }

        vector<int> v = nums;
        nth_element(v.begin(), v.begin() + 1, v.end());

        return v[1];
    }
};