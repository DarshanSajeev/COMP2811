// COMP2811 Coursework 1: Quake class

#include <stdexcept>
#include "quake.hpp"

using namespace std;


Quake::Quake(const string& tm, double lat, double lon, double dep, double mag):
  time(tm), latitude(lat), longitude(lon), depth(dep), magnitude(mag)
{
  //Checks if lat and long are within their bounds
    if (lat > MAX_LATITUDE || lat < MIN_LATITUDE) {
        throw std::invalid_argument("Latitude out of range");
    }
    if (lon > MAX_LONGITUDE || lon < MIN_LONGITUDE) {
        throw std::invalid_argument("Longitude out of range");
    }

    //Checks if depth and mag are within their bounds
    if (dep < 0) {
        throw std::invalid_argument("Depth cannot be negative");
    }
    if (mag < 0) {
        throw std::invalid_argument("Magnitude cannot be negative");
    }
}


ostream& operator<<(ostream& out, const Quake& quake)
{
  return out << "Time: " << quake.getTime()
             << "\nLatitude: " << quake.getLatitude() << " deg"
             << "\nLongitude: " << quake.getLongitude() << " deg"
             << "\nDepth: " << quake.getDepth() << " km"
             << "\nMagnitude: " << quake.getMagnitude() << endl;
}
