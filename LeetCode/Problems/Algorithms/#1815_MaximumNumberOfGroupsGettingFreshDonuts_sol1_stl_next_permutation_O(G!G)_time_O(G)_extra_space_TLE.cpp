class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        const int G = groups.size();
        
        vector<int> g(G);
        for(int i = 0; i < G; ++i){
            g[i] = groups[i] % batchSize;
        }
        
        sort(g.begin(), g.end());
        
        int maxHappyGroups = 0;
        do{
            int happyGroups = 0;
            int currentBatchSize = 0;
            for(int i = 0; i < G; ++i){
                if(currentBatchSize == 0){
                    happyGroups += 1;
                }
                currentBatchSize -= g[i];
                currentBatchSize += batchSize;
                currentBatchSize %= batchSize;
            }
            maxHappyGroups = max(maxHappyGroups, happyGroups);
        }while(next_permutation(g.begin(), g.end()) && maxHappyGroups < G);
        
        return maxHappyGroups;
    }
};