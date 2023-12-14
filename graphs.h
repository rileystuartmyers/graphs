#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>

#ifndef GRAPHS_H
#define GRAPHS_H

class graph_map {

    int **matrix;
    int size;

    public:

    graph_map(int);
    void push(int, int);
    void print();
    void dealloc();
    void Cycle(std::ofstream&, int);

    bool Empty_Row(int);
    bool Empty_Col(int);

};

graph_map::graph_map(int _size) {

    size = _size;
    
    matrix = new int*[size];

    for (int i = 0; i < size; ++i) {

        matrix[i] = new int[size];

    }
    
    for (int x = 0; x < size; ++x) {

        for (int y = 0; y < size; ++y) {

            matrix[x][y] = 0;

        }

    }

    return;

}

void graph_map::push(int x, int y) {

    matrix[x][y] = 1;

}

void graph_map::print() {

    for (int y = size - 1; y >= 0; --y) {

        for (int x = 0; x < size; ++x) {

            std::cout << matrix[x][y] << " ";

        }

        std::cout << std::endl;

    }

}

void graph_map::dealloc() {

    for (int i = 0; i < size; ++i) {

        delete[] matrix[i];

    }

    delete[] matrix;

    size = 0;

    return;

}

bool Dupes_In_Vector(std::vector<int> input_vector) {

    std::sort(input_vector.begin(), input_vector.end());

    for (int i = 0; i < input_vector.size() - 1; ++i) {

        if (input_vector[i] == input_vector[i + 1]) {

            return true;

        }

    }

    return false;

}

bool graph_map::Empty_Row(int y) {

    for (int i = 0; i < size; ++i) {

        if (matrix[i][y] == 1) {

            return false;

        }

    }

    return true;

}

bool graph_map::Empty_Col(int x) {

    for (int i = 0; i < size; ++i) {

        if (matrix[x][i] == 1) {

            return false;

        }

    }
    
    return true;

}

void graph_map::Cycle(std::ofstream& ofs, int input_size) {

    int del;

    while (input_size > 0) {

        int del = 0;

        for (int y = 0; y < size; ++y) {

            for (int x = 0; x < size; ++x) {

                if (matrix[x][y] == 0) {

                    continue;

                }

                if (Empty_Col(y)) {

                    matrix[x][y] = 0;
                    ++del;
                    --input_size;

                }

            }

        }

        if (del == 0) {

            ofs << "TRUE";

            return;

        }

    }

    ofs << "FALSE";

    return;

}

#endif
