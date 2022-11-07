class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        const int N = nums.size();
        
        vector<vector<int>> sortedNums(2);
        for(int num: nums){
            int parity = num % 2;
            sortedNums[parity].push_back(num);
        }
        
        sort(sortedNums[0].begin(), sortedNums[0].end());
        sort(sortedNums[1].begin(), sortedNums[1].end());
        
        vector<int> sortedTarget = target;
        sort(sortedTarget.begin(), sortedTarget.end());
        
        long long res = 0;
        for(int i = N - 1; i >= 0; --i){
            int parity = sortedTarget[i] % 2;
            res += max(0, (sortedNums[parity].back() - sortedTarget[i]) / 2);
            sortedNums[parity].pop_back();
        }
        
        return res;
    }
};