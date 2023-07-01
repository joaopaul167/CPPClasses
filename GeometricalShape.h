#pragma once
// Exercise 2
	// “Create class and sub - class objects which represent different geometrical shapes, 
	// such as Rectangle sand Squares”
#include <iostream>
#include <string>
#include <vector>
struct Vector2
{
	float x;
	float y;
};

// Shape might have and array of vertex
// vertex have position (x,y) 

typedef std::vector<Vector2> VertexArray;

typedef std::vector<std::vector<std::string>> Matrix;

typedef std::pair<Vector2, Vector2> Line;

class Board {
public:
	Board(int size_x, int size_y);
	~Board();
	void Draw();
	void Clear();
	int getWidth();
	int getHeight();
	void Update(VertexArray shape, std::vector<Line> indices);
private:
	Matrix m_Board;
};

class Shape {
public:
	Shape(VertexArray* shape, std::vector<Line>* indices);
	~Shape();


	VertexArray getShape();
	std::vector<Line> getIndices();
	void setShape(VertexArray shape);
	void setIndices(std::vector<Line> indices);
private:
	VertexArray m_Shape;
	std::vector<Line> m_Indices;
};