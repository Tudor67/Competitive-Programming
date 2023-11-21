class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const int N = garbage.size();
        const string GARBAGE_TYPES = "GMP";

        int totalCost = 0;
        for(char g: GARBAGE_TYPES){
            int travelCost = 0;
            for(int i = 0; i < N; ++i){
                if(i - 1 >= 0){
                    travelCost += travel[i - 1];
                }
                int gCount = count(garbage[i].begin(), garbage[i].end(), g);
                if(gCount >= 1){
                    totalCost += gCount;
                    totalCost += travelCost;
                    travelCost = 0;
                }
            }
        }

        return totalCost;
    }
};