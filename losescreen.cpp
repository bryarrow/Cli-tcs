#pragma once

#include <iostream>

void losescreen(){
    std::cout<<"               you lose";
    std::cout<<std::endl<<"pass any key to quit";
    getchar();
    exit(0);
}