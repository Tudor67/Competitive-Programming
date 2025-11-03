class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int N = colors.size();

        int res = 0;
        int alternatingNeighbors = 0;
        
        for(int i = 1; i < N + k - 1; ++i){
            alternatingNeighbors += (colors[(i - 1) % N] ^ colors[i % N]);
            if(i - k >= 0){
                alternatingNeighbors -= (colors[(i - k) % N] ^ colors[(i - k + 1) % N]);
            }
            
            if(alternatingNeighbors == k - 1){
                res += 1;
            }
        }

        return res;
    }
};