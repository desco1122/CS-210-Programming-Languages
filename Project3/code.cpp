//Daniel Escobedo - Project 3 - 6/18/2023

#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class ItemTracker {
private:
    map<string, int> frequencyMap;

public:
    ItemTracker() {}

    // This function reads the input file and stores the frequency of each item in the map
    void readInputFile(string fileName) {
        ifstream inputFile(fileName);
        string item;
        while (inputFile >> item) {
            frequencyMap[item]++;
        }
        inputFile.close();
    }

    //Function prints the frequency of a specific item
    void printItemFrequency(string item) {
        if (frequencyMap.count(item) > 0) {
            cout << item << " was purchased " << frequencyMap[item] << " times." << endl;
        }
        else {
            cout << item << " was not purchased." << endl;
        }
    }

    //Function prints the frequency of all items in the input file
    void printAllFrequencies() {
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            cout << itr->first << " was purchased " << itr->second << " times." << endl;
        }
    }

    //Function prints the frequency of all items in the input file as a histogram
    void printHistogram() {
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            cout << itr->first << " ";
            for (int i = 0; i < itr->second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    //Function writes the frequency map to a backup file
    void writeFrequencyFile(string fileName) {
        ofstream frequencyFile(fileName);
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            frequencyFile << itr->first << " " << itr->second << endl;
        }
        frequencyFile.close();
    }
};

int main() {
    ItemTracker tracker;
    tracker.readInputFile("CS210_Project_Three_Input_File.txt");

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print frequency of all items" << endl;
        cout << "3. Print histogram of all items" << endl;
        cout << "4. Exit program" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        switch (choice) {
        case 1:
        {
            string item;
            cout << "Enter item to search for: ";
            cin >> item;
            tracker.printItemFrequency(item);
            break;
        }
        case 2:
        {
            tracker.printAllFrequencies();
            break;
        }
        case 3:
        {
            tracker.printHistogram();
            break;
        }
        case 4:
        {tracker.writeFrequencyFile("frequency.dat");
        cout << "Exiting program..." << endl;
        break;}
        default:
        {cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        break;}
        }
    } while (choice != 4);

    return 0;
}