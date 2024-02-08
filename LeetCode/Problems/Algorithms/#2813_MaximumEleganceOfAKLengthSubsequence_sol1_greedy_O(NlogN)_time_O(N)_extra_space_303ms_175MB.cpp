class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        const int N = items.size();

        // Step 1: sort items in decreasing order of profit
        vector<pair<int, int>> sortedItems(N);
        for(int i = 0; i < N; ++i){
            sortedItems[i] = {items[i][0], items[i][1]};
        }

        sort(sortedItems.rbegin(), sortedItems.rend());

        // Step 2: pick the first k (most profitable) items
        //         store the profits of the duplicate categories
        long long profitSum = 0;
        long long distinctCategories = 0;
        vector<int> profitsOfDuplicateCategories;
        vector<bool> vis(N + 1, false);
        for(int i = 0; i < k; ++i){
            int profit = sortedItems[i].first;
            int category = sortedItems[i].second;
            profitSum += profit;
            distinctCategories += !vis[category];
            if(vis[category]){
                profitsOfDuplicateCategories.push_back(profit);
            }
            vis[category] = true;
        }

        long long res = profitSum + distinctCategories * distinctCategories;

        // Step 3: process the remaining (N - k) items in decreasing order of the profit
        //         replace the least profitable item of a duplicate category (from previous items)
        //                 with an item from a new category (current item)
        //         the main idea is to add a new category even if we lose some profit
        for(int i = k; i < N; ++i){
            int profit = sortedItems[i].first;
            int category = sortedItems[i].second;
            if(!vis[category] && !profitsOfDuplicateCategories.empty()){
                profitSum -= profitsOfDuplicateCategories.back();
                profitsOfDuplicateCategories.pop_back();
                profitSum += profit;
                distinctCategories += 1;
                vis[category] = true;
                res = max(res, profitSum + distinctCategories * distinctCategories);
            }
        }

        return res;
    }
};