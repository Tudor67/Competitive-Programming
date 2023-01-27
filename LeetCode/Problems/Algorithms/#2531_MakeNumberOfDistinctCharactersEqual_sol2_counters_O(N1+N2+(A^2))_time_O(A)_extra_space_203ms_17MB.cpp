class Solution {
private:
    void updateCounter(const string& S, vector<int>& count){
        for(char c: S){
            count[c] += 1;
        }
    }
    
public:
    bool isItPossible(string word1, string word2) {
        const int N1 = word1.length();
        const int N2 = word2.length();
        const int A = 26;
        
        vector<int> count1(100 + A);
        vector<int> count2(100 + A);
        updateCounter(word1, count1);
        updateCounter(word2, count2);

        int u1 = 0;
        int u2 = 0;
        for(char c = 'a'; c <= 'z'; ++c){
            u1 += (int)(count1[c] > 0);
            u2 += (int)(count2[c] > 0);
        }
        
        for(char c1 = 'a'; c1 <= 'z'; ++c1){
            for(char c2 = 'a'; c2 <= 'z'; ++c2){
                if(count1[c1] > 0 && count2[c2] > 0){
                    count1[c1] -= 1; u1 -= (int)(count1[c1] == 0);
                    count2[c1] += 1; u2 += (int)(count2[c1] == 1);
                    count1[c2] += 1; u1 += (int)(count1[c2] == 1);
                    count2[c2] -= 1; u2 -= (int)(count2[c2] == 0);

                    if(u1 == u2){
                        return true;
                    }
                    
                    count1[c1] += 1; u1 += (int)(count1[c1] == 1);
                    count2[c1] -= 1; u2 -= (int)(count2[c1] == 0);
                    count1[c2] -= 1; u1 -= (int)(count1[c2] == 0);
                    count2[c2] += 1; u2 += (int)(count2[c2] == 1);
                }
            }
        }
        
        return false;
    }
};