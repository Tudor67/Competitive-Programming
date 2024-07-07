class Solution {
public:
    int minDifference(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 4){
            return 0;
        }

        vector<int> v = nums;
        for(int i = 0; i < 4; ++i){
            for(int j = i + 1; j < N; ++j){
                if(v[i] > v[j]){
                    swap(v[i], v[j]);
                }
            }
        }

        for(int i = N - 1; i >= N - 4; --i){
            for(int j = 0; j < i; ++j){
                if(v[i] < v[j]){
                    swap(v[i], v[j]);
                }
            }
        }

        int minDiff = v.back() - v.front();
        for(int l = 0; l <= 3; ++l){
            int r = N - 4 + l;
            minDiff = min(minDiff, v[r] - v[l]);
        }

        return minDiff;
    }
};