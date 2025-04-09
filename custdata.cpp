#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

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

    double getPrice() const { return price; }
    string getName() const { return name; }

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




class CustomerData {
private:
    int custId;
    string custName;
    string email;
    string phoneNo;
    string address;

public:
    CustomerData(int id, string name, string mail, string phone, string addr)
        : custId(id), custName(name), email(mail), phoneNo(phone), address(addr) {}

    string getName() const { return custName; }

    void placeOrder(const PizzaData& pizza) const {
        cout << "\n🍕 Order Placed by: " << custName << endl;
        pizza.displayPizza();
    }

    void makePayment(double amount) const {
        cout << "💳 Payment of ₹" << amount << " made successfully by " << custName << "\n";
    }
};




class OrderData {
private:
    int orderId;
    CustomerData customer;
    PizzaData pizza;
    string orderDate;
    double totalAmount;

    string getCurrentDate() const {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }

public:
    OrderData(int id, CustomerData cust, PizzaData pz)
        : orderId(id), customer(cust), pizza(pz), totalAmount(0) {
        orderDate = getCurrentDate();
        calculateTotalAmount();
    }

    void calculateTotalAmount() {
        totalAmount = pizza.getPrice();
    }

    void updateTotalAmount(double discount) {
        totalAmount -= discount;
        if (totalAmount < 0) totalAmount = 0;
    }

    double getTotalAmount() const { return totalAmount; }

    void displayOrder() const {
        cout << "\n🧾 Order ID: " << orderId << "\nCustomer: " << customer.getName();
        cout << "\nPizza: " << pizza.getName();
        cout << "\nOrder Date: " << orderDate;
        cout << "Total Amount: ₹" << totalAmount << "\n---------------------------\n";
    }
};




class PaymentData {
private:
    int paymentId;
    int orderId;
    double amount;
    string paymentDate;

    string getCurrentDate() const {
        time_t now = time(0);
        char* dt = ctime(&now);
        return string(dt);
    }

public:
    PaymentData(int pid, int oid, double amt)
        : paymentId(pid), orderId(oid), amount(amt) {
        paymentDate = getCurrentDate();
    }

    void displayPayment() const {
        cout << "\n💵 Payment ID: " << paymentId << "\nOrder ID: " << orderId;
        cout << "\nAmount: ₹" << amount << "\nDate: " << paymentDate << "\n---------------------------\n";
    }
};




class StaffData {
private:
    int staffId;
    string firstName;
    string lastName;
    string email;
    string phoneNumber;
    string position;

public:
    StaffData(int id, string f, string l, string e, string p, string pos)
        : staffId(id), firstName(f), lastName(l), email(e), phoneNumber(p), position(pos) {}

    void addPizza(vector<PizzaData>& menu, const PizzaData& pizza) {
        menu.push_back(pizza);
        cout << "🍕 Staff added new pizza: " << pizza.getName() << endl;
    }

    void removePizza(vector<PizzaData>& menu, const string& pizzaName) {
        auto it = remove_if(menu.begin(), menu.end(), [&](PizzaData& pz) {
            return toLower(pz.getName()) == toLower(pizzaName);
        });

        if (it != menu.end()) {
            menu.erase(it, menu.end());
            cout << "🗑️ Staff removed pizza: " << pizzaName << endl;
        } else {
            cout << "❌ Pizza not found: " << pizzaName << endl;
        }
    }

    void updatePizza(vector<PizzaData>& menu, const string& pizzaName, double newPrice) {
        for (auto& pizza : menu) {
            if (toLower(pizza.getName()) == toLower(pizzaName)) {
                cout << "🔄 Updated price of " << pizzaName << " from ₹" << pizza.getPrice() << " to ₹" << newPrice << endl;
                return;
            }
        }
        cout << "❌ Pizza not found: " << pizzaName << endl;
    }
};




int main() {
    vector<string> pizzaNames = {
        "Margherita", "Pepperoni", "Veggie", "BBQ Chicken", "Paneer Tikka", "Farmhouse",
        "Cheese Burst", "Mexican", "Tandoori Paneer", "Chicken Tikka", "Mushroom Delight",
        "Double Cheese", "Peri Peri Chicken", "Pasta Pizza", "Meat Feast", "Hawaiian",
        "Supreme", "Cheesy Garlic", "Italian Special", "Spicy Chicken", "Kebab Pizza"
    };

    vector<PizzaData> pizzaMenu;
    for (int i = 0; i < pizzaNames.size(); ++i) {
        pizzaMenu.emplace_back(i + 1, pizzaNames[i], "Delicious pizza with rich toppings", 199 + (i * 10), vector<string>{"Cheese", "Tomato Sauce"});
    }

    for (auto& pizza : pizzaMenu) pizza.displayPizza();

    CustomerData customer(1, "Uday", "uday@example.com", "9876543210", "Gurugram");
    customer.placeOrder(pizzaMenu[0]);
    customer.makePayment(pizzaMenu[0].getPrice());

    OrderData order(101, customer, pizzaMenu[0]);
    order.displayOrder();

    PaymentData payment(1001, 101, order.getTotalAmount());
    payment.displayPayment();

    StaffData staff(1, "John", "Doe", "john@example.com", "9999999999", "Manager");
    staff.addPizza(pizzaMenu, PizzaData(999, "Staff Special", "Chef's secret recipe", 299, {"Cheese", "Mystery Sauce"}));
    staff.removePizza(pizzaMenu, "Pepperoni");
    staff.updatePizza(pizzaMenu, "Margherita", 225);

    return 0;
}
