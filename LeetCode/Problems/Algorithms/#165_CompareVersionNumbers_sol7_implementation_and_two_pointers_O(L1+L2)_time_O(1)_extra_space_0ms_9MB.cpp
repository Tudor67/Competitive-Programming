class Solution {
private:
    int getIndexOfNextDot(const string& S, int index){
        const int L = S.length();
        while(index < L && S[index] != '.'){
            index += 1;
        }
        return index;
    }

    int stringToInt(const string& S, int startIndex, int endIndex){
        int val = 0;
        for(int i = startIndex; i < endIndex; ++i){
            val = val * 10 + (S[i] - '0');
        }
        return val;
    }

public:
    int compareVersion(string version1, string version2) {
        const int L1 = version1.length();
        const int L2 = version2.length();

        int start1 = 0;
        int start2 = 0;

        while(start1 < L1 || start2 < L2){
            int end1 = getIndexOfNextDot(version1, start1);
            int end2 = getIndexOfNextDot(version2, start2);

            int val1 = stringToInt(version1, start1, end1);
            int val2 = stringToInt(version2, start2, end2);

            if(val1 < val2){
                return -1;
            }else if(val1 > val2){
                return 1;
            }

            start1 = min(L1, end1 + 1);
            start2 = min(L2, end2 + 1);
        }

        return 0;
    }
};