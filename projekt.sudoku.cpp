#include <iostream>
using namespace std;

int sudoku[9][9]=
{//pierwsza czesc stworzenie planszy sudoku zakonczone
        {0, 8, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 3, 6, 0, 0, 0, 0, 0},
        {0, 7, 0, 0, 9, 0, 2, 0, 0},
        {0, 5, 0, 0, 0, 7, 0, 0, 0},
        {0, 0, 0, 0, 4, 5, 7, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 3, 0},
        {0, 0, 1, 0, 0, 0, 0, 6, 8},
        {0, 0, 8, 5, 0, 0, 0, 1, 0},
        {0, 9, 0, 0, 0, 0, 4, 0, 0}
    };
int main()//druga czesc wyswietlenie tej planszy
{
        for(int i=0 ; i<9 ; i++)
            {
            for(int j=0 ; j<9 ; j++)
            {
            cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }

        int wiersz;
        int kolumna;
        int liczba;

        cout << "Podaj wiersz: ";
        cin >> wiersz;

        cout << "Podaj kolumne: ";
        cin >> kolumna;

        cout << "Podaj liczbe: ";
        cin >> liczba;

        if(wiersz < 0 || wiersz > 8 || kolumna <0 || kolumna > 8 || liczba < 1 || liczba > 9)
        {
            cout << "Nieprawidłowa liczba!" << endl;
        }
        return 0;
}
