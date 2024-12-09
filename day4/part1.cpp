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

    uint64_t total = 0; //total number of XMAS words in map

    //search loop
    //i - rows
    //j - collums

    for(size_t i = 0;i < map.size();i++){
        for (size_t j = 0;j < map[i].size();j++) {
            //forward right search
            //check if can search forward
            if(map[i].size()-j >= 4){
                //check if the word is forward
                if(map[i][j] == 'X' && map[i][j+1] == 'M' && map[i][j+2] == 'A' && map[i][j+3] == 'S'){
                    total++;
                }
                //backward
                if(map[i][j] == 'S' && map[i][j+1] == 'A' && map[i][j+2] == 'M' && map[i][j+3] == 'X') {
                    total++;
                }
            }
            
     
            //vertical search
            if(map.size()-i >= 4) {
                if(map[i][j] == 'X' && map[i+1][j] == 'M' && map[i+2][j] == 'A' && map[i+3][j] == 'S'){
                    total++;
                }

                //vertical backward search
                if(map[i][j] == 'S' && map[i+1][j] == 'A' && map[i+2][j] == 'M' && map[i+3][j] == 'X'){
                    total++;
                }
            }

            //diagonal right search
            if(map.size()-i >= 4 && map[i].size()-j >= 4){
                if(map[i][j] == 'X' && map[i+1][j+1] == 'M' && map[i+2][j+2] == 'A' && map[i+3][j+3] == 'S'){
                    total++;
                }
                //backward diagonal right search
                 if(map[i][j] == 'S' && map[i+1][j+1] == 'A' && map[i+2][j+2] == 'M' && map[i+3][j+3] == 'X'){
                    total++;
                 }
            }

            //diagonal left search
            if(map.size()-i >= 4 && j >= 3){
                if(map[i][j] == 'X' && map[i+1][j-1] == 'M' && map[i+2][j-2] == 'A' && map[i+3][j-3] == 'S'){
                    total++;
                }
                //backward diagonal left search
                if(map[i][j] == 'S' && map[i+1][j-1] == 'A' && map[i+2][j-2] == 'M' && map[i+3][j-3] == 'X') {
                    total++;
                }
            }
        
        }
    }

    std::cout << total << std::endl;
    return 0;
}