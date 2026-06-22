//
// Created by aleks on 22.06.2026.
//

#include "GridLoader.h"


bool GridLoader::has(const std::string& s, char c) { return s.find(c) != string::npos; };

Cell GridLoader::parseCell(const string& s) {
    Cell c = Cell(has(s, 'N'), has(s, 'S'), has(s, 'E'), has(s, 'W')); //NSEW
    return c;
}



