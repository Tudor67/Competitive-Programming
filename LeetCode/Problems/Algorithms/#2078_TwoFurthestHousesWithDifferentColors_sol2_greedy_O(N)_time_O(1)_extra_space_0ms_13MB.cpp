class Solution {
public:
    int maxDistance(vector<int>& colors) {
        const int N = colors.size();

        for(int d = N - 1; d >= 1; --d){
            if((colors[0] != colors[d]) ||
               (colors[N - 1 - d] != colors[N - 1])){
                return d;
            }
        }

        return 0;
    }
};