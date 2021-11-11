#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


typedef vector<vector<int>> Plateau;
Plateau plateauVide(){
	Plateau plaVide(4);
	for(int i =0; i< 4;i++){
		plaVide[i].resize(4);
	}
	return plaVide;
}
int random_position(int max){
	srand ((unsigned)time(0));
	 return (rand()%max);
 }
	  
	
	
	
	








//Plateau plateauInitial(){

	
