class Solution {
public:
    int passThePillow(int n, int time) {
        int person = time % (2 * n - 2) + 1;
        if(n <= person){
            person = n - (person - n);
        }
        return person;
    }
};