class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int N = bits.size();

        int i = 0;
        while(i < N - 1){
            if(bits[i] == 0){
                i += 1;
            }else{
                i += 2;
            }
        }

        return (i == N - 1);
    }
};