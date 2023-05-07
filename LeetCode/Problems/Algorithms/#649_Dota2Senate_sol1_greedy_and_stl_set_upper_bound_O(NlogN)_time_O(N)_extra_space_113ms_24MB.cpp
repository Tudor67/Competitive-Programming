class Solution {
public:
    string predictPartyVictory(string senate) {
        const int N = senate.length();

        map<char, char> rivalOf;
        rivalOf['R'] = 'D';
        rivalOf['D'] = 'R';

        set<int> activeIndices;
        map<char, set<int>> indicesOf;
        for(int i = 0; i < N; ++i){
            activeIndices.insert(i);
            indicesOf[senate[i]].insert(i);
        }

        while(!indicesOf['R'].empty() && !indicesOf['D'].empty()){
            for(set<int>::iterator activeIt = activeIndices.begin(); activeIt != activeIndices.end(); activeIt = next(activeIt)){
                int index = *activeIt;
                char rival = rivalOf[senate[index]];

                set<int>::iterator it = indicesOf[rival].upper_bound(index);
                if(it == indicesOf[rival].end()){
                    it = indicesOf[rival].begin();
                }

                if(it != indicesOf[rival].end()){
                    activeIndices.erase(*it);
                    indicesOf[rival].erase(*it);
                }
            }
        }

        if(indicesOf['R'].empty()){
            return "Dire";
        }
        return "Radiant";
    }
};