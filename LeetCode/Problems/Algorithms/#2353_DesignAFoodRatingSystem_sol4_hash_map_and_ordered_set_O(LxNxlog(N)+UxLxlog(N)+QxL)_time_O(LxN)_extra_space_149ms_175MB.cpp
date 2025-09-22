class FoodRatings {
private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodToRating;
    unordered_map<string, set<pair<int, string>>> cuisineToRatingFoodSet;

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < (int)foods.size(); ++i){
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
            cuisineToRatingFoodSet[foodToCuisine[foods[i]]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        cuisineToRatingFoodSet[cuisine].erase({-oldRating, food});
        foodToRating[food] = newRating;
        cuisineToRatingFoodSet[cuisine].insert({-newRating, food});
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