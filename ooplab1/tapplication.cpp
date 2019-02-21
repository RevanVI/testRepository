#include "tapplication.h"

TApplication::TApplication(int argc, char *argv[]): QCoreApplication (argc, argv)
{
    polyInited = false;
    xValueInited = false;
}

TApplication::~TApplication()
{

}

void TApplication::initXValue() {
    cout << "Enter x:";
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
    cout << "Enter коэффициентов полинома." << endl;
    cout << "Коэффициент при 2й степени (не равен 0): ";
    cin >> val;
    while (val == 0)
    {
        cout << "Ошибка! Введен 0. Повторите ввод: ";
        cin >> val;
    }
    polynom.setCoefA(val);
    cout << "Коэффициент при 1й степени: ";
    cin >> val;
    polynom.setCoefB(val);
    cout << "Коэффициент при 0й степени: ";
    cin >> val;
    polynom.setCoefC(val);
    polyInited = true;
}

void TApplication::initShowRoots() {
    cout << "Корень(-ни): ";
    polynom.showRoots();
}

int TApplication::menu() {
    system("cls");
    cout << "Menu:" << endl;
    cout << "1. Ввод/изменение коэффициентов полинома" << endl;
    cout << "2. Ввод значения Х" << endl;
    cout << "3. Поиск корней полинома" << endl;
    cout << "4. Вычисление значение полинома при заданном х" << endl;
    cout << "5. бШБНД ЛМНЦНВКЕМЮ Х ББЕДЕММНЦН ГМЮВЕМХЪ X" << endl;
    cout << "0. Выход" << endl;
    int choice;
    cout<< endl << "Поле ввода: ";
    cin >> choice;
    return 	choice;
}

int TApplication::run()
{
    int ch;
    while (true)
    {
        ch = menu();
        if (ch == 0) break;
        switch (ch) {
        case 1:
            initOrRedactCoefs();
            break;
        case 2:
            initXValue();
            break;
        case 3:
            if (!polyInited) initOrRedactCoefs();
            initRoots();
            initShowRoots();
            _getch();
            break;
        case 4:
            if (!polyInited) initOrRedactCoefs();
            if (!xValueInited) initXValue();
            initSolution();
            cout << "Значение при x=" << xValue << ": " << polynom.get_solution();
            _getch();
            break;
        case 5:
            if (polyInited) {
                cout << polynom;
            }else cout << "Полином не задан" << endl;
            if (xValueInited) {
                cout << "x=" << xValue;
            }else cout << "гМЮВЕМХЕ у МЕ ХМХЖХЮКХГХПНБЮМН";
            _getch();
            break;
        default:
            break;
        }
    }
    return 0;
}
