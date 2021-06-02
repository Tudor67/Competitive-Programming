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
                if(start[i] == 'X'){
                    // Case 1
                    if(end[i] == 'L'){
                        if(posL < posR){
                            start[i] = 'L';
                            start[posL] = 'X';
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else if(start[i] == 'R'){
                    // Case 2
                    if(end[i] == 'X'){
                        if(posX < posL){
                            start[i] = 'X';
                            start[posX] = 'R';
                        }else{
                            return false;
                        }
                    }else{
                        return false;
                    }
                }else if(start[i] == 'L'){
                    // Case 3
                    return false;
                }
            }
        }
        
        return true;
    }
};