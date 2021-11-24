class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int num: nums){
            count[num] += 1;
        }
        
        int pairsCount = 0;
        for(const pair<int, int>& P: count){
            int num = P.first;
            if(count.count(num + k)){
                pairsCount += count[num] * count[num + k];
            }
        }
        
        return pairsCount;
    }
};