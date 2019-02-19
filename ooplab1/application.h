#pragma once
#include <iostream>
#include "polinom.h"
#include "number.h"
#include <math.h>
#include <conio.h>

using namespace std;

class TApplication{
	//argc argv с main
	int Targc;
	char** Targv;
	TPolynom polynom;
	//введенное значение х
	number xValue;
	//поля отвечающие за инициализированность переменных
	bool polyInited;
	bool xValueInited;
public:
	TApplication(int argc, char *argv[]) {
		Targc = argc;
		Targv = argv;
		polyInited = false;
		xValueInited = false;
	}
	int menu();
	int run();
	//Ввод\изменение значения Х
	void initXValue();
	//Ввод\изменение коэффициентов полинома
	void initOrRedactCoefs();
	//Вывод корней многочлена
	void initShowRoots();
	//Вывод решения при текущем X
	void initSolution();
	//Вычисление корней полинома
	void initRoots();
	
};

void TApplication::initXValue() {
	cout << "Введите значение х: ";
	cin >> xValue;
	xValueInited = true;
}

void TApplication::initSolution() {
	polynom.findSolution(xValue);
}

void TApplication::initRoots() {
	polynom.findRoots();
}


void TApplication::initOrRedactCoefs() {
	int val;
	cout << "Ввод значений коэффициентов многочленов:" << endl;
	cout << "Введите значение коэффициента 2 порядка: ";
	cin >> val;
	while (val == 0) 
	{
		cout << "Коэффициент должен быть ненулевым. Введите значение коэффициента 2 порядка: ";
		cin >> val;
	}
	polynom.set_polyn_coef_2(val);
	cout << "Введите значение коэффициента 1 порядка: ";
	cin >> val;
	polynom.set_polyn_coef_1(val);
	cout << "Введите значение коэффициента 0 порядка: ";
	cin >> val;
	polynom.set_polyn_coef_0(val);
	//полином инициализирован
	polyInited = true;
}

void TApplication::initShowRoots() {
	cout << "Корни многочлена: ";
	polynom.showRoots();
}

int TApplication::menu() {
	system("cls");
	cout << "Меню:" << endl;
	cout << "1. Ввод значений коэффициентов многочлена" << endl;
	cout << "2. Ввод значения X" << endl;
	cout << "3. Вывод корней многочлена" << endl;
	cout << "4. Вывод значения многочлена для указанного X" << endl;
	cout << "5. Вывод многочлена и введенного значения X" << endl;
	cout << "0. Выход" << endl;
	int choiсe;
	cout<< endl << "Выберите действие: ";
	cin >> choiсe;
	return 	choiсe;
}

int TApplication::run()
{
	int ch;
	while (true)
	{
		ch = menu();
		if (ch == 0) break;
		char pause;
		switch (ch) {
		case 1:
			initOrRedactCoefs();
			break;
		case 2:
			initXValue();
			break;
		case 3:
			//проверка многочлена на инициализированность перед поиском его корней
			if (!polyInited) initOrRedactCoefs();
			initRoots();
			initShowRoots();
			//пауза до нажатия клавиши
			_getch();
			break;
		case 4:
			//проверка многочлена и значения Х на инициализированность перед вычислением его значения
			if (!polyInited) initOrRedactCoefs();
			if (!xValueInited) initXValue();
			initSolution();
			cout << "Решение при x=" << xValue << ": " << polynom.get_solution();
			_getch();
			break;
		case 5:
			if (polyInited) {
				polynom.showPolynom();
			}else cout << "Многочлен не инициализирован"<<endl;
			if (xValueInited) {
				cout << "x=" << xValue;
			}else cout << "Значение Х не инициализировано";
			_getch();
			break;
		default:
			break;
		}
	}
	return 0;
}
