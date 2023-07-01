
// Exercise 1 (X)
	// “Create a Budget class that can instantiate objects based on different budget categories like food, 
	// clothing, and entertainment.These objects should allow for depositingand withdrawing funds from each 
	// category, as well computing category balancesand transferring balance amounts between categories”
// Exercise 2 (X)
	// “Create class and sub - class objects which represent different geometrical shapes, 
	// such as Rectangle sand Squares”
// Exercise 3
	// “Create a lottery ball, or Hat, that takes a variable number of arguments that specify the number of 
	// balls of each color that are in the hat.Give the object the ability to pick a random number of balls 
	// from the hat, which will then be used to compute the probability of picking a certain distribution of 
	// balls over a large number of experiments”

#include <iostream>
#include <conio.h>
//#include "Budget.h"
#include "GeometricalShape.h"
#include <windows.h>

#define LOG(x) (std::cout << x << "\n")

void updatePoint(Vector2* p)
{
	//  0 x 24 & 0 y 24
	// 26 x 49 & 0 y 24
	//  0 x 24 & 26 y 49
	// 26 x 49 & 26 y 49
	if ((p->x >= 0.0 && p->x <= 25.0) && (p->y >= 0.0 && p->y <= 25.0))
	{
		//quadrant 1
		p->y += 1.0;
	}
	if ((p->x >= 26.0 && p->x <= 49.0) && (p->y >= 0.0 && p->y <= 25.0))
	{
		//quadrant 2

		p->x -= 1.0;
	}
	if ((p->x >= 0.0 && p->x <= 25.0) && (p->y >= 26.0 && p->y <= 49.0))
	{
		//quadrant 3
		p->x += 1.0;
	}
	if ((p->x >= 26.0 && p->x <= 49.0) && (p->y >= 26.0 && p->y <= 49.0))
	{
		//quadrant 4

		p->y -= 1.0;
	}
}
int main()
{
	//Budget groceryBudget(10000.00, "grocery");
	//LOG(groceryBudget.GetName());
	//groceryBudget.Deposit(5000);
	//groceryBudget.Withdraw(2500.40);
	//LOG(groceryBudget.Balance());

	//Budget clothingBudget(15000.50, "clothing");
	//LOG(clothingBudget.GetName());
	//clothingBudget.Withdraw(20000);
	//clothingBudget.Deposit(10000);
	//LOG(clothingBudget.Balance());

	Board board(49, 49);
	Vector2 a = { 5, 5};
	Vector2 b = { 44, 5 };
	Vector2 c = { 5, 44 };
	Vector2 d = { 44, 44 };
	VertexArray squareVertexArray;
	squareVertexArray.push_back(a);
	squareVertexArray.push_back(b);
	squareVertexArray.push_back(c);
	squareVertexArray.push_back(d);
	Line line1(a, b);
	Line line2(a, c);
	Line line3(c, d);
	Line line4(b, d);
	std::vector<Line> squareIndices;
	squareIndices.push_back(line1);
	squareIndices.push_back(line2);
	squareIndices.push_back(line3);
	squareIndices.push_back(line4);

	//for (int i = 0; i < indices.size(); i++)
	//{
		//LOG(indices[i][0].x << " " << indices[i][1].y);
	//}
	Shape square(&squareVertexArray, &squareIndices);

	board.Update(square.getShape(), square.getIndices());
	board.Draw();

	std::string changeDraw;
	std::cin >> changeDraw;

	system("cls");
	board.Clear();

	

	Vector2 a_1 = { 5, 5 };
	Vector2 b_1 = { 44, 5 };
	Vector2 c_1 = { 5, 44 };
	std::string exit;
	while (true) {
		VertexArray triangleVertexArray;
		triangleVertexArray.push_back(a_1);
		triangleVertexArray.push_back(b_1);
		triangleVertexArray.push_back(c_1);
		Line line_1(a_1, b_1);
		Line line_2(a_1, c_1);
		Line line_3(c_1, b_1);
		std::vector<Line> triangleIndices;
		triangleIndices.push_back(line_1);
		triangleIndices.push_back(line_2);
		triangleIndices.push_back(line_3);

		Shape triangle(&triangleVertexArray, &triangleIndices);

		board.Update(triangle.getShape(), triangle.getIndices());
		board.Draw();
		Sleep(100);
		system("cls");
		board.Clear();
		updatePoint(&c_1);
		updatePoint(&b_1);
		updatePoint(&a_1);
	}
	return 0;
}