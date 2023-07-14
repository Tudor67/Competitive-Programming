class Solution {
private:
    int computeMaxVariance(string& s, vector<int>& indicesOfA, vector<int>& indicesOfB){
        const int NA = indicesOfA.size();
        const int NB = indicesOfB.size();

        int maxVariance = 0;
        int balance = 0;
        int minBalance = 0;
        int minBalanceBeforeLastA = 0;

        int iA = 0;
        int iB = 0;
        while(iA < NA || iB < NB){
            if(iB == NB || (iA < NA && indicesOfA[iA] < indicesOfB[iB])){
                minBalanceBeforeLastA = minBalance;
                balance -= 1;
                iA += 1;
            }else{
                balance += 1;
                iB += 1;
            }

            if(iA >= 1){
                maxVariance = max(maxVariance, balance - minBalanceBeforeLastA);
            }
            
            minBalance = min(minBalance, balance);
        }

        return maxVariance;
    }

public:
    int largestVariance(string s) {
        const int N = s.length();

        unordered_map<char, vector<int>> indicesOf;
        for(int i = 0; i < N; ++i){
            indicesOf[s[i]].push_back(i);
        }

        int maxVariance = 0;
        for(char a = 'a'; a <= 'z'; ++a){
            for(char b = 'a'; b <= 'z'; ++b){
                if(a != b && indicesOf.count(a) && indicesOf.count(b)){
                    maxVariance = max(maxVariance, computeMaxVariance(s, indicesOf[a], indicesOf[b]));
                }
            }
        }

        return maxVariance;
    }
};