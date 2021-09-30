#pragma once

#include "Division.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <ctime>


std::vector<int> usedNumbers;

bool hasUsed(int n){
    for(int i : usedNumbers){
        if(n==i) return true;
    }
    return false;
}

std::string getName(int t){

    std::string name = "";

    int num = rand()%250;
    while(hasUsed(num)){
        num = rand()%250;
    }

    name+=std::to_string(num);

    if(num%10 == 1) name+="st";
    else if(num%10 == 2) name+="nd";
    else if(num%10 == 1) name+="rd";
    else name+="th";

    if(t == INFANTRY_DIV) name+=" Infantry";
    else if(t == ARMORED_DIV) name+=" Armored";
    else if(t == MECH_INFANTRY_DIV) name+=" Mechanized Infantry";

    name += " Division";

    return name;

}

Division getInfantryDiv(Vector2 p, int te){
    Division d = Division(INFANTRY_DIV, p, getName(INFANTRY_DIV), te);
    d.addRegiment(INF, 7);
    d.addRegiment(INF, 7);
    d.addRegiment(MECH_INFANTRY_DIV, 3);
    return d;
}

Division getArmorDiv(Vector2 p, int te){
    Division d = Division(ARMORED_DIV, p, getName(ARMORED_DIV), te);
    d.addRegiment(ARMOR, 3);
    d.addRegiment(ARMOR, 3);
    d.addRegiment(ARMOR, 3);
    d.addRegiment(MECH_INFANTRY_DIV, 3);
    d.addRegiment(MECH_INFANTRY_DIV, 3);
    return d;
}

Division getMechDiv(Vector2 p, int te){
    Division d = Division(MECH_INFANTRY_DIV, p, getName(MECH_INFANTRY_DIV), te);
    d.addRegiment(ARMOR, 3);
    d.addRegiment(MECH_INFANTRY_DIV, 7);
    d.addRegiment(MECH_INFANTRY_DIV, 3);
    d.addRegiment(MECH_INFANTRY_DIV, 3);
    return d;
}

Division getRandomDiv(Vector2 p, int te){
    if(rand()%3 == 0) return getInfantryDiv(p, te);
    if(rand()%3 == 1) return getArmorDiv(p, te);
    if(rand()%3 == 2) return getMechDiv(p,te);
}