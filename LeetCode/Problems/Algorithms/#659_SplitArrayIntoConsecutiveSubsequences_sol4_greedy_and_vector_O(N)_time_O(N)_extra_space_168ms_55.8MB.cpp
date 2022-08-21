class Solution {
public:
    bool isPossible(vector<int>& nums) {
        const int N = nums.size();
        
        vector<pair<int, int>> numCountVector;
        int count = 1;
        for(int i = 1; i <= N; ++i){
            if(i < N && nums[i - 1] == nums[i]){
                count += 1;
            }else{
                numCountVector.emplace_back(nums[i - 1], count);
                count = 1;
            }
        }
        
        bool isPossible = true;
        int startIdx = 0;
        while(isPossible && startIdx < (int)numCountVector.size()){
            int prevNum = numCountVector[startIdx].first - 1;
            int prevCount = 0;
            int len = 0;
            
            int idx = startIdx;
            while(idx < (int)numCountVector.size()){
                int num = numCountVector[idx].first;
                int count = numCountVector[idx].second;
                if(prevNum + 1 == num && prevCount <= count){
                    numCountVector[idx].second -= 1;
                    if(numCountVector[idx].second == 0){
                        startIdx += 1;
                    }
                    len += 1;
                    prevNum = num;
                    prevCount = count;
                    idx += 1;
                }else{
                    break;
                }
            }
            
            if(len < 3){
                isPossible = false;
            }
        }
        
        return isPossible;
    }
};