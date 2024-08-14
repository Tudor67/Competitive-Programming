class Solution {
private:
    void back(int remSum, int startIndex, vector<int>& sortedCandidates,
              vector<int>& currentCombination, vector<vector<int>>& combinations){
        if(remSum == 0){
            combinations.push_back(currentCombination);
        }else if(remSum > 0){
            for(int i = startIndex; i < (int)sortedCandidates.size(); ++i){
                if(i == startIndex || sortedCandidates[i - 1] != sortedCandidates[i]){
                    currentCombination.push_back(sortedCandidates[i]);
                    back(remSum - sortedCandidates[i], i + 1, sortedCandidates, currentCombination, combinations);
                    currentCombination.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> sortedCandidates = candidates;
        sort(sortedCandidates.begin(), sortedCandidates.end());

        vector<int> currentCombination;
        vector<vector<int>> combinations;
        back(target, 0, sortedCandidates, currentCombination, combinations);
        
        return combinations;
    }
};