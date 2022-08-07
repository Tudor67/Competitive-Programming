class Solution {
public:
    int mirrorReflection(int p, int q) {
        int pqLCM = lcm(p, q);
        
        int receptorID = -1;
        if((pqLCM / p) % 2 == 0){
            receptorID = 0;
        }else{
            if((pqLCM / q) % 2 == 0){
                receptorID = 2;
            }else{
                receptorID = 1;
            }
        }
        
        return receptorID;
    }
};