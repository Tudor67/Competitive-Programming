class Solution {
public:
    bool isPossible(vector<int>& nums) {
        const int N = nums.size();
        
        vector<pair<int, int>> numCnt;
        int cnt = 1;
        for(int i = 1; i < N; ++i){
            if(nums[i - 1] == nums[i]){
                cnt += 1;
            }else{
                numCnt.push_back({nums[i - 1], cnt});
                cnt = 1;
            }
        }
        numCnt.push_back({nums[N - 1], cnt});
        
        int currentSize = numCnt.size();
        while(currentSize >= 1){
            int i = currentSize - 1;
            while(i >= 1){
                if(numCnt[i - 1].first + 1 == numCnt[i].first &&
                   numCnt[i - 1].second >= numCnt[i].second &&
                   numCnt[i - 1].second >= 1 && numCnt[i].second >= 1){
                    i -= 1;
                }else{
                    break;
                }
            }
            
            if(currentSize - i >= 3){
                for(int j = i; j < currentSize; ++j){
                    numCnt[j].second -= 1;
                }
                while(currentSize >= 1 && numCnt[currentSize - 1].second == 0){
                    currentSize -= 1;
                }
            }else{
                return false;
            }
        }
        
        return true;
    }
};