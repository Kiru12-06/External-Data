#include "Extracted_data.h"
#include <iostream>
using namespace std;

DataRecord::DataRecord(string f1, string f2, string signal, string f4, string f5) 
    : field1(f1), field2(f2), signalStrength(signal), field4(f4), field5(f5) {}

string DataRecord::getSignalStrength() const {
    return signalStrength;
}

bool DataRecord::matchesSignal(const string& target) const {
    return signalStrength == target;
}

void DataRecord::display() const {
    cout << "Field1: " << field1 << ", Field2: " << field2 
         << ", Signal: " << signalStrength << ", Field4: " << field4 
         << ", Field5: " << field5 << endl;
}