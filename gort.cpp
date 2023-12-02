#include <iostream>
#include <chrono>
#include <thread>

bool sun;
int air = 30;
int gras = 10;
int wat = 50;
int tree = 3;

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

struct World{
	char** garden;
};

World* make_world(Tree tree){
	World world;
		world.garden = new (char*)[6];
		for(int i = 0; i < 6; ++i){
			world.garden[i] = new (char)[20];
		}
		

		for(int i = 0; i < 6; ++i){
			world.garden[5][i] = '\';
		}

		for(int i = 0; i < 5; ++i){
			for(int j = 0; j < 20; ++j){
				world.garden[i][j] = '-';	
			}
		}
		int a = 20;
		while(tree){
			a -= 3;			
			world.garden[2][a] = 'n';
			world.garden[3][a] = 'U';
			world.garden[4][a] = '|';
			--tree;
		}
	return world;
}

void The_End(World* world){
	for(int i = 0; i < 6; ++i){
		delete[] world.garden[i];
	}
	delete[] world.garden;
	world.garden = nullptr;
}


void Day();

	struct Tree tree1;
    struct Tree tree2;
	struct Tree tree3;
	struct Gort gort;

int main(){
	World* world = make_world(tree);
	Day(world);

	The_End(world);
}
void Day(World* world){
	while (true){
		int i = 101;
		while(i & 1){
			
			if(sun){
				world.garden[0][0] = 'S';
				for(int i = 0; i < 6; ++i){
					std::cout << std:;endl;
					for(int j = 0; j < 20; ++j){
						std::cout << world.garden[i][j];
					}
				}
				
				grass.to_grow();
				tree1.fotos();
				gort.drink();
				gort.eat();
				tree2.fotos();
				gort.bellow();
				tree3.fotos();
				gort.drink();
				gort.bellow();		
			
			}else{
				world.garden[0][0] = 'S';
				
				for(int i = 0; i < 5; i += 2)
					for(int j = 0; j < 20; ++j){
						if(world.garden[i][j] == '-'){
							world.garden[i][j] = '"';
						}
					}
				}
				for(int i = 0; i < 6; ++i){
					std::cout << std:;endl;
					for(int j = 0; j < 20; ++j){
						std::cout << world.garden[i][j];
					}
				}

				water.rain();

			}

			std::this_thread::sleep_for(std::chrono::seconds(5));
			sun = !sun;
			std::cout << "SUN  " << sun << std::endl;
			
			
			std::cout << "Air " << air << "  Water " << wat << "  Grass "  << gras << std::endl;
			--i;
		}
	}
}

