class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int totalDistance = 0;

        while(mainTank >= 5){
            int maxBlocks = min(additionalTank, mainTank / 5);
            additionalTank -= maxBlocks;

            totalDistance += (mainTank / 5) * 5 * 10;
            mainTank = (mainTank % 5) + min(maxBlocks, mainTank / 5);
        }

        totalDistance += mainTank * 10;

        return totalDistance;
    }
};