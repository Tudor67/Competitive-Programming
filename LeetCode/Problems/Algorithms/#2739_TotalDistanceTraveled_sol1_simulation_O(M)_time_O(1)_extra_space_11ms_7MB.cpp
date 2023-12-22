class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int totalDistance = 0;

        while(mainTank > 0){
            int takenFuel = min(mainTank, 5);
            mainTank -= takenFuel;
            totalDistance += takenFuel * 10;
            
            if(takenFuel == 5 && additionalTank > 0){
                mainTank += 1;
                additionalTank -= 1;
            }
        }

        return totalDistance;
    }
};