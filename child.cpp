#include <iostream>
#include <cstdlib> //для rand srand
#include <random> //для random_device, mt19937, mersenne

using namespace std;

int main(int argc, char *argv[]) {

	cout << "Номер шара:\t" << argv[1] << endl;

	random_device rd;
	mt19937 mersenne(rd());

	srand(mersenne()); //иницирование рандома по времени
	int x = -50 + rand() % 100;
	int y = -50 + rand() % 100;

	cout << "\nНачальная координата:\tx = "<< x << "\ty = " << y << endl;

	while(x > -100 && x < 100 && y >-100 && y < 100){
		x += - 50 + rand() % 100;
		y += - 50 + rand() % 100;
		cout << "\nСледующий шаг: x = " << x << "\ty = " << y;
	}
	cout << "\nНомер шара [" << argv[1] << "] Убит\n";

	return 0;
}
