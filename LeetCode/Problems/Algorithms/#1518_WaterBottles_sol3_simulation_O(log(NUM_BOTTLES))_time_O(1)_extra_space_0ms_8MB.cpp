class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drunkBottles = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){
            drunkBottles += (emptyBottles / numExchange);
            emptyBottles = (emptyBottles / numExchange + emptyBottles % numExchange);
        }

        return drunkBottles;
    }
};