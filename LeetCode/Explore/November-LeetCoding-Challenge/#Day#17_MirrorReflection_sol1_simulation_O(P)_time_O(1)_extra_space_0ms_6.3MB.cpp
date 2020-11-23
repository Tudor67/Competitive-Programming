class Solution {
private:
    int receptorID(const int& X, const int& Y, const int& P){
        if(X == P && Y == 0){
            return 0;
        }else if(X == P && Y == P){
            return 1;
        }else if(X == 0 && Y == P){
            return 2;
        }
        return -1;
    }
    
public:
    int mirrorReflection(int p, int q) {
        int x = p;
        int y = q;
        int direction = 1;
        
        while(receptorID(x, y, p) == -1){
            // update x
            if(x == 0){
                x = p;
            }else{
                x = 0;
            }
            // update y
            y += direction * q;
            if(y > p){
                y = p - (y - p);
                direction = -1;
            }else if(y < 0){
                y = -y;
                direction = 1;
            }
        }
        
        return receptorID(x, y, p);
    }
};