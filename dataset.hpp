// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include <string>
#include "quake.hpp"

using namespace std;

class QuakeDataset
{
  public:
    // Inline default constructor
    inline QuakeDataset(){};

    // Inline constructor that loads data from a file
    inline QuakeDataset(const string& filename) {
        loadData(filename);
    }

    // Inline operator for accessing quakes
    inline Quake& operator[](int index) {
        if (index < 0 || index >= data.size()) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    // Non-inline methods
    void loadData(const string& filename);
    // Returns number of quakes
    int size();  
    // Returns the strongest quake                      
    Quake strongest(); 
    // Returns the shallowest quake                
    Quake shallowest();  
    // Returns the average depth              
    double meanDepth();                
    // Returns the average magnitude
    double meanMagnitude();           

  private:
    vector<Quake> data;
};
