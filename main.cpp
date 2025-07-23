#include "Extracted_data.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    ifstream file("logged_data.csv");
    string line;
    
    // Skip header line if it exists
    getline(file, line);
    
    vector<DataRecord> records;
    
    // Read all records from CSV
    while (getline(file, line)) {
        stringstream ss(line);
        string field;
        vector<string> fields;
        
        // Split by comma
        while (getline(ss, field, ',')) {
            fields.push_back(field);
        }
        
        // Make sure we have enough fields
        if (fields.size() >= 5) {
            DataRecord record(fields[0], fields[1], fields[2], fields[3], fields[4]);
            records.push_back(record);
        }
    }
    
    // Find and display records with specific signal strength
    string targetSignal = "-75dBm";  // Change this to your target signal strength
    int count = 0;
    
    cout << "Records with signal strength " << targetSignal << ":" << endl;
    
    // Traditional for loop - easier to understand
    for (int i = 0; i < records.size(); i++) {
        if (records[i].matchesSignal(targetSignal) && count < 5) {
            records[i].display();
            count++;
        }
    }
    
    return 0;
}