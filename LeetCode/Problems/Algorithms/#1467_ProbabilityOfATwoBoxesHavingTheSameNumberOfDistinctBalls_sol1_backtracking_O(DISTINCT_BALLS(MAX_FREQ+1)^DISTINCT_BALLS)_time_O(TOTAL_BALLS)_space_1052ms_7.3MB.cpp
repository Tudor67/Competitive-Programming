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
    
    int countDistinctBalls(vector<int>& ballsFreq){
        int count = 0;
        for(int i = 0; i < ballsFreq.size(); ++i){
            count += (ballsFreq[i] > 0);
        }
        return count;
    }
    
    int countTotalBalls(vector<int>& ballsFreq){
        return accumulate(ballsFreq.begin(), ballsFreq.end(), 0);
    }
    
    void back(int idx, vector<int>& ballsFreqA, vector<int>& ballsFreqB, double& validDistributions){
        if(countDistinctBalls(ballsFreqA) == countDistinctBalls(ballsFreqB) && countTotalBalls(ballsFreqA) == countTotalBalls(ballsFreqB)){
            double permutationsA = countPermutationsWithRepetition(ballsFreqA);
            double permutationsB = countPermutationsWithRepetition(ballsFreqB);
            validDistributions += permutationsA * permutationsB;
        }else if(idx < ballsFreqA.size()){
            for(int i = 0; i <= ballsFreqA[idx]; ++i){
                if(ballsFreqA[idx] > 0){
                    ballsFreqA[idx] -= i;
                    ballsFreqB[idx] += i;
                    back(idx + 1, ballsFreqA, ballsFreqB, validDistributions);
                    ballsFreqB[idx] -= i;
                    ballsFreqA[idx] += i;
                }
            }
        }
    }
    
public:
    double getProbability(vector<int>& ballsFreq) {
        const int TOTAL_BALLS = accumulate(ballsFreq.begin(), ballsFreq.end(), 0);
        initFactorial(TOTAL_BALLS);
        double totalDistributions = countPermutationsWithRepetition(ballsFreq);
        double validDistributions = 0;
        vector<int> ballsFreqA = ballsFreq;
        vector<int> ballsFreqB = vector<int>(ballsFreq.size(), 0);
        back(0, ballsFreqA, ballsFreqB, validDistributions);
        return validDistributions / totalDistributions;
    }
};