class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int N = nums.size();

        vector<int> v = nums;
        for(int i = 0; i < 2; ++i){
            for(int j = i + 1; j < N; ++j){
                if(v[i] < v[j]){
                    swap(v[i], v[j]);
                }
            }
        }

        return (v[0] - 1) * (v[1] - 1);
    }
};