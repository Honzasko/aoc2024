#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdint>

int main(){
    std::ifstream in;
    in.open("input.txt");
    if(!in.is_open()) return 1;
    
    std::vector<std::string> map;
    std::string line;
    while (std::getline(in,line)) {
        map.push_back(line);
    }
    in.close();

    uint64_t total = 0; //total number of MAS words in map in X shape

    //search loop
    //i - rows
    //j - collums

    for(size_t i = 0;i < map.size();i++){
        for (size_t j = 0;j < map[i].size();j++) {
            bool diagonal_left = false;
            bool right = false;
            if((i+2) <= (map.size()-1) && (j+2) <= (map[i].size()-1))
            {
                //diagonal left forward
                if(map[i][j+2] == 'M' && map[i+1][j+1] == 'A' && map[i+2][j] == 'S'){
                    diagonal_left = true;
                }
                //diagonal left backward
                if( map[i][j+2] == 'S' && map[i+1][j+1] == 'A' && map[i+2][j] == 'M'){
                    diagonal_left = true;
                }
                
                //diagonal right forward
                if(map[i][j] == 'M' && map[i+1][j+1] == 'A' && map[i+2][j+2] == 'S'){
                     right = true;
                }
                //diagonal right backward
                if (map[i][j] == 'S' && map[i+1][j+1] == 'A' && map[i+2][j+2] == 'M') {
                    right = true;
                }
                
            }


            if(diagonal_left == true && right == true) total++;
        
        }
    }

    std::cout << total << std::endl;
    return 0;
}