#include<iostream>
#include<windows.h>
#include<conio.h>
#include<locale.h>
using namespace std;


class SnakeGame {
	bool gameOver;
	const int width = 20;
	const int height = 20;
	int x, y, fruitX, fruitY, score;
	enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
	int tailX[100], tailY[100];
	int nTail;
	eDirection dir;
	
	public:
		SnakeGame(bool gameOver = false, int score = 0, eDirection dir = STOP) {
			this->gameOver = gameOver;
			this->x = width/2;
			this->y = height/2;
			this->dir = dir;
			this->fruitX = rand() % width;
			this->fruitY = rand() % height;
			this->score = score;
			this->nTail = 1;
		}
		
		void draw() {
			system("CLS");
			for(int i = 0; i < this->width+2; i++) {
				cout << "#";
			}
			cout << endl;
			for(int i = 0; i < this->height; i++) {
				for(int j = 0; j < this->width; j++) {
					if(j==0)
						cout << "#";
					if(this->y==i && j==this->x)
						cout << "O";
					else if (i == this->fruitY && j == this->fruitX)
						cout << "*";
					else {
						bool print = false;
						for(int k = 0; k < this->nTail; k++) {
							if(this->tailX[k] == j && this->tailY[k] == i) {
								cout << "o";
								print = true;
							}
						}
						if(!print)
							cout << " ";
					}
					if(j == this->width-1)
						cout << "#";
				}
				cout<<endl;
			}
			for(int i = 0; i<this->width+2; i++) {
				cout << "#";
			}
			cout << endl << "Score: " << this->score << endl;
		}
		
		
		void input() {
			if(_kbhit()) {
				switch(getch()) {
					case 'a': 
						this->dir=LEFT;
						break;
					case 'd':
						this->dir=RIGHT;
						break;
					case 'w':
						this->dir=UP;
						break;
					case 's':
						this->dir=DOWN;
						break;
					case 'x':
						this->gameOver=true;
						break;
				}
			}
		}
		
		
		void logic() {
			int prevX = this->tailX[0];
			int prevY = this->tailY[0];
			int prev2X, prev2Y;
			this->tailX[0] = this->x;
			this->tailY[0] = this->y;
			
			for(int i = 0; i< this->nTail; i++) {
				prev2X = this->tailX[i];
				prev2Y = this->tailY[i];
				this->tailX[i] = prevX;
				this->tailY[i] = prevY;
				prevX = prev2X;
				prevY = prev2Y;
			}
			
			switch(dir) {
				case LEFT:
					x--;
					break;
				case RIGHT:
					x++;
					break;
				case UP:
					y--;
					break;
				case DOWN:
					y++;
					break;
			}
			
			if(this->x >= this->width)
				this->x = 0;
			else if (this->x < 0) 
				this->x = this->width-1;
			if(this->y >= this->height)
				this->y = 0;
			else if(this->y < 0) {
				this->y = this->height-1;
			}
			
			for(int i = 0; i<this->nTail; i++) {
				if(this->tailX[i] == this->x && this->tailY[i] == this->y)
					this->gameOver = true;
			}
			
			
			if(this->x == this->fruitX && this->y == this->fruitY) {
				this->score += 10;
				this->fruitX = rand() % this->width;
				this->fruitY = rand() % this->height;
				this->nTail++;
			}
		}
		
		
		void mainMenu() {
			int s;
			cout<<"Seviye seç 1-10: "<<endl<<"->";
			cin>>s;
			this->gameOver = false;
			this->score = 0;
			this->dir = STOP;
			while(!this->gameOver) {
				this->draw();
				this->input();
				this->logic();
				Sleep(100/s);
			}
			
			char ch;
			cout<<"Score: "<<this->score<<endl;
			cout<<"Devam etmek istiyor musun! (E/e)"<<endl<<"->";
			cin>>ch;
			if(ch == 'e' || ch == 'E') {
				system("CLS");
				this->nTail = 1;
				this->mainMenu();
			}
		}
			
};


int main() {
	setlocale(LC_ALL, "Turkish");
	SnakeGame().mainMenu();
	system("CLS");
	cout<<"Game Over!";
	Sleep(2000);
	return 0;
}
