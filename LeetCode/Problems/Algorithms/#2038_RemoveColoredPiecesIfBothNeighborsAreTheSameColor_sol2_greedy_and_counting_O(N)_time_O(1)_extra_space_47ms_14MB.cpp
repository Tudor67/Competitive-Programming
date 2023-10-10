class Solution {
public:
    bool winnerOfGame(string colors) {
        const int N = colors.length();

        vector<int> totalMoves(2);
        for(char targetColor: {'A', 'B'}){
            int len = 0;
            for(int i = 0; i < N; ++i){
                if(colors[i] == targetColor){
                    len += 1;
                }else{
                    len = 0;
                }

                if(i == N - 1 || colors[i + 1] != targetColor){
                    totalMoves[targetColor - 'A'] += max(0, len - 2);
                }
            }
        }
        
        return (totalMoves[0] > totalMoves[1]);
    }
};