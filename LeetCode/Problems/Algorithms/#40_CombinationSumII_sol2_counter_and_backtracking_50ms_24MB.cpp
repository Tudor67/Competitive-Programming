class Solution {
private:
    void back(int remSum, map<int, int>& freq, vector<int>& currentCombination, vector<vector<int>>& combinations){
        if(remSum == 0){
            combinations.push_back(currentCombination);
        }else if(remSum > 0 && !freq.empty()){
            pair<int, int> p = *freq.begin();
            freq.erase(freq.begin());

            int num = p.first;
            int numFreq = p.second;
            for(int f = 0; f <= numFreq; ++f){
                currentCombination.resize((int)currentCombination.size() + f, num);
                back(remSum - f * num, freq, currentCombination, combinations);
                currentCombination.resize((int)currentCombination.size() - f);
            }

            freq.insert(p);
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        map<int, int> freq;
        for(int num: candidates){
            freq[num] += 1;
        }

        vector<int> currentCombination;
        vector<vector<int>> combinations;
        back(target, freq, currentCombination, combinations);

        return combinations;
    }
};