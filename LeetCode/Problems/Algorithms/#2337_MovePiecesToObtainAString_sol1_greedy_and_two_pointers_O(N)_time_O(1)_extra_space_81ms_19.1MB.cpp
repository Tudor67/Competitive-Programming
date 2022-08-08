class Solution {
public:
    bool canChange(string start, string target) {
        const int N = start.length();
        
        int j = 0;
        for(int i = 0; i < N; ++i){
            if(start[i] != target[i]){
                if(start[i] == '_'){
                    j = max(j, i + 1);
                    while(j < N && start[j] == '_'){
                        j += 1;
                    }
                    if(j < N && start[j] == 'L'){
                        swap(start[i], start[j]);
                    }
                }else if(start[i] == 'R'){
                    j = max(j, i + 1);
                    while(j < N && start[j] == 'R'){
                        j += 1;
                    }
                    if(j < N && start[j] == '_'){
                        swap(start[i], start[j]);
                    }
                }
                
                if(start[i] != target[i]){
                    return false;
                }
            }
        }
        
        return true;
    }
};