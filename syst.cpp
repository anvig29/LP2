#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> symptomChecker = {
    {"headache", "Possible causes: stress, dehydration, migraine."},
    {"fever", "Possible causes: infection, flu, cold."},
    // Add more entries as needed
};

int main() {
    string symptom;
    cout << "Enter your symptom: ";
    cin >> symptom;

    if (symptomChecker.find(symptom) != symptomChecker.end()) {
        cout << "Possible causes: " << symptomChecker[symptom] << endl;
    } else {
        cout << "No information available for \"" << symptom << "\"" << endl;
    }

    return 0;
}
