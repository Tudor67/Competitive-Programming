class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        const int N = A.size();
        
        bool prevState = 0;
        bool curState = 1;
        vector<vector<int>> nums(2);
        unordered_set<int> distinctNums;
        for(int i = N - 1; i >= 0; --i){
            int curNum = A[i];
            nums[curState].clear();
            nums[curState].push_back(curNum);
            for(int prevNum: nums[prevState]){
                curNum |= prevNum;
                if(curNum != nums[curState].back()){
                    nums[curState].push_back(curNum);
                }
            }
            distinctNums.insert(nums[curState].begin(), nums[curState].end());
            swap(prevState, curState);
        }
        
        return distinctNums.size();
    }
};