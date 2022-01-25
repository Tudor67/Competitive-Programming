class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long k = 1;
        while(2 * k * (k + 1) * (2 * k + 1) < neededApples){
            k += 1;
        }
        return 8 * k;
    }
};