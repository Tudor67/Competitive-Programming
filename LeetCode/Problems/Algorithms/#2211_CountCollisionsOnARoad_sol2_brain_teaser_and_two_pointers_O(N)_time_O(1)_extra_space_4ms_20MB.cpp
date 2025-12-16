class Solution {
public:
    int countCollisions(string directions) {
        const int N = directions.length();

        int l = 0;
        while(l < N && directions[l] == 'L'){
            l += 1;
        }

        int r = N - 1;
        while(r >= 0 && directions[r] == 'R'){
            r -= 1;
        }

        int collisions = 0;
        for(int i = l; i <= r; ++i){
            if(directions[i] != 'S'){
                collisions += 1;
            }
        }

        return collisions;
    }
};