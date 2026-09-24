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
int rozwiazanie[9][9] =
{
    {2, 8, 4, 7, 5, 1, 6, 9, 3},
    {9, 1, 3, 6, 2, 4, 8, 5, 7},
    {6, 7, 5, 8, 9, 3, 2, 4, 1},
    {8, 5, 9, 3, 6, 7, 1, 2, 4},
    {1, 3, 2, 9, 4, 5, 7, 8, 6},
    {4, 6, 7, 1, 8, 2, 5, 3, 9},
    {5, 2, 1, 4, 7, 9, 3, 6, 8},
    {7, 4, 8, 5, 3, 6, 9, 1, 2},
    {3, 9, 6, 2, 1, 8, 4, 7, 5}
};

bool zablokowane[9][9] = {};

for (int i = 0; i < 9; i++)
{
    for(int j = 0; i < 9; j++)
    {
        if(sudoku[i][j]!=0)
        {
            zablokowane[i][j] = true;
        }
    }
}

bool nagroda_wiersz[9] = {};
bool nagroda_kolumna[9] = {};
bool nagroda_kwadrat[9] = {};

int punkty = 0;

int main()//druga czesc caly program,pobranie ruchu,system bledow
{
        int wiersz;
        int kolumna;
        int liczba;
        int bledy = 0;

        while(true)
        {
            // wyswietlenie tej planszy
            for(int i=0 ; i<9 ; i++)
            {
            for(int j=0 ; j<9 ; j++)
            {
            cout << sudoku[i][j] << " ";
            }
            cout << endl;
        }
            //pobranie ruchu gracza
            cout << "Podaj wiersz: ";
            cin >> wiersz;

            cout << "Podaj kolumne: ";
            cin >> kolumna;

            cout << "Podaj liczbe: ";
            cin >> liczba;

            if(wiersz < 0 || wiersz > 8 || kolumna <0 || kolumna > 8 || liczba < 1 || liczba > 9)
            {
                cout << "Nieprawidlowa liczba!" << endl;
                bledy++;
            }
            else if
            {
                if(zablokowane[wiersz][kolumna])
                {
                    cout << "Tego pola nie mozna zmienic!" <<endl;
                    bledy++;
                }
            }
            else
            {
                bool poprawne = true;

                //sprawdzanie wiersza
                for (int j = 0; j < 9 ; j++)
                {
                    if (sudoku[wiersz][j]==liczba)
                    {
                        cout << "Ta liczba jest juz w danym wierszu!" <<endl;
                        poprawne = false;
                    }
                }
                //sprawdzanie kolumny
                for (int i = 0; i < 9 ; i++)
                {
                    if (sudoku[i][kolumna]==liczba)
                    {
                        cout << "Ta liczba jest juz w danyej kolumnie!" <<endl;
                        poprawne = false;
                    }
                }

                //sprawdzanie kwadratu
                int poczatek_wiersza = wiersz - wiersz % 3;
                int poczatek_kolumny = kolumna - kolumna % 3;

                for(int i = 0; i < 3 ; i++)
                {
                    for(int j = 0; j < 3 ; j++)
                    {
                        if(sudoku[poczatek_wiersza + i][poczatek_kolumny + j]==liczba)
                        {
                            cout<<"Ta liczba jest juz w tym kwadracie!"<<endl;
                            poprawne = false;
                        }
                    }
                }

                if (poprawne)
                {
                    if(rozwiazanie[wiersz][kolumna] == liczba)
                    {
                        sudoku[wiersz][kolumna]=liczba;
                        cout << "Liczba zostala wpisana!" <<endl;

                        bool pelny_wiersz = true;

                        for(int j = 0;j<9;J++)
                        {
                            if(sudoku[wiersz][j]==0)
                            {
                                pelny_wiersz = false;
                            }
                        }\

                        if(pelny wiersz && !nagroda_wiersz[wiersz])
                        {
                            punkty += 100;
                            nagroda_wiersz[wiersz] = true;

                            cout << "Ukonczyles wiersz! +100 punktow" <<endl;
                        }

                        bool pelna_kolumna = true;

                        for(int i = 0; i < 9 ; i++)
                        {
                            if(sudoku[i][kolumna]==0)
                            {
                                pelna_kolumna = false;
                            }
                        }

                        if(pelna_kolumna && !nagroda_kolumna[kolumna])
                        {
                            punkty += 100;
                            nagroda_kolumna[kolumna] = true;

                            cout << "Ukonczyles kolumne! +100 punktow" <<endl;
                        }
                    }

                    else
                    {
                        cout <<"Zla liczba!" <<endl;
                        bledy++;
                    }
                }
                else
                {
                    bledy++;
                    cout << "Blad!" <<endl;
                }
            }
        }

        return 0;
}
