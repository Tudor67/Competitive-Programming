class Solution {
public:
    int maxDistance(vector<int>& colors) {
        const int N = colors.size();

        int maxDist = 0;
        for(int i = 0; i < N - 1; ++i){
            if(colors[i] != colors[N - 1]){
                maxDist = max(maxDist, N - 1 - i);
            }
        }

        for(int i = N - 1; i >= 1; --i){
            if(colors[i] != colors[0]){
                maxDist = max(maxDist, i);
            }
        }

        return maxDist;
    }
};