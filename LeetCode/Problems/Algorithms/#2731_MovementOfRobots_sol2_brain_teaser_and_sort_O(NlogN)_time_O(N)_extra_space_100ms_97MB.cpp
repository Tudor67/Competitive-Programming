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
        for(int i = 0; i < N; ++i){
            long long l = i;           // v[i] - v[0], v[i] - v[1], ..., v[i] - v[i - 1]
            long long r = N - (i + 1); // v[i + 1] - v[i], v[i + 2] - v[i], ..., v[N - 1] - v[i]
            long long contrib = (v[i] - v[0]) * (l - r) % MODULO;
            res = (res + contrib) % MODULO;
        }
        
        return res;
    }
};