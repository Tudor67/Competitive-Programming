class Solution {
private:
    const int BAD_RECEPTOR_ID = -1;
    
    int getReceptorID(int x, int y, int p){
        if(x == 0 && y == p){
            return 2;
        }else if(x == p && y == p){
            return 1;
        }else if(x == p && y == 0){
            return 0;
        }
        return BAD_RECEPTOR_ID;
    }
    
public:
    int mirrorReflection(int p, int q) {
        int x = 0;
        int y = 0;
        int direction = 1;
        
        while(getReceptorID(x, y, p) == BAD_RECEPTOR_ID){
            y += direction * q;
            
            if(x == 0){
                x = p;
            }else{
                x = 0;
            }
            
            if(y > p){
                y = p - (y - p);
                direction = -1;
            }else if(y < 0){
                y = -y;
                direction = 1;
            }
        }
        
        return getReceptorID(x, y, p);
    }
};