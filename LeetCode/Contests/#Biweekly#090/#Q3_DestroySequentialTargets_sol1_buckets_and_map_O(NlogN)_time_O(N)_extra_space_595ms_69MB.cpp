class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        const int N = nums.size();
        
        map<int, int> count;
        map<int, int> minStart;
        for(int num: nums){
            int bucket = num % space;
            count[bucket] += 1;
            if(minStart.count(bucket)){
                minStart[bucket] = min(minStart[bucket], num);
            }else{
                minStart[bucket] = num;
            }
        }
        
        int resCount = count.begin()->second;
        int resStart = minStart.begin()->second;
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