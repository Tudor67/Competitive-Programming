class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return -1;
        }

        vector<int> v = nums;
        for(int i = 0; i < 2; ++i){
            for(int j = i + 1; j < N; ++j){
                if(v[i] > v[j]){
                    swap(v[i], v[j]);
                }
            }
        }

        return v[1];
    }
};