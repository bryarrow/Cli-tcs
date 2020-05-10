#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Map.cpp"
#include "play.cpp"
#include "hellopage.cpp"
#include "systemset"


void settings(){
    int tx,ty;
    RESET:
    char sure;
    std::cout<<"请设置地图的高（默认为30,最大200）。" <<std::endl;
    std::cin>>ty;
    std::cout<<"请设置地图的宽（默认为80,最大200）。"<<std::endl;
    std::cin>>tx;
    std::cout<<"地图的高将被设为"<<ty<<",宽将被设为"<<tx<<",确定吗？(Y or n)"<<std::endl;
    std::cin>>sure;
    if(sure=='y'||sure=='Y'){
        x=tx;
        y=ty;
    }
    else{
        goto RESET;
    }
}

int main (){
    while(1){
        hellopage();
        char mode;
        std::cin>>mode;
        switch (mode){
            case 'p':
                play();
                break;
            case 'P':
                play();
                break;
            case 's':
    	        settings();
        	    break;
	        case 'S':
    	        settings();
        	    break;
	        case 'q':
    	        return 0;
        	case 'Q':
	            return 0;
    	    default:
        	    break;
        	}
    
        clean(SYS);
    }
    return 0;
}