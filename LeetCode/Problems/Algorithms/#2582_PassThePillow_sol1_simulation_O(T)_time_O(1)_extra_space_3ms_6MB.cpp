class Solution {
public:
    int passThePillow(int n, int time) {
        int person = 1;
        int direction = -1;

        while(time >= 1){
            if(person == 1 || person == n){
                direction *= -1;
            }
            person += direction;
            time -= 1;
        }

        return person;
    }
};