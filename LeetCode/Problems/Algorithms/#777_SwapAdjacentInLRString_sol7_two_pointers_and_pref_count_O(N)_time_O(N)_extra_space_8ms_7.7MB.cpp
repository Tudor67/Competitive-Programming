class Solution {
private:
    static bool sameSubsequenceOfNonX(const string& START, const string& END){
        const int N = START.length();
        string startSubseq;
        string endSubseq;
        for(int i = 0; i < N; ++i){
            if(START[i] != 'X'){
                startSubseq += START[i];
            }
            if(END[i] != 'X'){
                endSubseq += END[i];
            }
        }
        return (startSubseq == endSubseq);
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