class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        const int N = nums.size();
        const int INF = 1e9;

        int minLen = INF;
        vector<pair<long long, int>> st;
        st.push_back({0, -1});

        long long prefSum = 0;
        for(int i = 0; i < N; ++i){
            prefSum += nums[i];
            while(!st.empty() && st.back().first >= prefSum){
                st.pop_back();
            }
            
            st.push_back({prefSum, i});

            auto it = upper_bound(st.begin(), st.end(), pair<long long, int>{prefSum - k, INF});
            if(it != st.begin()){
                int len = i - prev(it)->second;
                minLen = min(minLen, len);
            }
        }

        if(minLen == INF){
            minLen = -1;
        }

        return minLen;
    }
};