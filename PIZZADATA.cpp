#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string toLower(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

class PizzaData {
private:
    int pizzaId;
    string name;
    string description;
    double price;
    vector<string> ingredients;

public:
    PizzaData(int id, string n, string desc, double p, vector<string> ings)
        : pizzaId(id), name(n), description(desc), price(p), ingredients(ings) {}

    void addIngredient(const string& ingredient) {
        if (ingredient.empty()) {
            cout << "❌ Ingredient cannot be empty.\n";
            return;
        }

        string ingredientLower = toLower(ingredient);
        auto exists = find_if(ingredients.begin(), ingredients.end(),
            [&ingredientLower](const string& ing) {
                return toLower(ing) == ingredientLower;
            });

        if (exists == ingredients.end()) {
            ingredients.push_back(ingredient);
            cout << "✅ Added: " << ingredient << " to " << name << endl;
        } else {
            cout << "⚠️ " << ingredient << " is already in " << name << endl;
        }
    }

    void removeIngredient(const string& ingredient) {
        string ingredientLower = toLower(ingredient);
        auto it = find_if(ingredients.begin(), ingredients.end(),
            [&ingredientLower](const string& ing) {
                return toLower(ing) == ingredientLower;
            });

        if (it != ingredients.end()) {
            ingredients.erase(it);
            cout << "🗑️ Removed: " << ingredient << " from " << name << endl;
        } else {
            cout << "❌ " << ingredient << " not found in " << name << endl;
        }
    }

    void displayPizza() const {
        cout << "Pizza ID: " << pizzaId << endl;
        cout << "Name: " << name << endl;
        cout << "Description: " << description << endl;
        cout << "Price: ₹" << price << endl;
        cout << "Ingredients: ";
        for (const auto& ing : ingredients) {
            cout << ing << ", ";
        }
        cout << "\n---------------------------\n";
    }
};

int main() {
    vector<PizzaData> pizzaMenu = {
        PizzaData(1, "Margherita", "Classic cheese and tomato pizza", 199, {"Cheese", "Tomato"}),
        PizzaData(2, "Pepperoni", "Topped with spicy pepperoni slices", 209, {"Cheese", "Pepperoni"}),
        PizzaData(3, "Veggie", "Mixed vegetables and cheese", 219, {"Onions", "Capsicum", "Tomato", "Cheese"}),
        PizzaData(4, "BBQ Chicken", "BBQ sauce and chicken topping", 229, {"BBQ Sauce", "Chicken", "Cheese"}),
        PizzaData(5, "Paneer Tikka", "Indian style paneer tikka pizza", 239, {"Paneer", "Onions", "Peppers", "Spices"}),
        PizzaData(6, "Farmhouse", "Loaded with veggies from the farm", 249, {"Capsicum", "Tomato", "Corn", "Cheese"}),
        PizzaData(7, "Cheese Burst", "Extra cheesy base and topping", 259, {"Double Cheese", "Oregano"}),
        PizzaData(8, "Mexican", "Spicy Mexican flavors", 269, {"Jalapenos", "Capsicum", "Corn", "Cheese"}),
        PizzaData(9, "Tandoori Paneer", "Tandoori-flavored paneer and veggies", 279, {"Paneer", "Onions", "Tandoori Sauce"}),
        PizzaData(10, "Chicken Tikka", "Spicy chicken tikka pizza", 289, {"Chicken", "Onions", "Spices", "Cheese"}),
        PizzaData(11, "Mushroom Delight", "Creamy mushrooms and cheese", 299, {"Mushrooms", "Cheese", "Cream"}),
        PizzaData(12, "Double Cheese", "Twice the cheese, double the fun", 309, {"Mozzarella", "Cheddar", "Oregano"}),
        PizzaData(13, "Peri Peri Chicken", "Peri-peri chicken toppings", 319, {"Peri Peri Chicken", "Capsicum", "Cheese"}),
        PizzaData(14, "Pasta Pizza", "Fusion of pasta and pizza", 329, {"Pasta", "Tomato Sauce", "Cheese"}),
        PizzaData(15, "Meat Feast", "A mix of all kinds of meats", 339, {"Chicken", "Pepperoni", "Sausage", "Ham"}),
        PizzaData(16, "Hawaiian", "Pineapple and ham delight", 349, {"Ham", "Pineapple", "Cheese"}),
        PizzaData(17, "Supreme", "Loaded with everything", 359, {"Veggies", "Meat", "Olives", "Cheese"}),
        PizzaData(18, "Cheesy Garlic", "Garlic-flavored cheesy base", 369, {"Garlic", "Cheese", "Butter"}),
        PizzaData(19, "Italian Special", "Traditional Italian flavors", 379, {"Tomatoes", "Basil", "Olive Oil", "Cheese"}),
        PizzaData(20, "Spicy Chicken", "Extra spicy chicken pizza", 389, {"Spicy Chicken", "Onions", "Jalapenos"}),
        PizzaData(21, "Kebab Pizza", "Kebab meat and Indian spices", 399, {"Kebab", "Onions", "Spices", "Cheese"})
    };

    for (auto& pizza : pizzaMenu) {
        pizza.displayPizza();
    }

    // Example interaction
    pizzaMenu[0].addIngredient("Oregano");
    pizzaMenu[2].removeIngredient("Capsicum");

    return 0;
}
