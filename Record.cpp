//
// Created by Aliez on 2018/7/7.
//

#include "Record.h"
#include <iostream>
#include <fstream>

using namespace std;

Record::Record() {
    load();
}

void Record::load() {
    ifstream LOAD("ranking.txt");
    string line;
    while (getline(LOAD, line)) {
        records.push_back(atoi(line.c_str()));
    }
    LOAD.close();
}

void Record::save() {
    ofstream SAVE("ranking.txt");
    for (int record : records) {
        SAVE << record << endl;
    }
    SAVE.close();
}

void Record::add(int usingTime) {
    records.push_back(usingTime);
    sort(records.begin(), records.end(),less<int>());
    save();
}

void Record::print() {
    if (records.empty()){
        cout << "nobody has passed" << endl;
    } else {
        cout << " Records " << endl;
        for (int i = 0; i < records.size(); ++i) {
            cout << "NO." << i + 1 << ": " << (records[i]) / 60 << " minutes " << (records[i]) % 60 << " seconds " << endl;
        }
    }
}
