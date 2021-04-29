class Solution {
public:
    int countBinarySubstrings(string s) {
        const int N = s.length();
        int answer = 0;
        int prevElem = 0;
        int prevElemCount = 0;
        int curElem = s[0];
        int curElemCount = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == curElem){
                curElemCount += 1;
            }else{
                answer += min(prevElemCount, curElemCount);
                prevElem = curElem;
                prevElemCount = curElemCount;
                curElem = s[i];
                curElemCount = 1;
            }
        }
        answer += min(prevElemCount, curElemCount);
        return answer;
    }
};