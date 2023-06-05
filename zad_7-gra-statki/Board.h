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
#include "Ship.h"


using namespace std;

class Board {
	public:
	int matrix[10][10];
	void showmyboard();
	void addShip(Ship s);
	Board();
	friend class Gamer;
	friend class Ship;
};