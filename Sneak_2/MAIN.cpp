#pragma once
#include "common.h"
#include "Sneak.h"
#include "MyMap.h"

int width = 30, height = 15;

void setObject(const HANDLE& h, const COORD& coord, const char& simbol, const int& color = 10)
{
	SetConsoleCursorPosition(h, coord);
	SetConsoleTextAttribute(h, color); 
	putchar(simbol);
}

int randomNumber(int first, int last)
{
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<> d(first, last);
	return d(gen);
}

int main()
{
	system("cls");
	srand(time(0)); // запуск генератора случайных чисел
	system("mode con cols=200 lines=120"); // установка размеров окна консоли
	MoveWindow(GetConsoleWindow(), 100, 100, 500, 500, true); // установка стартовой позиции окна консоли
	CONSOLE_CURSOR_INFO cci = { sizeof(cci), false }; // создание параметров на отображение курсора
	SetConsoleCursorInfo(h, &cci); //связывание параметров и хендла

	cout << endl << "   $neak!" << endl << endl << "input 'A' if you want to run the snake in automatic mode " << endl
												<< "input 'M' if you want to run the snake in manually mode ";
	char chooseMode;
	while (!(_kbhit())) {
		char k = _getch();
		if (k == 'm' || k == 'M' || k == 'a' || k == 'A' ) {
			chooseMode = k;
			break;
		}
	}
	system("cls");
	coordin c(10, 5);
	MyMap map(15, 30, 7, c);
	Sneak sneak1(map);
	map.pushSneak(sneak1);

	
	do {
		//Sleep(100);
		//if (_kbhit() && chooseMode == 'm')
		//{
		//	int k = _getch();
		//	if (k == 0 || k == 224)
		//		k = _getch();
		//	sneak1.usersDecide(k);
		//}
		//else if (chooseMode == 'a')
		//{
		//	sneak1.decide();
		//}
		sneak1.drawSneak();
		if (chooseMode == 'm') {
			Sleep(100);
		}
		else if (chooseMode == 'a') {
			Sleep(10);			
		}
		if (_kbhit() && chooseMode == 'm') {
			int k = _getch();
			if (k == 0 || k == 224)
				k = _getch();
			sneak1.usersDecide(k);
		}
		else if (chooseMode == 'a') {
			Sleep(10);
			sneak1.decide();
		}


		coordin nextStep = sneak1.getHead() ;
		nextStep.x += sneak1.getDX();
		nextStep.y += sneak1.getDY();

		if (nextStep.x > map.getLeftUpCorrner().x + map.getWidth() - 1 || nextStep.x < map.getLeftUpCorrner().x + 1 ||
			nextStep.y > map.getLeftUpCorrner().y + map.getHeight() - 1|| nextStep.y < map.getLeftUpCorrner().y + 1) {
			map.gameContinue = 0;
		}

		if (nextStep == map.apple->getCoord()) {
			sneak1.moveSneak(true);
			map.putApple();
		}
		else if (map.thisPlaceFree(nextStep)) {
			sneak1.moveSneak(false);
		}
		else {
			map.gameContinue = 0;
		}
	} while (map.gameContinue);

	coordin ccc = map.getLeftUpCorrner();
	ccc.x += (map.getWidth() / 2);
	ccc.y += (map.getHeight() + 3 );

	SetConsoleCursorPosition(h, ccc.coordinToCOORD());
	putchar(' ');
	//cout << "LastMove: " << sneak1.lastMoveText;

	coordin cc = map.getLeftUpCorrner();
	cc.x += (map.getWidth() / 2);
	cc.y -= 2;

	Sneak s(sneak1);
	s.tailMemory = sneak1.tailMemory;
	s.color = 4;
	s.drawSneak();

	SetConsoleTextAttribute(h, 4);
	while (true)
	{
		SetConsoleCursorPosition(h, cc.coordinToCOORD());
		putchar(' ');
		cout << "GAME OVER";
		Sleep(500);
		SetConsoleCursorPosition(h, cc.coordinToCOORD());
		putchar(' ');
		cout << "          ";
		Sleep(500);

	}
	

	_getch();
	return 0;
}


