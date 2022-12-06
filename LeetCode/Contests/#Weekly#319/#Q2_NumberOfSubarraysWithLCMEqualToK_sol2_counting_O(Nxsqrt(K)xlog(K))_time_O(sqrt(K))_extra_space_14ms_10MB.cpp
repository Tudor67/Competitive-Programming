class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int res = 0;
        unordered_map<int, int> prevCount;
        unordered_map<int, int> count;
        
        for(int i = 0; i < N; ++i){
            if(k % nums[i] == 0){
                count[nums[i]] = 1;
                for(const pair<int, int>& P: prevCount){
                    int prevLCM = P.first;
                    int prevLCMCount = P.second;
                    int currentLCM = lcm(prevLCM, nums[i]);
                    if(currentLCM <= k){
                        count[currentLCM] += prevLCMCount;
                    }
                }
                res += count[k];
            }
            prevCount = count;
            count.clear();
        }
        
        return res;
    }
};