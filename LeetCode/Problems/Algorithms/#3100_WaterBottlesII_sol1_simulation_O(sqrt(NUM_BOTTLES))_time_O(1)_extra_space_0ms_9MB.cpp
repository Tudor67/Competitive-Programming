class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunkBottles = numBottles;
        int emptyBottles = numBottles;

        while(emptyBottles >= numExchange){
            emptyBottles -= numExchange;
            numExchange += 1;
            drunkBottles += 1;
            emptyBottles += 1;
        }

        return drunkBottles;
    }
};