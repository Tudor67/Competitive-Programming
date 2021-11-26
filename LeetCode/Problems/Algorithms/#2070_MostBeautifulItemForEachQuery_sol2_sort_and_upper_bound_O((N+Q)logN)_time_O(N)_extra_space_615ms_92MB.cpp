class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int N = items.size();
        const int Q = queries.size();
        
        vector<pair<int, int>> priceBeauty(N);
        for(int i = 0; i < N; ++i){
            priceBeauty[i] = {items[i][0], items[i][1]};
        }
        
        sort(priceBeauty.begin(), priceBeauty.end());
        
        vector<int> prefMaxPrice(N);
        vector<int> prefMaxBeauty(N);
        for(int i = 0; i < N; ++i){
            prefMaxPrice[i] = priceBeauty[i].first;
            prefMaxBeauty[i] = priceBeauty[i].second;
            if(i >= 1){
                prefMaxBeauty[i] = max(prefMaxBeauty[i - 1], priceBeauty[i].second);
            }
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int idx = upper_bound(prefMaxPrice.begin(), prefMaxPrice.end(), queries[i]) - prefMaxPrice.begin() - 1;
            if(idx >= 0){
                answer[i] = prefMaxBeauty[idx];
            }
        }
        
        return answer;
    }
};