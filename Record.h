//
// Created by Aliez on 2018/7/7.
//

#ifndef INC_2048_RECORD_H
#define INC_2048_RECORD_H

#include <vector>

class Record {
private:
    std::vector<int> records;
public:
    Record();
    ~Record() = default;

    void load();
    void save();
    void add(int usingTime);
    void print();
};


#endif //INC_2048_RECORD_H
