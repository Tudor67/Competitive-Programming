class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int N = items.size();
        const int Q = queries.size();

        map<int, int> priceToMaxBeauty;
        for(int i = 0; i < N; ++i){
            int price = items[i][0];
            int beauty = items[i][1];
            priceToMaxBeauty[price] = max(priceToMaxBeauty[price], beauty);
        }

        int prefMaxBeauty = 0;
        for(auto& [price, beauty]: priceToMaxBeauty){
            prefMaxBeauty = max(prefMaxBeauty, beauty);
            beauty = prefMaxBeauty;
        }

        vector<int> res(Q);
        for(int queryIndex = 0; queryIndex < Q; ++queryIndex){
            auto it = priceToMaxBeauty.upper_bound(queries[queryIndex]);
            if(it != priceToMaxBeauty.begin()){
                res[queryIndex] = prev(it)->second;
            }
        }

        return res;
    }
};