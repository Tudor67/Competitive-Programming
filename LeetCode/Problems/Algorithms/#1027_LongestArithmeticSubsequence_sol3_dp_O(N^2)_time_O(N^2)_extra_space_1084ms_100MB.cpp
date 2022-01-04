class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        unordered_map<int, int> count;
        int maxCount = 1;
        for(int i = 1; i < N; ++i){
            int currentNum = nums[i];
            bool visitedCurrentNum = false;
            for(int j = 0; j < i; ++j){
                int previousNum = nums[j];
                if(previousNum == currentNum){
                    if(visitedCurrentNum){
                        continue;
                    }
                    visitedCurrentNum = true;
                }
                int diff = currentNum - previousNum + MAX_NUM;
                int currentState = (currentNum << 12) | diff;
                int previousState = (previousNum << 12) | diff;
                if(count.count(previousState)){
                    count[currentState] = max(count[currentState], 1 + count[previousState]);
                }else{
                    count[currentState] = 2;
                }
                maxCount = max(maxCount, count[currentState]);
            }
        }
        
        return maxCount;
    }
};