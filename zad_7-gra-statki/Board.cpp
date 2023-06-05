#include "Board.h"


using namespace std;

void Board::showmyboard() {
	int i, j;
	cout << "   a b c d e f g h i j \n";
	cout << "----------------------\n";
	for (i = 0; i < 10; i++) {
		if (i!=9)
		cout << i+1 << "| ";
		else if(i==9)cout << "0" << "| ";
		for (j = 0; j < 10; j++) {
			if (matrix[i][j] == 0) cout << ".";             //puste miejsca na mapie
			else if (matrix[i][j] == 1) cout << "#";		//Statki
			else if (matrix[i][j] == 2)cout << "x";			//strzelone puste miejsca
			else if (matrix[i][j] == 3) cout << "\033[1;31m" << "#" << "\033[0m";   //strzelone statki(czerwone)
			cout << " ";
		};
		cout << "|\n";
	};
	cout << "       Moja mapka\n";
};
void Board::addShip(Ship s){
	string place = s.place;
	int num = place[0];
	int ch = place[1];
	matrix[num][(ch - 97)] = 1;

};

Board::Board(){
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			matrix[i][j] = 0;
		}
	}
};
