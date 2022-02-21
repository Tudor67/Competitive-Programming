class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        const int N = nums.size();
        
        multiset<pair<int, int>> pSet;
        for(int i = 0; i < N; ++i){
            if(nums[i] % 2 == 0){
                int maxNum = nums[i];
                int minNum = nums[i];
                while(minNum % 2 == 0){
                    minNum /= 2;
                }
                pSet.emplace(minNum, maxNum);
            }else{
                pSet.emplace(nums[i], 2 * nums[i]);
            }
        }
        
        int minDiff = prev(pSet.end())->first - pSet.begin()->first;
        while((int)pSet.size() == N && minDiff > 0){
            int diff = prev(pSet.end())->first - pSet.begin()->first;
            minDiff = min(minDiff, diff);
            
            int x = pSet.begin()->first;
            int y = pSet.begin()->second;
            pSet.erase(pSet.begin());
            
            if(x < y){
                pSet.emplace(2 * x, y);
            }
        }
        
        return minDiff;
    }
};