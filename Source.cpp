#include <iostream>
#include <time.h>
#include<thread>
#include "graphics.h"

int x1 = 450, x2 = 525, Y1 = 520, y2 = 550, puan = 100, zaman2,  z=60, i,rasgeleyumurta,sayac=0;
char puan1[100], zaman1[100];

void hareket();

void zaman() {
	for (z = 60; z >= 1; --z) {
		delay(1000);
		sprintf(zaman1, "zaman:%d", z);
		outtextxy(800, 300, zaman1);
		if (z == 1) {
			while (true)
			{
				outtextxy(450, 300, "Zaman Bitti.!");
				cleardevice();
			}
			while (1) {
			//outtextxy(450, 300, puan1);
			}
		}
	}
}

void yakalama(int x1, int x2, int Y1, int y2, int i, int rasgeleyumurta) {

	
	if (Y1-50 <= 100 + i && y2 >= 130 + i) {

		if (x1-50 <= 90 + rasgeleyumurta && x2 >= 120 + rasgeleyumurta) {
			puan += 10;

			setcolor(WHITE);
			
			sprintf(puan1, "Puaniniz:%d", puan);
			outtextxy(800, 200, puan1);
			
			if (puan == 250) {
				cleardevice();
				while (true)
				{
					outtextxy(450, 300, "250 Puan Kazandiniz.Tebrikler.Oyun Bitti.!");
					delay(600);
				}
			}

		}

		else {
			puan -= 10;

			setcolor(WHITE);
			sprintf(puan1, "Puaniniz:%d", puan);
				cleardevice();
				setcolor(WHITE);
				sprintf(puan1, "Puaniniz:%d", puan);
				
				outtextxy(800, 200, puan1);
				if (puan == 0) {
					cleardevice();
					while (true)
					{
						outtextxy(400, 300, "0 Puan Kaybettiniz!.Oyun Bitti.!");
						delay(1);
					}
				}
		}
	}
}


void mousekontrol()
{
	while (1)
	{
		int x = mousex();
		int y = mousey();

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			if (x>330 && y>489 && x<578 && y<569)
			{
				cleardevice();
				break;
			}
		}
		clearmouseclick(WM_LBUTTONDOWN);
	}
}

void baslangýc() {

	readimagefile("logo5.jpg", 0, 0, 900, 600);
	delay(1500);

	readimagefile("arka2.jpg", 0, 0, 900, 600);

	mousekontrol();
}

void cizimler() {
	while (true)
	{
		readimagefile("arkaplan.jpg", 0, 0, 900, 600);
		readimagefile("tavuklar.jpg", 0, 0, 900, 100);
		readimagefile("sepett.jpg", x1-50, Y1-50, x2, y2);

		readimagefile("yumurtaa.gif", 90 + rasgeleyumurta, 100 + i, 120 + rasgeleyumurta, 130 + i);
		
		sprintf(puan1, "Puaniniz:%d", puan);
		outtextxy(800, 200, puan1);
	//	delay(800);
	
		sprintf(zaman1, "zaman:%d", z);
		outtextxy(800, 300, zaman1);
		
		swapbuffers();
		cleardevice();

		

	}
}

void hareket() {

	int ek = 50;
	char tus;

	setcolor(WHITE);
	readimagefile("sepetek.gif",x1-50, Y1-50, x2, y2);
	while (1)
	{
		tus = getch();
		if (tus == 27) exit(0);
		else
		{
			//setcolor(BLACK);
			//readimagefile("sepetek.gif", x1-50, Y1-50, x2, y2);
			
			if (tus == 77)
			{
				x1 += ek;
				x2 += ek;
			}
			else if (tus == 75)
			{
				x1 -= ek;
				x2 -= ek;
			}
			sayac++;
			//cleardevice();
			setcolor(WHITE);
			
			readimagefile("sepett.jpg", x1-50, Y1-50, x2, y2);

			
		}
	}
}
void yumurtaHareketleri(){

	//int rasgeleyumurta;

	while (true)
	{	
		//readimagefile("tavuklar.jpg", 0, 0, 900, 100);
		//readimagefile("sepet.bmp", x1 - 50, Y1 - 50, x2, y2);
		rasgeleyumurta = rand() % 10;
		
		rasgeleyumurta *= 50;
		for (i = 0; i <= 400; i += 50)
		{

			setcolor(WHITE);
			readimagefile("yumurtaa.jpg",90+rasgeleyumurta, 100 + i, 120+rasgeleyumurta, 130 + i);
						
			delay(550);
			setcolor(BLACK);
			readimagefile("ekrannn.gif",90 + rasgeleyumurta, 100 + i, 120 + rasgeleyumurta, 130 + i);
		//	cleardevice();
			//if (zaman(z)==1)break;
			yakalama(x1, x2, Y1, y2, i, rasgeleyumurta);
			

		}
		
		
	}
}

int main() {
	initwindow(900, 600);
	FreeConsole();
	
	baslangýc();
	
	std::thread t1(cizimler);
	std::thread t2(yumurtaHareketleri);
	std::thread t3(hareket);
	std::thread t4(mousekontrol);
	std::thread t5(zaman);
	
	//cizimler();
	t5.join(); t1.join();
	t2.join(); t3.join(); t4.join(); 



	getch();
}