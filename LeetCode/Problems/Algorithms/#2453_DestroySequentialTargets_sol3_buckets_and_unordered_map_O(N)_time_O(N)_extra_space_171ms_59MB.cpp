class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        int maxCount = 0;
        unordered_map<int, int> count;
        for(int num: nums){
            int bucket = num % space;
            count[bucket] += 1;
            maxCount = max(maxCount, count[bucket]);
        }
        
        int resStart = MAX_NUM;
        for(int num: nums){
            int bucket = num % space;
            if(count[bucket] == maxCount){
                resStart = min(resStart, num);
            }
        }
        
        return resStart;
    }
};