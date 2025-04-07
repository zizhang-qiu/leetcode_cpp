#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class FoodRatings {
 public:
  FoodRatings(vector<string>& foods, vector<string>& cuisines,
              vector<int>& ratings) {
    for (int i = 0; i < foods.size(); i++) {
      food_to_cuisine[foods[i]] = cuisines[i];
      food_to_rating[foods[i]] = ratings[i];
      auto cuisine = cuisines[i];
      auto rating = ratings[i];
      auto food = foods[i];
      cuisine_to_rating_and_food[cuisine].push_back({rating, food});
    }
    for (auto& p : cuisine_to_rating_and_food) {
      sort(p.second.begin(), p.second.end(), 
      [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        if (a.first == b.first) {
          return a.second < b.second;
        }
        return a.first > b.first;
      });
    }
  }

  void changeRating(string food, int newRating) {
    auto oldRating = food_to_rating[food];
    food_to_rating[food] = newRating;
    auto cuisine = food_to_cuisine[food];
    auto& foods = cuisine_to_rating_and_food[cuisine];
    auto it = find_if(foods.begin(), foods.end(),
                      [&](const auto& p) { return p.second == food; });
    if (it != foods.end()) {
      it->first = newRating;
      
      sort(foods.begin(), foods.end(), 
      // greater<pair<int, string>>()
      [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
        if (a.first == b.first) {
          return a.second < b.second;
        }
        return a.first > b.first;
      }
    );
    }
  }

  string highestRated(string cuisine) {
    auto& foods = cuisine_to_rating_and_food[cuisine];
    if (foods.empty()) {
      return "";
    }
    return foods[0].second;
  }

 private:
  std::unordered_map<std::string, std::string> food_to_cuisine;
  std::unordered_map<std::string, int> food_to_rating;
  std::unordered_map<std::string, std::vector<std::pair<int, std::string>>>
      cuisine_to_rating_and_food;
};

/**
   * Your FoodRatings object will be instantiated and called as such:
   * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
   * obj->changeRating(food,newRating);
   * string param_2 = obj->highestRated(cuisine);
   */

int main(int argc, char const* argv[]) {
  /* code */
  // vector<string> foods = {"kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"};
  // vector<string> cuisines = {"korean", "japanese", "japanese", "greek", "japanese", "korean"};
  // vector<int> ratings = {9, 12, 8, 15, 14, 7};
  // FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
  // cout << obj->highestRated("korean") << endl;
  // cout << obj->highestRated("japanese") << endl;
  // obj->changeRating("sushi", 16);
  // cout << obj->highestRated("japanese") << endl;
  // obj->changeRating("ramen", 16);
  // cout << obj->highestRated("japanese") << endl;
  vector<string> foods = {"cpctxzh","bryvgjqmj","wedqhqrmyc","ee","lafzximxh","lojzxfel","flhs"};
  vector<string> cuisines = {"wbhdgqphq","wbhdgqphq","mxxajogm","wbhdgqphq","wbhdgqphq","mxxajogm","mxxajogm"};
  vector<int> ratings = {15,5,7,16,16,10,13};
  FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
  obj->changeRating("lojzxfel",1);
  cout << obj->highestRated("mxxajogm") << endl;
  cout << obj->highestRated("wbhdgqphq") << endl;

  
  return 0;
}
