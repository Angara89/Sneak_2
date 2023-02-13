#pragma once
#include "common.h"
#include "Sneak.h"


int width = 30, height = 15;

void setObject(const HANDLE& h, const COORD& coord, const char& simbol, const int& color = 10)
{
	SetConsoleCursorPosition(h, coord); // ���������� ������ �� ������� 
	SetConsoleTextAttribute(h, color); // ������������� ������� ���� ��� ���������
	putchar(simbol);// �������� ������
}



int main()
{

	system("cls");
	srand(time(0)); // ������ ���������� ��������� �����
	system("mode con cols=100 lines=60"); // ��������� �������� ���� �������
	MoveWindow(GetConsoleWindow(), -1000, 50, 1000, 600, true); // ��������� ��������� ������� ���� �������
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // �������� ���������� �� ����������� �������
	SetConsoleCursorInfo(h, &cci); //���������� ���������� � ������

	




	_getch();
	return 0;
}