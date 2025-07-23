#ifndef EXTRACTED_DATA_H
#define EXTRACTED_DATA_H
#include <string>
using namespace std;

class DataRecord {
private:
    string field1;
    string field2;
    string signalStrength;
    string field4;
    string field5;

public:
    DataRecord(string f1, string f2, string signal, 
               string f4, string f5);
    
    string getSignalStrength() const;
    void display() const;
    bool matchesSignal(const string& target) const;
};

#endif