#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <ctime>

using namespace std;


class Oyuncu{
	public:
		string isim;
		int level;
		Oyuncu(string isim) : isim(isim), level(1) {}
		virtual void sutCek() {
			cout<<isim<<" oyuncusu " << level*10<< " hýzýnda bir þut çekiyor"<<endl;
		}
		void anteremanYap() {
			cout << isim << " antereman yapýyor..."<<endl;
			level++;
		}
};

class Tsubasa:public Oyuncu{
	private:
		void kartalSutuCek() {
			cout << isim << " oyuncusu " << level*20 << " hýzýnda bir kartal þutu çekiyor."<< endl;
		}
	public:
		Tsubasa() : Oyuncu("Tsubasa") {}
		void sutCek() {
			if(rand() % 2)
				kartalSutuCek();
			else
				Oyuncu::sutCek();		
		}
		
};

int main() {
	setlocale(LC_ALL,"Turkish");
	srand(time(0));
	Oyuncu* dizi[11];
	dizi[0] = new Oyuncu("Genzo Wakabayashi");
	dizi[1] = new Oyuncu("Takeshi Kishida");
	dizi[2] = new Oyuncu("Koji Nishio");
	dizi[3] = new Oyuncu("Masao Nakayama");
	dizi[4] = new Oyuncu("Hanji Urabe");
	dizi[5] = new Oyuncu("Shingo Takasugi");
	dizi[6] = new Oyuncu("Hajime Taki");
	dizi[7] = new Oyuncu("Mamoru Izawa");
	dizi[8] = new Oyuncu("Teppei Kisugi");
	dizi[9] = new Tsubasa();
	dizi[10] = new Oyuncu("Taro Misaki");
	
	for(int i=0; i<10; i++) {
		int x = rand() % 11;
		dizi[x]->sutCek();
	}	
	
	return 0;
}
