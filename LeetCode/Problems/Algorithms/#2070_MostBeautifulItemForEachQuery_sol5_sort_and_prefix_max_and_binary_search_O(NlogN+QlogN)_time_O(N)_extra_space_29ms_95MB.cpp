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

        vector<int> prefMaxBeauty(N);
        prefMaxBeauty[0] = sortedItems[0].second;
        for(int i = 1; i < N; ++i){
            prefMaxBeauty[i] = max(prefMaxBeauty[i - 1], sortedItems[i].second);
        }

        vector<int> res(Q);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            int i = upper_bound(sortedItems.begin(), sortedItems.end(), pair<int, int>{queries[queryIndex], INT_MAX})
                    - sortedItems.begin() - 1;
            if(i >= 0){
                res[queryIndex] = prefMaxBeauty[i];
            }
        }

        return res;
    }
};