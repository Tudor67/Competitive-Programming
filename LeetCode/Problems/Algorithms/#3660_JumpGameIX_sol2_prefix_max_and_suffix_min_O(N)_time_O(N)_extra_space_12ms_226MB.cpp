class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        const int N = nums.size();

        vector<int> prefMax(N);
        prefMax[0] = nums[0];
        for(int i = 1; i < N; ++i){
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        vector<int> suffMin(N);
        suffMin[N - 1] = nums[N - 1];
        for(int i = N - 2; i >= 0; --i){
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }

        vector<int> res(N);
        res[N - 1] = prefMax[N - 1];
        for(int i = N - 2; i >= 0; --i){
            if(prefMax[i] > suffMin[i + 1]){
                res[i] = res[i + 1];
            }else{
                res[i] = prefMax[i];
            }
        }

        return res;
    }
};