#include <iostream>
#include <conio.h>
#include <stdlib.h>     
#include <time.h>       
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#pragma once
using namespace std;

void Menu_Start() {
	cout << "---------------------STATKI---------------------\n";
    int g = 1;
    do {
    cout << "1.Start gry\n";
    cout << "2.Zasady gry\n";
    int choice=0;
    int h = 1;
    
        do {
            cout << "Wybierz[1-2]\n";
            cin >> choice;
            if (choice == 1) h = 0;
            if (choice == 2) h = 0;
        } while (h);
    
        if (choice == 2) {
            cout << "______________________________________________________________________________\n";
            cout << "Na pocz�tku gry zawodnicy zaznaczaj�, gdzie na ich planszy znajdowa� si� b�d� okr�ty, kt�re przeciwnik musi trafi�.\n";
            cout << "Po trafieniu w statek drugiego gracza, dowiadujemy si� jakiej jest on wielko�ci(od 1 do 4 p�l d�ugo�ci),\na tak�e czy zosta� ca�kowicie zatopiony(po trafieniu we wszystkie jego pola).\n";
            cout << "Gdy gracz trafi w statek, przys�uguje mu kolejny ruch w ramach tej samej kolejki.\n";
            cout << "Ka�dy gracz umieszcza na swoim polu gry : jeden statek czteromasztowy, dwa tr�jmasztowe,\ntrzy dwumasztowe oraz cztery jednostki jednomasztowe.\n";
            cout << "Ilo�� maszt�w okre�la ile p�l zajmuje dany okr�t.\n";
            cout << "______________________________________________________________________________\n";
        }
        else g = 0;
    } while (g);
};