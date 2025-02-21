class Solution {
private:
    void back(int index, int visMask, vector<int>& currSeq, vector<int>& maxSeq){
        int n = ((int)currSeq.size() + 1) / 2;
        if(!maxSeq.empty()){
            // stop
        }else if(index == (int)currSeq.size()){
            maxSeq = currSeq;
        }else if(currSeq[index] != 0){
            back(index + 1, visMask, currSeq, maxSeq);
        }else{
            for(int num = n; num >= 1 && maxSeq.empty(); --num){
                if(!((visMask >> num) & 1)){
                    int index2 = index + num * (int)(num >= 2);
                    if(index2 < (int)currSeq.size() && currSeq[index2] == 0){
                        currSeq[index] = num;
                        currSeq[index2] = num;
                        back(index + 1, visMask | (1 << num), currSeq, maxSeq);
                        currSeq[index] = 0;
                        currSeq[index2] = 0;
                    }
                }
            }
        }
    }

public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> currSeq(2 * n - 1);
        vector<int> maxSeq;
        back(0, 0, currSeq, maxSeq);
        return maxSeq;
    }
};