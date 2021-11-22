class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int z = x ^ y;
        while(z > 0){
            z &= (z - 1);
            distance += 1;
        }
        return distance;
    }
};