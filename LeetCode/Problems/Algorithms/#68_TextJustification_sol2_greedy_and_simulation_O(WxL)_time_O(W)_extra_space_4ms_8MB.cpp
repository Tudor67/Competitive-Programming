class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        const int W = words.size();

        vector<vector<int>> resWordIndices;
        vector<int> resLength;
        for(int i = 0; i < (int)words.size(); ++i){
            if(resLength.empty() || (int)resLength.back() + 1 + (int)words[i].length() > maxWidth){
                resWordIndices.push_back({i});
                resLength.push_back(words[i].length());
            }else{
                resWordIndices.back().push_back(i);
                resLength.back() += 1 + words[i].length();
            }
        }
        
        const int TOTAL_LINES = resWordIndices.size();
        vector<string> res(TOTAL_LINES);
        for(int lineIndex = 0; lineIndex < TOTAL_LINES; ++lineIndex){
            int lineWordsCount = resWordIndices[lineIndex].size();
            int spaces = 1;
            int leftExtraSpaces = 0;
            if(lineWordsCount >= 2 && lineIndex != TOTAL_LINES - 1){
                spaces = 1 + (maxWidth - resLength[lineIndex]) / (lineWordsCount - 1);
                leftExtraSpaces = (maxWidth - resLength[lineIndex]) % (lineWordsCount - 1);
            }
            for(int wordIndex: resWordIndices[lineIndex]){
                res[lineIndex] += words[wordIndex];
                res[lineIndex].append(min(1, leftExtraSpaces) + spaces, ' ');
                leftExtraSpaces = max(0, leftExtraSpaces - 1);
            }
            res[lineIndex].resize(maxWidth, ' ');
        }

        return res;
    }
};