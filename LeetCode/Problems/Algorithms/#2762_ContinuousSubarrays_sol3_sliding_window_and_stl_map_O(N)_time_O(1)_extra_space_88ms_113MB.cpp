class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        const int N = nums.size();

        long long res = 0;
        map<int, int> freq;
        
        int l = 0;
        for(int r = 0; r < N; ++r){
            freq[nums[r]] += 1;

            while(prev(freq.end())->first - freq.begin()->first > 2){
                freq[nums[l]] -= 1;
                if(freq[nums[l]] == 0){
                    freq.erase(nums[l]);
                }
                l += 1;
            }

            res += (r - l + 1);
        }

        return res;
    }
};