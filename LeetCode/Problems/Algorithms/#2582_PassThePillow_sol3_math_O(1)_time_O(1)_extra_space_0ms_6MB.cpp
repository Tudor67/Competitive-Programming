class Solution {
public:
    int passThePillow(int n, int time) {
        int rounds = time / (n - 1);
        int rem = time % (n - 1);
        
        int person = rem + 1;
        if(rounds % 2 == 1){
            person = n - rem;
        }

        return person;
    }
};