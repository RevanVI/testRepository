#pragma once
#include <QCoreApplication>
#include <iostream>
#include <math.h>
#include <conio.h>
#include "polynom.h"
#include "number.h"

using namespace std;

class TApplication: public QCoreApplication
{
private:
	TPolynom polynom;
	number xValue;
	bool polyInited;
	bool xValueInited;
public:
    TApplication(int argc, char *argv[]);
    ~TApplication();
	int menu();
	int run();
	void initXValue();
	void initOrRedactCoefs();
	void initShowRoots();
	void initSolution();
	void initRoots();
};