//0 char:
//1 char : ☺
//2 char : ☻
//3 char : ♥
//4 char : ♦
//5 char : ♣
//6 char : ♠
//7 char :
//	8 char :
//	9 char :
//	10 char :
//
//	11 char : ♂
//	12 char : ♀
//	13 char :
//	14 char : ♫
//	15 char : ☼
//	16 char : ►
//	17 char : ◄
//	18 char : ↕
//	19 char : ‼
//	20 char : ¶
//	21 char : §
//	22 char : ▬
//	23 char : ↨
//	24 char : ↑
//	25 char : ↓
//	26 char : →
//	27 char :
//	8 char : ∟
//	29 char : ↔
//	30 char : ▲
//	31 char : ▼
//	32 char :
//	33 char : !
//	34 char : "
//	35 char : #
//	36 char : $
//	37 char : %
//	38 char : &
//	39 char : '
//	40 char: (
//		41 char:)
//	42 char : *
//	43 char : +
//	44 char : ,
//	45 char : -
//	46 char : .
//	47 char : /
//	48 char : 0
//	49 char : 1
//	50 char : 2
//	51 char : 3
//	52 char : 4
//	53 char : 5
//	54 char : 6
//	55 char : 7
//	56 char : 8
//	57 char : 9
//	58 char : :
//	59 char : ;
//60 char: <
//	61 char : =
//	62 char : >
//	63 char : ?
//	64 char : @
//	65 char: A
//	66 char : B
//	67 char : C
//	68 char : D
//	69 char : E
//	70 char : F
//	71 char : G
//	72 char : H
//	73 char : I
//	74 char : J
//	75 char : K
//	76 char : L
//	77 char : M
//	78 char : N
//	79 char : O
//	80 char : P
//	81 char : Q
//	82 char : R
//	83 char : S
//	84 char : T
//	85 char : U
//	86 char : V
//	87 char : W
//	88 char : X
//	89 char : Y
//	90 char : Z
//	91 char : [
//		92 char:\
//		93 char:]
//	94 char : ^
//		95 char : _
//		96 char : `
//		97 char: a
//		98 char : b
//		99 char : c
//		100 char : d
//		101 char : e
//		102 char : f
//		103 char : g
//		104 char : h
//		105 char : i
//		106 char : j
//		107 char : k
//		108 char : l
//		109 char : m
//		110 char : n
//		111 char : o
//		112 char : p
//			113 char : q
//			114 char : r
//			115 char : s
//			116 char : t
//			117 char : u
//			118 char : v
//			119 char : w
//			120 char : x
//			121 char : y
//			122 char : z
//			123 char : {
//			124 char: |
//			125 char : }
//			126 char : ~
//			127 char : ⌂
//			128 char : А
//			129 char : Б
//			130 char : В
//			131 char : Г
//			132 char : Д
//			133 char : Е
//			134 char : Ж
//			135 char : З
//			136 char : И
//			137 char : Й
//			138 char : К
//			139 char : Л
//			140 char : М
//			141 char : Н
//			142 char : О
//			143 char : П
//			144 char : Р
//			145 char : С
//			146 char : Т
//			147 char : У
//			148 char : Ф
//			149 char : Х
//			150 char : Ц
//			151 char : Ч
//			152 char : Ш
//			153 char : Щ
//			154 char : Ъ
//			155 char : Ы
//			156 char : Ь
//			157 char : Э
//			158 char : Ю
//			159 char : Я
//			160 char : а
//			161 char : б
//			162 char : в
//			163 char : г
//			164 char : д
//			165 char : е
//			166 char : ж
//			167 char : з
//			168 char : и
//			169 char : й
//			170 char : к
//			171 char : л
//			172 char : м
//			173 char : н
//			174 char : о
//			175 char : п
//			176 char : ░
//			177 char : ▒
//			178 char : ▓
//			179 char : │
//			180 char : ┤
//			181 char : ╡
//			182 char : ╢
//			183 char : ╖
//			184 char : ╕
//			185 char : ╣
//			186 char : ║
//			187 char : ╗
//			188 char : ╝
//			189 char : ╜
//			190 char : ╛
//			191 char : ┐
//			192 char : └
//			193 char : ┴
//			194 char : ┬
//			195 char : ├
//			196 char : ─
//			197 char : ┼
//			198 char : ╞
//			199 char : ╟
//			200 char : ╚
//			201 char : ╔
//			202 char : ╩
//			203 char : ╦
//			204 char : ╠
//			205 char : ═
//			206 char : ╬
//			207 char : ╧
//			208 char : ╨
//			209 char : ╤
//			210 char : ╥
//			211 char : ╙
//			212 char : ╘
//			213 char : ╒
//			214 char : ╓
//			215 char : ╫
//			216 char : ╪
//			217 char : ┘
//			218 char : ┌
//			219 char : █
//			220 char : ▄
//			221 char : ▌
//			222 char : ▐
//			223 char : ▀
//			224 char : р
//			225 char : с
//			226 char : т
//			227 char : у
//			228 char : ф
//			229 char : х
//			230 char : ц
//			231 char : ч
//			232 char : ш
//			233 char : щ
//			234 char : ъ
//			235 char : ы
//			236 char : ь
//			237 char : э
//			238 char : ю
//			239 char : я
//			240 char : Ё
//			241 char : ё
//			242 char : Є
//			243 char : є
//			244 char : Ї
//			245 char : ї
//			246 char : Ў
//			247 char : ў
//			248 char : °
//			249 char : ∙
//			250 char : ·
//			251 char : √
//			252 char : №
//			253 char : ¤
//			254 char :

