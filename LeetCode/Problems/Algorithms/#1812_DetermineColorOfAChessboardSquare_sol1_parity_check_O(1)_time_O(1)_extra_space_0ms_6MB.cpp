class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return ((coordinates[0] - '1') + (coordinates[1] - 'a')) % 2;
    }
};