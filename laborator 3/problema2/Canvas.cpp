#include "Canvas.h"
#include <cmath>

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			if ((i-x)*(i-x) + (j-y)*(j-y) <= ray*ray + 4 && (i - x)*(i - x) + (j - y)*(j - y) >= ray*ray - 4)
				this->matrix[i][j] = ch;
		}
	}
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray + 4 )
			{
				this->matrix[i][j] = ch;
			}
		}
	}
}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		this->matrix[top][i] = ch;
		this->matrix[bottom][i] = ch;
	}
	for (int i = top+1; i < bottom; i++)
	{
		this->matrix[i][right] = ch;
		this->matrix[i][left] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i < right; i++)
	{
		for (int j = top; j < bottom; j++)
		{
			this->matrix[i][j] = ch;
		}
	}
}
void Canvas::SetPoint(int x, int y, char ch)
{
	this->matrix[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int m_new = 2 * (y2 - y1);
	int slope_error_new = m_new - (x2 - x1);
	for (int x = x1, y = y1; x <= x2; x++) {
		this->matrix[x][y] = ch;


		slope_error_new += m_new; 
		if (slope_error_new >= 0) {
			y++;
			slope_error_new -= 2 * (x2 - x1);
		}
	}
}
void Canvas::Print()
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			printf("%c", this->matrix[i][j]);
		}
		printf("\n");
	}
}
void Canvas::Clear()
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			this->matrix[i][j] = '.';
		}
	}
}
