class Solution {
private:
    vector<double> factorial;
    
    void initFactorial(const int MAX_N){
        factorial.resize(MAX_N + 1, 1);
        for(int i = 2; i <= MAX_N; ++i){
            factorial[i] = i * factorial[i - 1];
        }
    }
    
    double countPermutationsWithRepetition(vector<int>& k){
        // compute (k[0] + k[1] + ... k[m - 1])! / (k[0]! * k[1]! * ... k[m - 1])
        int n = accumulate(k.begin(), k.end(), 0);
        double count = factorial[n];
        for(int i = 0; i < k.size(); ++i){
            count /= factorial[k[i]];
        }
        return count;
    }
    
    void back(vector<int>& ballsFreqA, int distinctBallsA, int totalBallsA,
              vector<int>& ballsFreqB, int distinctBallsB, int totalBallsB,
              int idx, double& validDistributions){
        if(distinctBallsA == distinctBallsB && totalBallsA == totalBallsB){
            double permutationsA = countPermutationsWithRepetition(ballsFreqA);
            double permutationsB = countPermutationsWithRepetition(ballsFreqB);
            validDistributions += permutationsA * permutationsB;
        }else if(idx < ballsFreqA.size()){
            for(int i = 0; i <= ballsFreqA[idx]; ++i){
                if(ballsFreqA[idx] > 0){
                    ballsFreqA[idx] -= i;
                    ballsFreqB[idx] += i;
                    back(ballsFreqA, distinctBallsA - (ballsFreqA[idx] == 0), totalBallsA - i,
                         ballsFreqB, distinctBallsB + (ballsFreqB[idx] > 0), totalBallsB + i, idx + 1, validDistributions);
                    ballsFreqA[idx] += i;
                    ballsFreqB[idx] -= i;
                }
            }
        }
    }
    
public:
    double getProbability(vector<int>& ballsFreq) {
        const int TOTAL_BALLS = accumulate(ballsFreq.begin(), ballsFreq.end(), 0);
        const int DISTINCT_BALLS = ballsFreq.size();
        initFactorial(TOTAL_BALLS);
        double totalDistributions = countPermutationsWithRepetition(ballsFreq);
        double validDistributions = 0;
        vector<int> ballsFreqA = ballsFreq;
        vector<int> ballsFreqB = vector<int>(ballsFreq.size(), 0);
        back(ballsFreqA, DISTINCT_BALLS, TOTAL_BALLS, ballsFreqB, 0, 0, 0, validDistributions);
        return validDistributions / totalDistributions;
    }
};