class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int N = items.size();
        const int Q = queries.size();
        
        vector<pair<int, int>> sortedItems(N);
        for(int i = 0; i < N; ++i){
            sortedItems[i] = {items[i][0], items[i][1]};
        }
        
        sort(sortedItems.begin(), sortedItems.end());
        
        for(int i = 1; i < N; ++i){
            sortedItems[i].second = max(sortedItems[i - 1].second, sortedItems[i].second);
        }
        
        vector<int> answer(Q);
        for(int j = 0; j < Q; ++j){
            auto it = upper_bound(sortedItems.begin(), sortedItems.end(), make_pair(queries[j], INT_MAX));
            if(it != sortedItems.begin()){
                answer[j] = prev(it)->second;
            }
        }
        
        return answer;
    }
};