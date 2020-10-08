class Solution {
private:
    vector<int> candidates;
    int target;
    
    void back(int currentSum, const int& START_POS, vector<int>& currentCombination,
              vector<vector<int>>& combinations){
        if(currentSum == target){
            combinations.push_back(currentCombination);
        }else{
            for(int i = START_POS; i < candidates.size(); ++i){
                if(i > START_POS && candidates[i - 1] == candidates[i]){
                    // avoid duplicates
                    continue;
                }
                if(currentSum + candidates[i] > target){
                    // no valid combinations with the current prefix
                    break;
                }
                currentCombination.push_back(candidates[i]);
                back(currentSum + candidates[i], i, currentCombination, combinations);
                currentCombination.pop_back();
            }
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->candidates = candidates;
        this->target = target;
        sort(this->candidates.begin(), this->candidates.end());
        
        vector<vector<int>> combinations;
        vector<int> currentCombination;
        back(0, 0, currentCombination, combinations);
        
        return combinations;
    }
};