class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int N = colors.size();

        int alternatingGroups = 0;
        int alternatingNeighbors = 0;

        for(int i = 1; i < N + k - 1; ++i){
            alternatingNeighbors += (int)(colors[(i - 1) % N] != colors[i % N]);
            if(i >= k){
                alternatingNeighbors -= (int)(colors[(i - k) % N] != colors[(i - k + 1) % N]);
            }
            if(alternatingNeighbors == k - 1){
                alternatingGroups += 1;
            }
        }

        return alternatingGroups;
    }
};