class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        int totalCandies = 0;
        if(N == 1){
            totalCandies = 1;
        }else{
            int prevLen = 0;
            int len = 0;
            int i = 0;
            while(i < N - 1){
                if(ratings[i] == ratings[i + 1]){
                    if(prevLen == 0){
                        totalCandies += 1;
                    }
                    while(i + 1 < N && ratings[i] == ratings[i + 1]){
                        i += 1;
                        totalCandies += 1;
                    }
                    prevLen = 1;
                }else if(ratings[i] < ratings[i + 1]){
                    len = 1;
                    while(i + 1 < N && ratings[i] < ratings[i + 1]){
                        i += 1;
                        len += 1;
                    }
                    totalCandies += len * (len + 1) / 2;
                    if(prevLen >= 1){
                        totalCandies -= 1;
                    }
                    prevLen = len;
                }else if(ratings[i] > ratings[i + 1]){
                    len = 1;
                    while(i + 1 < N && ratings[i] > ratings[i + 1]){
                        i += 1;
                        len += 1;
                    }
                    totalCandies += len * (len + 1) / 2;
                    if(prevLen < len){
                        totalCandies -= prevLen;
                    }else{
                        totalCandies -= len;
                    }
                    prevLen = len;
                }
            }
        }
        return totalCandies;
    }
};

/*
ratings: 1 2 5 9 7 6 5 4 3 2 1 
candies: 1 2 3 8 7 6 5 4 3 2 1 

ratings: 1 2 5 9 7 6 6 5 4 3 2 1
candies: 1 2 3 4 2 1 6 5 4 3 2 1
*/