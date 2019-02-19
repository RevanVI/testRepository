#include "application.h"
#include <iostream>
#include "polinom.h"
#include "number.h"
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
	setlocale(LC_ALL, "Russian");
	TApplication a(argc, argv);
	return a.run();
}
