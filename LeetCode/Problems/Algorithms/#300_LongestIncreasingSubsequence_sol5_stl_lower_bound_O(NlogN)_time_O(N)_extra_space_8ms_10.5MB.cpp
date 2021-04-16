class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int N = nums.size();
        const int INF = INT_MAX;
        vector<int> v(N, INF);
        for(int num: nums){
            int pos = lower_bound(v.begin(), v.end(), num) - v.begin();
            v[pos] = num;
        }
        int answer = lower_bound(v.begin(), v.end(), INF) - v.begin();
        return answer;
    }
};