class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        const int N = hand.size();
        
        map<int, int> freq;
        for(int elem: hand){
            freq[elem] += 1;
        }

        while((int)freq.size() >= groupSize){
            int startElem = freq.begin()->first;
            for(int elem = startElem; elem < startElem + groupSize; ++elem){
                if(freq.count(elem)){
                    freq[elem] -= 1;
                    if(freq[elem] == 0){
                        freq.erase(elem);
                    }
                }else{
                    return false;
                }
            }
        }

        return freq.empty();
    }
};