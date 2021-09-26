#include <SDL2/SDL.h>
#include <iostream>

#include "Division.hpp"
#include "misc.hpp"

int main(){

	Division div = Division(ARMORED_DIV, Vector2(0.0,0.0), std::string("1st Armored Division"));

	std::cout<<"The 1st Armored Division has been deployed!\n";


	return 0;
}
