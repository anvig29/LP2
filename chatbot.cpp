#include <iostream>
#include <string>
#include <map>

using namespace std;

class Chatboat {
private:
    string name;
    string greetings[2];
    string commonQuestions[3];
    map<string, string> responses;
    string interactions[100]; // Assuming maximum 100 interactions

public:
    // Constructor
    Chatboat(string boatName) : name(boatName) {
        // Default greetings
        greetings[0] = "Hello! How can I assist you today?";
        greetings[1] = "Welcome! How may I help you?";

        // Common questions and responses
        commonQuestions[0] = "What are your business hours?";
        responses["What are your business hours?"] = "Our business hours are from 9:00 AM to 5:00 PM, Monday to Friday.";

        commonQuestions[1] = "Do you offer shipping services?";
        responses["Do you offer shipping services?"] = "Yes, we offer shipping services to most locations.";

        commonQuestions[2] = "How can I contact customer support?";
        responses["How can I contact customer support?"] = "You can contact our customer support team at support@example.com or by calling 1-800-123-4567.";
    }

    // Method to set name
    void setName(string boatName) {
        name = boatName;
    }

    // Method to get name
    string getName() const {
        return name;
    }

    // Method to add a custom greeting
    void addGreeting(string greeting) {
        greetings[1] = greeting;
    }

    // Method to display a random greeting
    void greet() const {
        int index = rand() % 2; // Two default greetings
        cout << greetings[index] << endl;
    }

    // Method to interact with the customer
    void interact() {
        greet();
        string userInput;
        getline(cin, userInput); // Get user input

        // Store interaction
        static int interactionCount = 0;
        interactions[interactionCount++] = userInput;

        // Check if the user input matches a common question
        for (int i = 0; i < 3; ++i) {
            if (userInput.find(commonQuestions[i]) != string::npos) {
                cout << responses[commonQuestions[i]] << endl;
                return;
            }
        }

        // If no common question matched, provide a generic response
        cout << "Thank you for your query. Our team will get back to you shortly." << endl;
    }

    // Method to display previous interactions
    void displayInteractions() const {
        cout << "Previous Interactions:" << endl;
        for (int i = 0; interactions[i] != ""; ++i) {
            cout << "- " << interactions[i] << endl;
        }
    }
};

int main() {
    // Create a Chatboat object
    Chatboat myChatboat("CustomerServiceBot");

    // Add custom greetings
    myChatboat.addGreeting("Hi there! How can I assist you today?");
    myChatboat.addGreeting("Greetings! What can I do for you?");

    // Interact with the customer
    myChatboat.interact();

    // Display previous interactions
    myChatboat.displayInteractions();

    return 0;
}
