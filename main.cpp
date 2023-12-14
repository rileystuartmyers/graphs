#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

#include "graphs.h"

int main() {

    std::ofstream ofs("output.txt");
    std::ifstream ifs("input.txt");

    int size;

    std::string input_string;

    std::getline(ifs, input_string);

    size = std::stoi(input_string);
    graph_map g(size);

    int temp_x;
    int temp_y;

    int input_size = 0;

    while (std::getline(ifs, input_string)) {
 
        std::istringstream iss(input_string);
        
        iss >> temp_x;
        iss >> temp_y;
        g.push(temp_x, temp_y);

        ++input_size;

    }

    g.Cycle(ofs, input_size);

    g.dealloc();

    return 0;

}