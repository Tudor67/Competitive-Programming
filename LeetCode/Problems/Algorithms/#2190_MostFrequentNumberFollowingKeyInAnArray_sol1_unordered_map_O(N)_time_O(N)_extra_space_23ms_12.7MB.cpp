class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int i = 0; i + 1 < N; ++i){
            if(nums[i] == key){
                count[nums[i + 1]] += 1;
            }
        }
        
        int res = 0;
        int resFreq = 0;
        for(const pair<int, int>& P: count){
            int num = P.first;
            int numFreq = P.second;
            if(numFreq > resFreq){
                res = num;
                resFreq = numFreq;
            }
        }
        
        return res;
    }
};