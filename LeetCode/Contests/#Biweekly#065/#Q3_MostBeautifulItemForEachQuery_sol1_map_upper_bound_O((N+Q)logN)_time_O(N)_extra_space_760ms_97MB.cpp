class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        const int N = items.size();
        const int Q = queries.size();
        
        map<int, int> maxBeautyAt;
        for(const vector<int>& PB: items){
            int price = PB[0];
            int beauty = PB[1];
            maxBeautyAt[price] = max(maxBeautyAt[price], beauty);
        }
        
        int prevMaxBeauty = 0;
        for(const pair<int, int>& PB: maxBeautyAt){
            int price = PB.first;
            int beauty = PB.second;
            int maxBeauty = max(prevMaxBeauty, beauty);
            maxBeautyAt[price] = maxBeauty;
            prevMaxBeauty = maxBeauty;
        }
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            auto it = maxBeautyAt.upper_bound(queries[i]);
            if(it != maxBeautyAt.begin()){
                answer[i] = prev(it)->second;
            }
        }
        
        return answer;
    }
};