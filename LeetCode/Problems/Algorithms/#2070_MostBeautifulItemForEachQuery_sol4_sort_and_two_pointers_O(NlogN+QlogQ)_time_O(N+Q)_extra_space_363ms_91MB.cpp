class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int N = items.size();
        const int Q = queries.size();
        
        vector<pair<int, int>> sortedPriceBeauty(N);
        vector<pair<int, int>> sortedQueryIdx(Q);
        
        for(int i = 0; i < N; ++i){
            sortedPriceBeauty[i] = {items[i][0], items[i][1]};
        }
        
        for(int j = 0; j < Q; ++j){
            sortedQueryIdx[j] = {queries[j], j};
        }
        
        sort(sortedPriceBeauty.begin(), sortedPriceBeauty.end());
        sort(sortedQueryIdx.begin(), sortedQueryIdx.end());
        
        vector<int> answer(Q);
        int i = 0;
        int maxBeauty = 0;
        for(const pair<int, int>& QI: sortedQueryIdx){
            int query = QI.first;
            int queryIdx = QI.second;
            while(i < N && sortedPriceBeauty[i].first <= query){
                maxBeauty = max(maxBeauty, sortedPriceBeauty[i].second);
                i += 1;
            }
            answer[queryIdx] = maxBeauty;
        }
        
        return answer;
    }
};