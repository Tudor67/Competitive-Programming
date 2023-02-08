class Solution {
public:
    string maximumBinaryString(string binary) {
        const int N = binary.length();

        string s = binary;
        int firstZeroPos = find(s.begin(), s.end(), '0') - s.begin();
        if(firstZeroPos < N){
            int zeros = count(s.begin() + firstZeroPos, s.end(), '0');
            for(int i = firstZeroPos; i < N; ++i){
                if(zeros >= 2){
                    s[i] = '1';
                }else if(zeros == 1){
                    s[i] = '0';
                }else{
                    s[i] = '1';
                }
                zeros -= 1;
            }
        }

        return s;
    }
};