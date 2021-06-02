class Solution {
private:
    static bool sameSubsequenceOfNonX(const string& START, const string& END){
        const int N = START.length();
        for(int i = 0, j = 0; j < N; ++j){
            if(END[j] != 'X'){
                while(i < N && START[i] != END[j]){
                    i += 1;
                }
                if(i == N){
                    return false;
                }
                i += 1;
            }
        }
        return true;
    }
    
    static bool validPrefixCountOfL(const string& START, const string& END){
        const int N = START.length();
        int startPrefixCountOfL = 0;
        int endPrefixCountOfL = 0;
        for(int i = 0; i < N; ++i){
            startPrefixCountOfL += (START[i] == 'L');
            endPrefixCountOfL += (END[i] == 'L');
            if(startPrefixCountOfL > endPrefixCountOfL){
                return false;
            }
        }
        return true;
    }
    
    static bool validSuffixCountOfR(const string& START, const string& END){
        const int N = START.length();
        int startSuffixCountOfR = 0;
        int endSuffixCountOfR = 0;
        for(int i = N - 1; i >= 0; --i){
            startSuffixCountOfR += (START[i] == 'R');
            endSuffixCountOfR += (END[i] == 'R');
            if(startSuffixCountOfR > endSuffixCountOfR){
                return false;
            }
        }
        return true;
    }
    
public:
    bool canTransform(string start, string end) {
        return (sameSubsequenceOfNonX(start, end) &&
                validPrefixCountOfL(start, end) &&
                validSuffixCountOfR(start, end));
    }
};