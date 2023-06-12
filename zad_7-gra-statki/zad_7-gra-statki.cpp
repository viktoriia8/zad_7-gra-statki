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
        while(true){
        Ship k;
        if (b.ifok(k)) {
            cout << "OK\n";
            b.addShip(k);
        }
        else cout << "No\n";
        b.showmyboard();
    } 
}
