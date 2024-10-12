// COMP2811 Coursework 1: QuakeDataset class

#pragma once

#include <vector>
#include "quake.hpp"
#include "dataset.hpp"

using namespace std;

void QuakeDataset::loadData(string& filename){

}

Quake QuakeDataset::strongest(){
    return Quake("2024-20-09T00:00:01Z, 0.0,0.0,0.0,0.0");
}

int QuakeDataset::size(){return 0;}

double QuakeDataset::meanDepth(){

}

double QuakeDataset::meanMagnitude(){
    
}
