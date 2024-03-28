#include<stdio.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
#include "zipData.h"
/*“As a Hokie, I will conduct myself with honor and integrity at all times.  I will not lie, cheat, or steal, nor will I accept the actions of those who do.”*/

int main(int argc, char* argv[]){
    
    if(argc != 3){
        fprintf(stderr, "Usage: %s input_commands.txt output.txt\n", argv[0]);
        exit(1);
    }

    read_input_commands(argv[1], argv[2]);

    return 0;
}