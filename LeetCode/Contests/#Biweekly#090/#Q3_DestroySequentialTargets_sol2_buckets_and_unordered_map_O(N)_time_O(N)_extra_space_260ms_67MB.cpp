class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        unordered_map<int, int> minStart;
        for(int num: nums){
            int bucket = num % space;
            count[bucket] += 1;
            if(minStart.count(bucket)){
                minStart[bucket] = min(minStart[bucket], num);
            }else{
                minStart[bucket] = num;
            }
        }
        
        int bucket = nums[0] % space;
        int resCount = count[bucket];
        int resStart = minStart[bucket];
        
        for(const pair<int, int>& P: count){
            int num = P.first;
            int bucket = num % space;
            if(resCount < count[bucket]){
                resCount = count[bucket];
                resStart = minStart[bucket];
            }else if(resCount == count[bucket]){
                resStart = min(resStart, minStart[bucket]);
            }
        }
        
        return resStart;
    }
};