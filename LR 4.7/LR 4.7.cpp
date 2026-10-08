// Lab_04_7.cpp
// Кіц Роман Романович
// Лабораторна робота № 4.7
// Обчислення суми ряду Тейлора за допомогою ітераційних циклів та рекурентних співвідношень.
// Варіант 12

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const double PI = atan(1.0) * 4;
    double xp, xk, x, dx, eps, a, R, S;
    int n;

    cout << "xp = ";  cin >> xp;
    cout << "xk = ";  cin >> xk;
    cout << "dx = ";  cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "----------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << "      |"
        << setw(10) << "arctg(x)" << "   |"
        << setw(7) << "S" << "        |"
        << setw(5) << "n" << "   |"
        << endl;
    cout << "----------------------------------------------------" << endl;

    x = xp;
    while (x <= xk)
    {
        n = 0;
        a = -1 / x;            // перший доданок
        S = -PI / 2 + a;         // сума: константа -pi/2 + перший доданок

        do {
            n++;
            R = -(2. * n - 1) / ((2. * n + 1) * x * x);   // коефіцієнт рекурентності
            a *= R;
            S += a;
        } while (fabs(a) >= eps);

        cout << "|" << setw(7) << setprecision(2) << x << "    |"
            << setw(10) << setprecision(6) << atan(x) << "    |"
            << setw(10) << setprecision(6) << S << "    |"
            << setw(4) << n + 1 << "    |"
            << endl;
        x += dx;
    }
    cout << "----------------------------------------------------" << endl;

    return 0;
}

