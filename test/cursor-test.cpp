#include <iostream>
#include "displayManager.h"
using namespace std;
char print() {
    return 'o';
};
int main()
{
    int row, col;
    // while (1)
    // {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
                cout << j;
            cout << endl;
        }
        cout << "\n> ";
        cin >> row >> col;
        // absolute line
        // cout << "\033["<<row<<";"<<col<<"H" << print() << endl;
        cout << "\033["<<col<<"A" << print() << endl;
        cout << "\033[" << row << "C"<<  "\033["<<col<<"B" << endl;
        cout << "row: "<< row <<" col: "<< col <<endl;

        // system("pause");

    // }
    
}