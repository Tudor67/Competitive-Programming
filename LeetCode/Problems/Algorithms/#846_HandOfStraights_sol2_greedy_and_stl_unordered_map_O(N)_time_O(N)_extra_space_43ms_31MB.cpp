class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int N = hand.size();

        unordered_map<int, int> freq;
        for(int elem: hand){
            freq[elem] += 1;
        }

        for(int elem: hand){
            int startElem = elem;
            while(freq[startElem - 1] >= 1){
                startElem -= 1;
            }

            while(startElem <= elem){
                while(freq[startElem] >= 1){
                    for(int i = startElem; i < startElem + groupSize; ++i){
                        if(freq[i] >= 1){
                            freq[i] -= 1;
                        }else{
                            return false;
                        }
                    }
                }
                startElem += 1;
            }
        }

        return true;
    }
};