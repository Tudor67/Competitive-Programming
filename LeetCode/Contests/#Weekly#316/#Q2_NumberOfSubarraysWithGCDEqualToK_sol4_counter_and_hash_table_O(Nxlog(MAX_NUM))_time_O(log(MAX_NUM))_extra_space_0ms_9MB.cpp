class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        const int N = nums.size();
        
        int res = 0;
        unordered_map<int, int> prevCount;
        unordered_map<int, int> count;
        for(int i = 0; i < N; ++i){
            count.clear();
            if(nums[i] % k == 0){
                count[nums[i]] = 1;
                for(const pair<int, int>& P: prevCount){
                    int prevGCD = P.first;
                    int prevGCDCount = P.second;
                    int currentGCD = gcd(prevGCD, nums[i]);
                    count[currentGCD] += prevGCDCount;
                }
                res += count[k];
            }
            prevCount = count;
        }
        
        return res;
    }
};