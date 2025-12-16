class Solution {
public:
    int countCollisions(string directions) {
        int collisions = 0;

        int r = 0;
        int s = 0;
        for(char direction: directions){
            if(direction == 'L'){
                if(r >= 1){
                    collisions += r + 1;
                    r = 0;
                    s = 1;
                }else if(s == 1){
                    collisions += 1;
                }
            }else if(direction == 'R'){
                r += 1;
            }else if(direction == 'S'){
                collisions += r;
                r = 0;
                s = 1;
            }
        }

        return collisions;
    }
};