#include "Canvas.h"
#include <stdlib.h>
#include <stdio.h>
#include <cstdarg>

Canvas::Canvas(int lines,int columns)
{
    this->lines = lines; this->columns = columns;
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < columns; j++)
            this->matrix[i][j] = '.';
}

void Canvas::set_pixel(int x, int y, char value) 
{
    this->matrix[x][y] = value;
}

void Canvas::set_pixels(int count ...)
{
    int x, y;
    char ch;
    va_list vl;
    va_start(vl, count);
    for (int i = 0; i < count; i++)
    {
        x = va_arg(vl, int);
        y = va_arg(vl, int);
        ch = va_arg(vl, char);
        set_pixel(x, y, ch);
    }
    va_end(vl);
}

void Canvas::clear()
{
    for (int i = 0; i < this->lines; i++)
        for (int j = 0; j < this->columns; j++)
            this->matrix[i][j] = '.';
}

void Canvas::print() const
{
    for (int i = 0; i < this->lines; i++)
    {
        for (int j = 0; j < this->columns; j++)
            printf("%c", this->matrix[i][j]);
        printf("\n");
    }
        

}