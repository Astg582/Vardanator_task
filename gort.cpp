#include <iostream>
#include <chrono>
#include <thread>

bool sun; 
int air = 30;
int gras = 10;
int wat = 50;

struct Grass {
	void to_grow(){
		if(sun){
			wat -= 2;
			gras += 7;
		}
	}
}grass;

struct Water {
	void rain(){
			if(!sun){
				wat += 23;
			}
			std::cout << "water " << wat << std::endl; 
	}
}water;


struct Gort{
	void bellow(){
		if(sun){
			air -= 5;
		}
	}
	void eat(){
		if(sun){
			gras -= 2; 
		}
	}
	void drink(){
		if(sun){
			wat -= 3;
		}
	}
};


struct Tree{
	void fotos(){
		if(sun){
			wat -= 3;
			air += 5;
		}
	}
};

void Day();

	struct Tree tree1;
    struct Tree tree2;
	struct Tree tree3;
	struct Gort gort;

int main(){
	Day();
}
void Day(){
	while (true){
		int i = 101;
		while(i & 1){
			std::this_thread::sleep_for(std::chrono::seconds(5));
			sun = !sun;
			std::cout << "SUN  " << sun << std::endl;
			
			grass.to_grow();
			tree1.fotos();
			gort.drink();
			gort.eat();
			tree2.fotos();
			gort.bellow();
			tree3.fotos();
			gort.drink();
			gort.bellow();			
			water.rain();
			gort.eat();
			
			std::cout << "Air " << air << "  Water " << wat << "  Grass "  << gras << std::endl;
			--i;
		}
	}
}

