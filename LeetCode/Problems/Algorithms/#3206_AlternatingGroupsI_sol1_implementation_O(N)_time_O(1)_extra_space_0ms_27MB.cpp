class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        const int N = colors.size();

        int res = 0;
        for(int i = 0; i < N; ++i){
            if(colors[(i - 1 + N) % N] != colors[i] && colors[i] != colors[(i + 1) % N]){
                res += 1;
            }
        }

        return res;
    }
};