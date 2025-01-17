﻿#include <iostream>
#include <cstdio>
#include <locale.h>
using namespace std;
class KrestikiNoliki
{
	char* field;
	int size;
public:
	KrestikiNoliki(int sies)
	{
		size = sies;
		field = new char[size * size];
	}
	~KrestikiNoliki()
	{
		delete[] field;
	}
	char* operator[](int row)
	{
		return field + row * size;
	}
	void print(KrestikiNoliki& field) {
		system("cls");
		for (int j = 0; j < size; j++) {
			cout << "--";
		}
		cout << "-\n";
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cout << "|" << field[i][j];
			}
			cout << "|\n";
			for (int j = 0; j < size; j++) {
				cout << "--";
			}
			cout << "-\n";
		}
	}
	int check(KrestikiNoliki& field) {
		int g, v;
		int d1, d2;
		for (int i = 0; i < size; i++) {
			g = field[i][0];
			for (int j = 0; j < size; j++) {
				if (field[i][j] != g || g == ' ') {
					g = ' ';
					break;
				}
			}
			if (g != ' ') {
				return g;
			}
			v = field[0][i];
			for (int j = 0; j < size; j++) {
				if (field[j][i] != v || v == ' ') {
					v = ' ';
					break;
				}
			}
			if (v != ' ') {
				return v;
			}
		}
		d1 = field[0][0];
		d2 = field[0][size - 1];
		for (int i = 0; i < size; i++) {
			if (field[i][i] != d1) {
				d1 = ' ';
				break;
			}
		}
		if (d1 != ' ') {
			return d1;
		}
		for (int i = 0; i < size; i++) {
			if (field[i][size - 1 - i] != d2) {
				d2 = ' ';
				break;
			}
		}
		//возвращаем знак
		if (d2 != ' ') {
			return d2;
		}
		return ' ';
	}
	void game(KrestikiNoliki& field)
	{
		int player = 'x';
		char result;
		int running = 1;
		int i = 0, j = 0;
		bool vvod = true;
		while (running) {
			do {
				if (vvod == false) {
					cout << "Повтрорите ввод\n";
				}
				field.print(field);
				if (player == 'x') {
					cout << "игрок X ходит\n";
				}
				else {
					cout << "игрок O ходит\n";
				}
				cout << "Введите координаты хода x y (через пробел): ";
				cin >> i >> j;
				vvod = false;
				// если неправильно
			} while (i > size || j > size || i < 0 || j < 0 || field[i - 1][j - 1] != ' ');
			vvod = true;
			field[i - 1][j - 1] = player;
			result = field.check(field);
			if (result != ' ') { // если result не пробел, значит выигрыш
				cout << result << " выиграл!";
				running = 0;
			}		
			if (player == 'x') { // Передача хода другому игроку
				player = 'o';
			}
			else {
				player = 'x';
			}
		}

	}
};
int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Нужно ввести размер поля: ";
	cin >> size;

	KrestikiNoliki field(size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			field[i][j] = ' ';
	}
	field.game(field);
	return 0;
}