// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include "quake.hpp"

using namespace std;

class QuakeDataset
{
  public:
    inline QuakeDataset() = default;
    inline QuakeDataset(string& filename){
      loadData(filename);
    };
    // Specify prototypes or inlined methods here
    // (see UML diagram for what is required)

    inline void loadData(string& filename);

    int size(){}

    inline Quake& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    Quake strongest();

    Quake shallowest();

    double meanDepth(){}

    double meanMagnitude(){}

  private:
    std::vector<Quake> data;
};
