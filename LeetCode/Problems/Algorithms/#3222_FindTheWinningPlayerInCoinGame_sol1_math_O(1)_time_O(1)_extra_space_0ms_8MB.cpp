class Solution {
public:
    string winningPlayer(int x, int y) {
        int validTurns = min(x, y / 4);
        if(validTurns % 2 == 1){
            return "Alice";
        }
        return "Bob";
    }
};