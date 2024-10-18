#include "dataset.hpp"
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include "csv.hpp"

//Loads data frfom csv
void QuakeDataset::loadData(const string& filename) {
    csv::CSVReader reader(filename);
    double strongest = 0.0;
    for (auto& row: reader) {
        string time = row["time"].get<>();
        double latitude = row["latitude"].get<double>();
        double longitude = row["longitude"].get<double>();
        double depth = row["depth"].get<double>();
        double mag = row["mag"].get<double>();
        
        //Used online resource:
        //https://stackoverflow.com/questions/43193868/is-it-fine-to-use-variables-after-they-being-used-as-arguments-of-emplace-back
        data.emplace_back(time,latitude,longitude,depth,mag);
    }
}

// Returns the number of quakes in the dataset
int QuakeDataset::size() {
    return data.size();
}

// Find and return the strongest quake by mag
Quake QuakeDataset::strongest() {

    //Checks if data vector is empty
    //https://www.geeksforgeeks.org/how-to-check-if-vector-is-empty-in-cpp/
    if (data.empty()){
        throw runtime_error("No data in vector");
    }
    //Set strongest quake to teh first quake in the vector
    Quake* strongestQuake = &data[0];
    //Compare each quake with the current strongest
    for (auto& quake: data)
    {
        if (quake.getMagnitude() > strongestQuake->getMagnitude())
        {
           strongestQuake = &quake;
        }
    }
    return *strongestQuake;
}

// Find and return the shallowest quake by depth
Quake QuakeDataset::shallowest() {
    //Similar to strongest()
    if (data.empty()){
        throw runtime_error("No data in vector");
    }
    Quake* shallowestQuake = &data[0];
    for (auto& quake: data)
    {
        if (quake.getDepth() < shallowestQuake->getDepth())
        {
           shallowestQuake = &quake;
        }
    }
    return *shallowestQuake;
}

// Return the average depth of all quakes
double QuakeDataset::meanDepth() {
    //Similar to strongest()
    if (data.empty()){
        throw runtime_error("No data in vector");
    }
    //increases the mean depth by every depth
    double meanDepthQuake = 0.0;
    int counter = 0;
    for (auto& quake: data)
    {
        meanDepthQuake += quake.getDepth();
        counter += 1;
    }
    //Then returns the mean of the final number
    return meanDepthQuake/counter;
}

// Return the average magnitude of all quakes
double QuakeDataset::meanMagnitude() {
    //Similar to mean depth
    if (data.empty()){
        throw runtime_error("No data in vector");
    }
    double meanMagQuake = 0.0;
    int counter = 0;
    for (auto& quake: data)
    {
        meanMagQuake += quake.getMagnitude();
        counter += 1;
    }
    return meanMagQuake/counter;
}
