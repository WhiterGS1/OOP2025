#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <cstdarg>

class Canvas {
    char matrix[50][50];
    int lines, columns;
public:
    // contructor will call the clear method
    Canvas(int lines, int columns);

    // set the character at the position x and y to value
    void set_pixel(int x, int y, char value);

    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};