#include <SDL2/SDL.h>
#include <iostream>

#include "Division.hpp"
#include "Regiment.hpp"
#include "misc.hpp"

int main(){

	Division div = Division(ARMORED_DIV, Vector2(0.0,0.0), std::string("1st Armored Division"));
	div.addRegiment(ARMOR, 3);

	std::cout<<"The 1st Armored Division has been deployed!\n";
	std::cout<<"has "<<div.getNumReg()<<" regiments with a total of "<<div.getMaxStrength()<<" Strength\n";


	return 0;
}
