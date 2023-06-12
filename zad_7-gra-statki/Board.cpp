#include "Board.h"


using namespace std;

void Board::showmyboard() {
	int i, j;
	cout << "   a b c d e f g h i j \n";
	cout << "----------------------\n";
	for (i = 1; i < 11; i++) {
		if (i!=10)
		cout << i << "| ";
		else if(i==10)cout << "0" << "| ";
		for (j = 1; j < 11; j++) {
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
void Board::addShip(const Ship& s){
	string place = s.place;
	int num = atoi(&place[0]);
	if (num == 0)num = 10;
	int ch = int(place[1])-96;
	matrix[num][ch] = 1;

};

Board::Board(){
	for (int i = 0; i < 13; i++) {
		for (int j = 0; j < 13; j++) {
			matrix[i][j] = 0;
		}
	}
};

bool Board::ifok(const Ship& s) {
	string place_ = s.place;
	int row = atoi(&place_[0]);
	if (row == 0)row = 10;
	int column = int(place_[1]) - 96;     //97-106
	int correct = 0;
	for (int g = 1; g < 11; g++) {
		if (row == g) correct++;
		if (column == g)correct++;
	}
	if (correct != 2) {
		cout << "le wprowadzone wspó³rzêdne statka!\n";
		return 0;
	}
		//sprawdzenie czy mo¿na umieœciæ statek
	for (int y = row - 1; y <= row + 1; y++) {
		for (int x = column - 1; x <= column + 1; x++) {
			if (matrix[y][x] != 0) return 0;
		}
	}return 1;
}