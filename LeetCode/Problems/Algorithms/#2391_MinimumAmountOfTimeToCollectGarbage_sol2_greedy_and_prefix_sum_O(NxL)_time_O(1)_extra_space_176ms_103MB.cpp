class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        const int N = garbage.size();
        const string GARBAGE_TYPES = "GMP";

        // Step 1: collect all garbage (ignoring the travel time)
        int totalCost = 0;
        for(int i = 0; i < N; ++i){
            totalCost += garbage[i].length();
        }

        // Step 2: add the travel time for each type of garbage
        unordered_map<char, int> travelTimeOf;
        int travelTime = 0;
        for(int i = 0; i < N; ++i){
            if(i - 1 >= 0){
                travelTime += travel[i - 1];
            }
            for(char g: garbage[i]){
                travelTimeOf[g] = travelTime;
            }
        }

        for(pair<const char, int>& P: travelTimeOf){
            int travelTime = P.second;
            totalCost += travelTime;
        }

        return totalCost;
    }
};