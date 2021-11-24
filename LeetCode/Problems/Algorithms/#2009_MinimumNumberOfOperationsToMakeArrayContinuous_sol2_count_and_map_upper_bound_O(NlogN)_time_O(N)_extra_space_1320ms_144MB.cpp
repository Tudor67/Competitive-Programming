class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();
        
        // we don't need duplicates of a number
        set<int> numsSet(nums.begin(), nums.end());
        
        map<int, int> prefCount;
        int prefSumOfCount = 0;
        for(int num: numsSet){
            prefSumOfCount += 1;
            prefCount[num] = prefSumOfCount;
        }
        
        int answer = N - 1;
        for(int num: numsSet){
            int maxNum = num;
            int minNum = maxNum - N + 1;
            int prefCountMinNum = 0;
            auto it = prefCount.upper_bound(minNum - 1);
            if(it != prefCount.begin()){
                it = prev(it);
                prefCountMinNum = it->second;
            }
            int weHave = prefCount[maxNum] - prefCountMinNum;
            int cost = N - weHave;
            answer = min(answer, cost);
        }
        
        return answer;
    }
};