class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        return 10 * (mainTank + min(additionalTank, (mainTank - 1) / 4));
    }
};