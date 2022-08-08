class Solution {
private:
    void ignoreBlanks(const string& S, int& i){
        const int N = S.length();
        while(i < N && S[i] == '_'){
            i += 1;
        }
    }
    
public:
    bool canChange(string start, string target) {
        const int N = start.length();
        
        int i = 0;
        int j = 0;
        while(i < N && j < N){
            ignoreBlanks(start, i);
            ignoreBlanks(target, j);
            if(i < N && j < N && start[i] == target[j] && ((start[i] == 'L' && i >= j) ||
                                                           (start[i] == 'R' && i <= j))){
                i += 1;
                j += 1;
            }else{
                break;
            }
        }
        
        ignoreBlanks(start, i);
        ignoreBlanks(target, j);
        
        return (i == N && j == N);
    }
};