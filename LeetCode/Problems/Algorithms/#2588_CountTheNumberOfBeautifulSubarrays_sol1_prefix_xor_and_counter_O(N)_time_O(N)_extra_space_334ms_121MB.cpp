class Solution {
public:
    long long beautifulSubarrays(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        count[0] = 1;
        
        long long res = 0;
        int prefXOR = 0;
        for(int num: nums){
            prefXOR ^= num;
            res += count[prefXOR];
            count[prefXOR] += 1;
        }
        
        return res;
    }
};