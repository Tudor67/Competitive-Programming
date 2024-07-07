class Solution {
public:
    int passThePillow(int n, int time) {
        int index = time % (2 * n - 2);
        if(index >= n){
            index = (n - 1) - (index - (n - 1));
        }
        return index + 1;
    }
};