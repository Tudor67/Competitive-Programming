class Solution {
private:
    void ignoreBlankSpaces(string& s, int& i){
        while(i < (int)s.length() && s[i] == '_'){
            i += 1;
        }
    }

public:
    bool canChange(string start, string target) {
        const int N = target.length();

        int startIndex = 0;
        for(int targetIndex = 0; targetIndex < N; ++targetIndex){
            if(target[targetIndex] == '_'){
                // ignore '_'
            }else{
                ignoreBlankSpaces(start, startIndex);
                if((startIndex >= targetIndex && start[startIndex] == 'L' && target[targetIndex] == 'L') ||
                   (startIndex <= targetIndex && start[startIndex] == 'R' && target[targetIndex] == 'R')){
                    startIndex += 1;
                }else{
                    return false;
                }
            }
        }

        ignoreBlankSpaces(start, startIndex);

        return (startIndex == N);
    }
};