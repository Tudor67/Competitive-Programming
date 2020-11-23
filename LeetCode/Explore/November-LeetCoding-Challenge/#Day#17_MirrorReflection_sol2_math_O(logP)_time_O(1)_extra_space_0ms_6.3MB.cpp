class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q == 0){
            q = 2 * p;
        }
        
        int receptorID = -1;
        if((lcm(p, q) / p) % 2 == 0){
            receptorID = 0;
        }else{
            if((lcm(p, q) / q) % 2 == 0){
                receptorID = 2;
            }else{
                receptorID = 1;
            }
        }
        
        return receptorID;
    }
};