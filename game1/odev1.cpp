#include <iostream>
#include <cstdlib>
#include <ctime>
#include <locale.h>

using namespace std;

class Oyuncu {
private:
    string isim;
    int darbe;
    int can;
    int enerji;

public:
    Oyuncu(string isim, int can = 5, int enerji = 100) {
        this->isim = isim;
        this->darbe = 0;
        this->can = can;
        this->enerji = enerji;
    }

    void mevcut_durumu_goruntule() {
        cout << "darbe: " << this->darbe << endl;
        cout << "can: " << this->can << endl;
        cout << "enerji: " << this->enerji << endl;
    }

    void saldir(Oyuncu& rakip) {
        cout << "Bir saldýrý gerçekleþtirdiniz." << endl;
        cout << "Saldýrý sürüyor. Bekleyiniz." << endl;

        for (int i = 0; i < 10; i++) {
            cout << ".";
            cout.flush();
            _sleep(300);
        }

        int sonuc = this->saldiri_sonucunu_hesapla();

        if (sonuc == 0) {
            cout << "\nSONUÇ: kazanan taraf yok" << endl;
        }

        if (sonuc == 1) {
            cout << "\nSONUÇ: rakibinizi darbelediniz" << endl;
            this->darbele(rakip);
        }

        if (sonuc == 2) {
            cout << "\nSONUÇ: rakibinizden darbe aldýnýz" << endl;
            rakip.darbele(*this);
        }
    }

    int saldiri_sonucunu_hesapla() {
        return rand() % 3;
    }

    void kac() {
        cout << "Kaçýlýyor..." << endl;
        for (int i = 0; i < 10; i++) {
            cout << "\n";
            cout.flush();
            _sleep(300); 
        }
        cout << "Rakibiniz sizi yakaladý" << endl;
    }

    void darbele(Oyuncu& darbelenen) {
        darbelenen.darbe += 1;
        darbelenen.enerji -= 1;
        if ((darbelenen.darbe % 5) == 0) {
            darbelenen.can -= 1;
        }
        if (darbelenen.can < 1) {
            darbelenen.enerji = 0;
            cout << "Oyunu " << this->isim << " kazandý!" << endl;
            this->oyundan_cik();
        }
    }

    void oyundan_cik() {
        cout << "Çýkýlýyor..." << endl;
        exit(0);
    }
};

int main() {
	setlocale(LC_ALL, "Turkish");
    srand(time(NULL));
    
	char hamle;

    
    Oyuncu siz("Ahmet");
    Oyuncu rakip("Mehmet");

    
    while (true) {
        cout << "Þu anda rakibinizle karþý karþýyasýnýz."<<endl;
        cout << "Yapmak istediðiniz hamle:" <<endl;
        cout << "Saldýr: s"<<endl;
        cout << "Kaç: k"<<endl;
        cout << "Çýk: q"<<endl;
        
        cin >> hamle;
        
        if(hamle == 's') {
        	siz.saldir(rakip);
        	
        	cout << "Rakibinizin durumu: ";
        	rakip.mevcut_durumu_goruntule();
        	cout << "Sizin durumunuz: ";
        	siz.mevcut_durumu_goruntule();
        	
		}
		
		else if(hamle == 'k')
			siz.kac();
		else if(hamle == 'q')
			siz.oyundan_cik();
		else
			cout << "Hatalý tuþladýnýz. Tekrar deneyin." << endl;	
		
} }
	
	


