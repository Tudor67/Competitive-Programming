class Solution {
private:
    void addWeight(vector<vector<int>>& items, vector<int>& weightSumOf){
        for(const vector<int>& ITEM: items){
            int value = ITEM[0];
            int weight = ITEM[1];
            weightSumOf[value] += weight;
        }
    }
    
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int maxValue = max(*max_element(items1.begin(), items1.end()),
                           *max_element(items2.begin(), items2.end()))[0];
        
        vector<int> weightSumOf(maxValue + 1);
        addWeight(items1, weightSumOf);
        addWeight(items2, weightSumOf);
        
        vector<vector<int>> res;
        for(int value = 0; value <= maxValue; ++value){
            if(weightSumOf[value] > 0){
                res.push_back({value, weightSumOf[value]});
            }
        }
        
        return res;
    }
};