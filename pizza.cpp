

// Constructor Implementation
Pizza::Pizza(int id, string n, string desc, double p, vector<string> ing)
    : pizzaID(id), name(n), description(desc), price(p), ingredients(ing) {}

// Method to add an ingredient
void Pizza::addIngredient(string ingredient) {
    ingredients.push_back(ingredient);
    cout << ingredient << " added to " << name << " pizza.\n";
}

// Method to remove an ingredient
void Pizza::removeIngredient(string ingredient) {
    for (auto it = ingredients.begin(); it != ingredients.end(); ++it) {
        if (*it == ingredient) {
            ingredients.erase(it);
            cout << ingredient << " removed from " << name << " pizza.\n";
            return;
        }
    }
    cout << ingredient << " not found in " << name << " pizza.\n";
}

// Display pizza details
void Pizza::displayPizza() {
    cout << "\nPizza ID: " << pizzaID << "\nName: " << name
         << "\nDescription: " << description << "\nPrice: $" << price << "\nIngredients: ";
    for (const string &ing : ingredients) {
        cout << ing << " ";
    }
    cout << "\n";
}
