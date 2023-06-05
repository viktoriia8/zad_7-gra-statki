#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>     
#include <time.h>       
#include <string>  
#include <fstream>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
#include"Menu.h"
#include "Board.h"
//#include "Ship.h"


using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Polish");
    Menu_Start();
    Board b;
    b.showmyboard();
    Ship k;
    if (k.ifok(&b, k)) { 
        cout << "OK"; 
        b.addShip(k);
    }
    else cout << "NO";
    
    b.showmyboard();


    cout << "Hello World!\n";
}
