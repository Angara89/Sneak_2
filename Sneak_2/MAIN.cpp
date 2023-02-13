#pragma once
#include "common.h"
#include "Sneak.h"


int width = 30, height = 15;

void setObject(const HANDLE& h, const COORD& coord, const char& simbol, const int& color = 10)
{
	SetConsoleCursorPosition(h, coord); // отправляем курсор на позицию 
	SetConsoleTextAttribute(h, color); // устанавливаем красный цвет для отрисовки
	putchar(simbol);// печатаем символ
}



int main()
{

	system("cls");
	srand(time(0)); // запуск генератора случайных чисел
	system("mode con cols=100 lines=60"); // установка размеров окна консоли
	MoveWindow(GetConsoleWindow(), -1000, 50, 1000, 600, true); // установка стартовой позиции окна консоли
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // создание параметров на отображение курсора
	SetConsoleCursorInfo(h, &cci); //связывание параметров и хендла

	




	_getch();
	return 0;
}