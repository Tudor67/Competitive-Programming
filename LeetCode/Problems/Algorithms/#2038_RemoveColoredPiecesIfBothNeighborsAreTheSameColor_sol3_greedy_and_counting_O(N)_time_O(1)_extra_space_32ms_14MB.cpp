class Solution {
public:
    bool winnerOfGame(string colors) {
        const int N = colors.length();

        vector<int> totalMoves(2);
        for(int i = 1; i + 1 < N; ++i){
            if(colors[i - 1] == colors[i] && colors[i] == colors[i + 1]){
                totalMoves[colors[i] - 'A'] += 1;
            }
        }

        return (totalMoves[0] > totalMoves[1]);
    }
};