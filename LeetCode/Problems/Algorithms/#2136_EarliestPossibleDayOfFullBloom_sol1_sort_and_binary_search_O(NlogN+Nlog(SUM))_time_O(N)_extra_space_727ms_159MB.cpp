class Solution {
private:
    bool isPossible(vector<pair<int, int>>& sortedPlantAndGrowTimes, int timeLimit){
        int leftPlantTime = timeLimit - sortedPlantAndGrowTimes[0].second;
        
        for(const pair<int, int>& P: sortedPlantAndGrowTimes){
            int plantTime = P.first;
            int growTime = P.second;
            
            leftPlantTime = min(leftPlantTime - plantTime, timeLimit - growTime - plantTime);
            
            if(leftPlantTime < 0){
                return false;
            }
        }
        
        return true;
    }
    
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        const int N = plantTime.size();
        
        // Step 1: sort
        vector<pair<int, int>> sortedPlantAndGrowTimes(N);
        for(int i = 0; i < N; ++i){
            sortedPlantAndGrowTimes[i] = {plantTime[i], growTime[i]};
        }
        
        sort(sortedPlantAndGrowTimes.begin(), sortedPlantAndGrowTimes.end(),
             [](const pair<int, int>& LHS, const pair<int, int>& RHS){
                 int lhsPlantTime = LHS.first;
                 int lhsGrowTime = LHS.second;
                 int rhsPlantTime = RHS.first;
                 int rhsGrowTime = RHS.second;
                 return (lhsGrowTime < rhsGrowTime) ||
                        (lhsGrowTime == rhsGrowTime && lhsPlantTime < rhsPlantTime);
             });
        
        // Step 2: binary search
        int l = 0;
        int r = accumulate(plantTime.begin(), plantTime.end(), 0) +
                accumulate(growTime.begin(), growTime.end(), 0);
        while(l != r){
            int mid = l + (r - l) / 2;
            if(isPossible(sortedPlantAndGrowTimes, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};