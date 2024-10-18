#include <iostream>
#include <stdexcept>
#include <iomanip> // For formatting table output
#include "dataset.hpp" // Your QuakeDataset class

using namespace std;

// Function to print stats from the csv
void printStatistics(QuakeDataset& dataset) {
    //no of lines in the file
    cout << "Number of quakes read from file: " << dataset.size() << endl;

    // Get the strongest quake
    Quake strongestQuake = dataset.strongest();
    cout << "\nStrongest Quake:" << endl;
    cout << "Time: " << strongestQuake.getTime() << endl;
    cout << "Latitude: " << strongestQuake.getLatitude() << endl;
    cout << "Longitude: " << strongestQuake.getLongitude() << endl;
    cout << "Depth: " << strongestQuake.getDepth() << endl;
    cout << "Magnitude: " << strongestQuake.getMagnitude() << endl;

    // Get the shallowest quake
    Quake shallowestQuake = dataset.shallowest();
    cout << "\nShallowest Quake:" << endl;
    cout << "Time: " << shallowestQuake.getTime() << endl;
    cout << "Latitude: " << shallowestQuake.getLatitude() << endl;
    cout << "Longitude: " << shallowestQuake.getLongitude() << endl;
    cout << "Depth: " << shallowestQuake.getDepth() << endl;
    cout << "Magnitude: " << shallowestQuake.getMagnitude() << endl;

    // Display the mean depth of the quakes
    cout << "\nMean Depth: " << dataset.meanDepth() << " km" << endl;

    // Display the mean magnitude of the quakes
    cout << "Mean Magnitude: " << dataset.meanMagnitude() << endl;
}

// Function to print table of all quakes
void printTable(QuakeDataset& dataset) {
    // Print table labels
    cout << left << setw(30) << "Time"
         << setw(15) << "Latitude"
         << setw(15) << "Longitude"
         << setw(10) << "Depth"
         << setw(10) << "Magnitude" << endl;

    // Print table rows
    for (int i = 0; i < dataset.size(); ++i) {
        Quake q = dataset[i];
        cout << left << setw(30) << q.getTime()
             << setw(15) << q.getLatitude()
             << setw(15) << q.getLongitude()
             << setw(10) << q.getDepth()
             << setw(10) << q.getMagnitude() << endl;
    }
}

// Function to print help information
void printHelp(const char* programName) {
    cout << "Usage: " << programName << " <CSV file> [--table]" << endl;
    cout << "Options:" << endl;
    cout << "  <CSV file>   The path to the CSV file containing quake data." << endl;
    cout << "  --table      Display all quake data in a table format." << endl;
    cout << endl;
    cout << "This application reads earthquake data from a CSV file and provides statistics such as:" << endl;
    cout << " - Number of quakes" << endl;
    cout << " - Strongest quake" << endl;
    cout << " - Shallowest quake" << endl;
    cout << " - Mean depth" << endl;
    cout << " - Mean magnitude" << endl;
    cout << "If the --table option is provided, all quakes will be displayed in tabular form." << endl;
}

int main(int argc, char* argv[]) {
    // Check if the help option is provided
    if (argc > 1 && std::string(argv[1]) == "--help") {
        printHelp(argv[0]);
        return 0;
    }

    // Check if the required CSV file argument is provided
    if (argc < 2) {
        cerr << "No CSV file! " << endl;
        return 1;
    }

    // Prints the table
    std::string csvFile = argv[1];

    bool tableMode = false;
    if (argc == 3 && std::string(argv[2]) == "--table")
    {
        tableMode = true;
    }

    // Create a QuakeDataset object and load the data from the CSV file
    QuakeDataset dataset(csvFile);

    if (tableMode) {
        // Print table of all quakes
        printTable(dataset);
    } else {
        // Print statistics
        printStatistics(dataset);
    }

    return 0;
}
