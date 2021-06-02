class Solution {
public:
    bool canTransform(string start, string end) {
        const int N = start.length();
        
        unordered_map<char, set<int>> pos;
        for(int i = 0; i < N; ++i){
            pos[start[i]].insert(i);
        }
        
        for(int i = 0; i < N; ++i){
            if(start[i] != end[i]){
                auto itX = pos['X'].upper_bound(i);
                auto itL = pos['L'].upper_bound(i);
                auto itR = pos['R'].upper_bound(i);
                if(start[i] == 'X'){
                    // Case 1
                    if(end[i] == 'L'){
                        if(itL == pos['L'].end() || (itR != pos['R'].end() && *itR < *itL)){
                            return false;
                        }else{
                            start[i] = 'L';
                            start[*itL] = 'X';
                            pos['X'].erase(i);
                            pos['X'].insert(*itL);
                            pos['L'].erase(itL);
                            pos['L'].insert(i);
                        }
                    }else{
                        return false;
                    }
                }else if(start[i] == 'R'){
                    // Case 2
                    if(end[i] == 'X'){
                        if(itX == pos['X'].end() || (itL != pos['L'].end() && *itL < *itX)){
                            return false;
                        }else{
                            start[i] = 'X';
                            start[*itX] = 'R';
                            pos['R'].erase(i);
                            pos['R'].insert(*itX);
                            pos['X'].erase(itX);
                            pos['X'].insert(i);
                        }
                    }else{
                        return false;
                    }
                }else if(start[i] == 'L'){
                    // Case 3
                    return false;
                }
            }
        }
        
        return true;
    }
};