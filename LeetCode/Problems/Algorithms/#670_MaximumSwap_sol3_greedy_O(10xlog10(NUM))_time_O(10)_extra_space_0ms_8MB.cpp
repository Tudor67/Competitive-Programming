class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int sLen = s.length();
        
        int leftIndex = -1;
        int rightIndex = -1;
        vector<int> lastIndexOf(10, -1);

        for(int i = sLen - 1; i >= 0; --i){
            for(int digit = s[i] - '0' + 1; digit <= 9; ++digit){
                if(lastIndexOf[digit] != -1){
                    leftIndex = i;
                    rightIndex = lastIndexOf[digit];
                }
            }

            if(lastIndexOf[s[i] - '0'] == -1){
                lastIndexOf[s[i] - '0'] = i;
            }
        }

        if(leftIndex != -1){
            swap(s[leftIndex], s[rightIndex]);
        }

        return stoi(s);
    }
};