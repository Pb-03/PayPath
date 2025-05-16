#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

class Person {
public:
    string name;
    double balance;

    Person(string n, double b) : name(n), balance(b) {}
};

class DebtSettlement {
private:
    vector<Person> people;

    static double roundTo(double value, int places) {
        double factor = pow(10.0, places);
        return round(value * factor) / factor;
    }

    static bool compareMax(const Person& a, const Person& b) {
        return a.balance < b.balance;
    }

    static bool compareMin(const Person& a, const Person& b) {
        return a.balance > b.balance;
    }

public:
    void addPerson(const string& name, double balance) {
        people.emplace_back(name, balance);
    }

    void findPath() {
        while (true) {
            auto maxIt = max_element(people.begin(), people.end(), compareMax);
            auto minIt = min_element(people.begin(), people.end(), compareMin);

            if (maxIt == people.end() || minIt == people.end())
                break;

            double maxVal = maxIt->balance;
            double minVal = minIt->balance;

            if (maxVal <= 0 || minVal >= 0) break;

            double transactionAmount = roundTo(min(-minVal, maxVal), 2);

            cout << minIt->name << " needs to pay " << maxIt->name << ": " << fixed << setprecision(2) << transactionAmount << endl;

            maxIt->balance -= transactionAmount;
            minIt->balance += transactionAmount;
        }
    }
};

int main() {
    DebtSettlement ds;

    // Add people with balances
    ds.addPerson("A", -5.0);
    ds.addPerson("B", 25.0);
    ds.addPerson("C", -20.0);
    ds.addPerson("D", 25.0);
    ds.addPerson("E", -20.0);
    ds.addPerson("F", -5.0);

    ds.findPath();

    return 0;
}
