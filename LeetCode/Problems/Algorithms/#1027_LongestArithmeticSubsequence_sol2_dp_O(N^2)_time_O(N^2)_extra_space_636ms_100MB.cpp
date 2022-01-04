class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        unordered_map<int, int> count;
        unordered_set<int> vis;
        int maxCount = 1;
        for(int currentNum: nums){
            for(int previousNum: vis){
                int diff = currentNum - previousNum + MAX_NUM;
                int currentState = (currentNum << 12) | diff;
                int previousState = (previousNum << 12) | diff;
                if(count.count(previousState)){
                    count[currentState] = 1 + count[previousState];
                }else{
                    count[currentState] = 2;
                }
                maxCount = max(maxCount, count[currentState]);
            }
            vis.insert(currentNum);
        }
        
        return maxCount;
    }
};