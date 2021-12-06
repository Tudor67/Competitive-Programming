class Solution {
public:
    bool winnerOfGame(string colors) {
        const int N = colors.size();
        
        vector<int> colorCount(2, 0);
        
        int i = 0;
        for(int j = 0; j <= N; ++j){
            if(j == N || colors[i] != colors[j]){
                colorCount[colors[i] - 'A'] += max(0, j - i - 2);
                i = j;
            }
        }
        
        return (colorCount[0] > colorCount[1]);
    }
};