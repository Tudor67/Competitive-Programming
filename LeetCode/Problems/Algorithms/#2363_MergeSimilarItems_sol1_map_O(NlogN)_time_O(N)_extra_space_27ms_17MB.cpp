class Solution {
private:
    void addWeight(vector<vector<int>>& items, map<int, int>& weightSumOf){
        for(const vector<int>& ITEM: items){
            int value = ITEM[0];
            int weight = ITEM[1];
            weightSumOf[value] += weight;
        }
    }
    
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> weightSumOf;
        addWeight(items1, weightSumOf);
        addWeight(items2, weightSumOf);
        
        vector<vector<int>> res;
        for(const pair<int, int>& P: weightSumOf){
            int value = P.first;
            int weight = P.second;
            res.push_back({value, weight});
        }
        
        return res;
    }
};