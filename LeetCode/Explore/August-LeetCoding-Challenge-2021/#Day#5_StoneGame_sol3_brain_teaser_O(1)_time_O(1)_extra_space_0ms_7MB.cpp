class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /*
          c1.) even number of piles;
          => first player can take the first, third, fifth, ... (N - 1)th piles (always taking an odd pile)
                                or the second, fourth, sixth, ... Nth piles (always taking an even pile);
                             
          c2.) odd number of stones;
          => sum of stones from odd piles and sum of stones from even piles are distinct;
          => first player can always pick the piles with a maximum number of stones in total;
                             
          From c1.) and c2.) results that the first player always wins the game;
        */
        return true;
    }
};