class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long res = 0;
        
        map<int, int> prevCount;
        map<int, int> currCount;

        for(int num: nums){
            currCount.clear();
            currCount[num] += 1;
            for(auto& [subarrayAND, c]: prevCount){
                currCount[subarrayAND & num] += c;
            }
            res += currCount[k];
            prevCount = currCount;
        }

        return res;
    }
};