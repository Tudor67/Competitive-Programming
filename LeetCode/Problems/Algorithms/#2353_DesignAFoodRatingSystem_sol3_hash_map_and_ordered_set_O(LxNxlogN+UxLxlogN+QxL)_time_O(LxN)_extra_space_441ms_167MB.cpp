class FoodRatings {
private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineToRatingFoodSet;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int N = foods.size();
        for(int i = 0; i < N; ++i){
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToRatingFoodSet[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        cuisineToRatingFoodSet[cuisine].erase({-foodToRating[food], food});
        foodToRating[food] = newRating;
        cuisineToRatingFoodSet[cuisine].insert({-foodToRating[food], food});
    }
    
    string highestRated(string cuisine) {
        return cuisineToRatingFoodSet[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */