#pragma once
#include "application.h"
#include <iostream>
#include "number.h"
#include <math.h>

using namespace std;

class TPolynom {
	number polyn_coef_2;
	number polyn_coef_1;
	number polyn_coef_0;
	short num_of_roots;
	number roots[2];
	number solution;
public:
	void set_polyn_coef_2(number val)
	{
		polyn_coef_2 = val;
	}
	void set_polyn_coef_1(number val)
	{
		polyn_coef_1 = val;
	}
	void set_polyn_coef_0(number val)
	{
		polyn_coef_0 = val;
	}
	short get_num_of_roots()
	{
		return num_of_roots;
	}
	number get_solution()
	{
		return solution;
	}

	number findSolution(number);
	//вычисление корней
	void findRoots();
	//вывод корней
	void showRoots();
	//вывод полинома
	void showPolynom();
};

number TPolynom::findSolution(number xValue) {
	solution = polyn_coef_2*pow(xValue, 2) + polyn_coef_1*xValue + polyn_coef_0;
	return solution;
}

void TPolynom::findRoots() {
	number discr = pow(polyn_coef_1, 2) - 4 * polyn_coef_2*polyn_coef_0;
	if (discr < 0)
	{
		num_of_roots = 0;
		return;
	}
	if (discr == 0)
	{
		num_of_roots = 1;
		roots[0] = (-polyn_coef_1) / (2 *polyn_coef_2);
	}
	else
	{
		num_of_roots = 2;
		roots[0] = (-polyn_coef_1 + sqrt(discr)) / (2 * polyn_coef_2);
		roots[1] = (-polyn_coef_1 - sqrt(discr)) / (2 * polyn_coef_2);
	}
}

void TPolynom::showRoots() {
	if (num_of_roots == 0) 
	{
		cout << "отсутствуют";
		return;
	}
	for (int i = 0; i < num_of_roots; i++) cout << roots[i] << " ";
}

void TPolynom::showPolynom() {
	if (polyn_coef_2 != 0) 
	{
		if (polyn_coef_2 != 1) cout << polyn_coef_2;
		cout << "x^2";
	}
	
	if (polyn_coef_1 != 0) 
	{
		if (polyn_coef_1 > 0 && polyn_coef_2!=0) cout << "+";
		if (polyn_coef_1 != 1) cout << polyn_coef_1;
		cout << "x";
	}
	
	if (polyn_coef_0 != 0) 
	{
		if (polyn_coef_0 > 0 && (polyn_coef_1 != 0 || polyn_coef_2 != 0)) cout << "+";
		cout << polyn_coef_0;
	}
	cout << endl;
}