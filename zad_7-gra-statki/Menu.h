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
            cout << "Na pocz¹tku gry zawodnicy zaznaczaj¹, gdzie na ich planszy znajdowaæ siê bêd¹ okrêty, które przeciwnik musi trafiæ.\n";
            cout << "Po trafieniu w statek drugiego gracza, dowiadujemy siê jakiej jest on wielkoœci(od 1 do 4 pól d³ugoœci),\na tak¿e czy zosta³ ca³kowicie zatopiony(po trafieniu we wszystkie jego pola).\n";
            cout << "Gdy gracz trafi w statek, przys³uguje mu kolejny ruch w ramach tej samej kolejki.\n";
            cout << "Ka¿dy gracz umieszcza na swoim polu gry : jeden statek czteromasztowy, dwa trójmasztowe,\ntrzy dwumasztowe oraz cztery jednostki jednomasztowe.\n";
            cout << "Iloœæ masztów okreœla ile pól zajmuje dany okrêt.\n";
            cout << "______________________________________________________________________________\n";
        }
        else g = 0;
    } while (g);
};