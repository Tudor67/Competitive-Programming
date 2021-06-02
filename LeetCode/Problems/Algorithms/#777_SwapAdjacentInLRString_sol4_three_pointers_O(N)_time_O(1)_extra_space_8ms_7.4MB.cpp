class Solution {
public:
    bool canTransform(string start, string end) {
        const int N = start.length();
        
        int posX = 0;
        int posL = 0;
        int posR = 0;
        
        for(int i = 0; i < N; ++i){
            if(start[i] != end[i]){
                for(posX = max(i + 1, posX); posX < N && start[posX] != 'X'; ++posX);
                for(posL = max(i + 1, posL); posL < N && start[posL] != 'L'; ++posL);
                for(posR = max(i + 1, posR); posR < N && start[posR] != 'R'; ++posR);
                if(start[i] == 'X' && end[i] == 'L' && posL < posR){
                    start[i] = 'L';
                    start[posL] = 'X';
                }else if(start[i] == 'R' && end[i] == 'X' && posX < posL){
                    start[i] = 'X';
                    start[posX] = 'R';
                }else{
                    return false;
                }
            }
        }
        
        return true;
    }
};