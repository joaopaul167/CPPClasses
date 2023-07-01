// Exercise 2
	// “Create class and sub - class objects which represent different geometrical shapes, 
	// such as Rectangle sand Squares”
#include "GeometricalShape.h"

#define LOG(x) (std::cout << x << "\n")


Board::Board(int size_x, int size_y) {
	std::vector<std::string> row(size_x, ",");
	Matrix matrix(size_y, row);
	m_Board = matrix;
}

Board::~Board(){}

void Board::Draw()
{
	for (int i = 0; i < m_Board[0].size(); i++)
	{
		for (int j = 0; j < m_Board.size(); j++)
		{
			std::cout << m_Board[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void Board::Clear()
{
	std::vector<std::string> row(m_Board[0].size(), ",");
	Matrix matrix(m_Board.size(), row);
	m_Board = matrix;
}

int Board::getWidth()
{
	return m_Board[0].size();
}
int Board::getHeight() 
{
	return m_Board.size();
}
// distance = sqrt((a.y - b.y * a.y - b.y) + (a.x - b.x * a.x - b.x))
float DistanceBetweenTwoVector2(Vector2 a, Vector2 b)
{
	float diffY = a.y - b.y;
	float diffX = a.x - b.x;
	return sqrt((diffX * diffX) + (diffY * diffY));
}

bool onLine(Line l1, Vector2 p)
{
	// Check whether p is on the line or not
	if (p.x <= std::max(l1.first.x, l1.second.x)
		&& p.x <= std::min(l1.first.x, l1.second.x)
		&& (p.y <= std::max(l1.first.y, l1.second.y)
			&& p.y <= std::min(l1.first.y, l1.second.y)))
		return true;

	return false;
}

int direction(Vector2 a, Vector2 b, Vector2 c)
{
	int val = (b.y - a.y) * (c.x - b.x)
		- (b.x - a.x) * (c.y - b.y);

	if (val == 0)

		// Collinear
		return 0;

	else if (val < 0)

		// Anti-clockwise direction
		return 2;

	// Clockwise direction
	return 1;
}

bool isIntersect(Line l1, Line l2)
{
	// Four direction for two lines and points of other line
	int dir1 = direction(l1.first, l1.second, l2.first);
	int dir2 = direction(l1.first, l1.second, l2.second);
	int dir3 = direction(l2.first, l2.second, l1.first);
	int dir4 = direction(l2.first, l2.second, l1.second);

	// When intersecting
	if (dir1 != dir2 && dir3 != dir4)
		return true;

	// When p2 of line2 are on the line1
	if (dir1 == 0 && onLine(l1, l2.first))
		return true;

	// When p1 of line2 are on the line1
	if (dir2 == 0 && onLine(l1, l2.second))
		return true;

	// When p2 of line1 are on the line2
	if (dir3 == 0 && onLine(l2, l1.first))
		return true;

	// When p1 of line1 are on the line2
	if (dir4 == 0 && onLine(l2, l1.second))
		return true;

	return false;
}

bool checkInside(VertexArray poly, int n, Vector2 p)
{

	// When polygon has less than 3 edge, it is not polygon
	if (n < 3)
		return false;

	// Create a point at infinity, y is same as point p
	Line exline = { p, { 9999, p.y } };
	int count = 0;
	int i = 0;
	do {

		// Forming a line from two consecutive points of
		// poly
		Line side = { poly[i], poly[(i + 1) % n] };
		if (isIntersect(side, exline)) {

			// If side is intersects exline
			if (direction(side.first, p, side.second) == 0)
				return onLine(side, p);
			count++;
		}
		i = (i + 1) % n;
	} while (i != 0);

	// When count is odd
	return count & 1;
}

void Board::Update(VertexArray vertexArray, std::vector<Line> indices)
{
	// set points
	for (int i = 0; i < m_Board[0].size(); i++)
	{

		for (int j = 0; j < m_Board.size(); j++)
		{

			std::string result;
			Vector2 c = { (float)i, (float)j };

			// set lines distance(A, C) + distance(B, C) == distance(A, B) 
			for (int k = 0; k < indices.size(); k++)
			{
				Vector2 a = indices[k].second;
				Vector2 b = indices[k].first;
				//LOG("a " << a.x << " " << a.y << std::endl);
				//LOG("b " << b.x << " " << b.y << std::endl);
				// c is the point we are checking
				// a and b are the indices that draw the line
				float dAC = DistanceBetweenTwoVector2(a, c);
				float dBC = DistanceBetweenTwoVector2(b, c);
				float dAB = DistanceBetweenTwoVector2(a, b);
				// LOG(dAC << " + " << dBC << " = " << dAC + dBC << " => " << dAB);
				if (dAC + dBC == dAB) {
					result = "@";
					m_Board[i][j] = result;
				}
			}

			// Function call
			//if (checkInside(vertexArray, vertexArray.size(), c))
			//{
			//	result = "&";
			//	m_Board[i][j] = result;
			//}
		}
	}

}

Shape::Shape(VertexArray* shape, std::vector<Line>* indices)
{
	m_Shape = *shape;
	m_Indices = *indices;
 }

Shape::~Shape(){}

VertexArray Shape::getShape()
{
	return m_Shape;
}

void Shape::setShape(VertexArray shape)
{
	m_Shape = shape;
}

std::vector<Line> Shape::getIndices()
{
	return m_Indices;
}

void Shape::setIndices(std::vector<Line> indices)
{
	m_Indices = indices;
}