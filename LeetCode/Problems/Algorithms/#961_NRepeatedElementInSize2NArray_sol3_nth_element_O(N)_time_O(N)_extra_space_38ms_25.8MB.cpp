class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int N = nums.size() / 2;
        
        vector<int> v = nums;
        nth_element(v.begin(), v.begin() + N - 1, v.end());
        nth_element(v.begin(), v.begin() + N, v.end());
        
        if(count(v.begin(), v.end(), v[N - 1]) == N){
            return v[N - 1];
        }
        
        return v[N];
    }
};