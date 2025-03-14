#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <cstdarg>

class Canvas
{
    char matrix[51][51];
    int width, height;
public:
    Canvas() {
        this->width = 20;this->height = 20;
        for (int i = 0; i < this->width; i++)
            for (int j = 0; j < this->height; j++)
                this->matrix[i][j] = '.';
    };
    Canvas(int width, int height) {
        this->width = width; this->height = height;
        for (int i = 0; i < this->width; i++)
            for (int j = 0; j < this->height; j++)
                this->matrix[i][j] = '.';
    };
    
    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print(); // shows what was printed
    void Clear(); // clears the canvas
};

