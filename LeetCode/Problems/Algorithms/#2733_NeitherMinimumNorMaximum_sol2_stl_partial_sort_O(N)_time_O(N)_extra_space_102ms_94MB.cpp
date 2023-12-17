class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return -1;
        }

        vector<int> v = nums;
        partial_sort(v.begin(), v.begin() + 2, v.end());

        return v[1];
    }
};