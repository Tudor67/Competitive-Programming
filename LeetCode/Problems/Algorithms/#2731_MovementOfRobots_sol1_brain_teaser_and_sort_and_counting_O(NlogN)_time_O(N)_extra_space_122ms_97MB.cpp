class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        const int N = nums.size();
        const int MODULO = 1e9 + 7;
        
        vector<long long> v(N);
        for(int i = 0; i < N; ++i){
            if(s[i] == 'L'){
                v[i] = nums[i] - (long long)d;
            }else{
                v[i] = nums[i] + (long long)d;
            }
        }
        
        sort(v.begin(), v.end());

        long long res = 0;
        for(int i = 1; i < N; ++i){
            long long lCount = i;
            long long rCount = N - lCount;
            long long segmentLength = v[i] - v[i - 1];
            long long contrib = ((lCount * rCount) % MODULO) * segmentLength % MODULO;
            res = (res + contrib) % MODULO;
        }
        
        return res;
    }
};