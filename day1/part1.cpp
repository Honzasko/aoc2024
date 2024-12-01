#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstdint>
#include <vector>
#include <cstdlib>

int main(){
    std::ifstream in;
    in.open("input.txt");
    if(!in.is_open()){ 
        std::cout << "Fail to open input file" << std::endl;
        return 0;
    }

    std::string line;
    std::vector<std::uint64_t> left;
    std::vector<std::uint64_t> right;
    while (std::getline(in,line)) {
        std::uint64_t l,r = 0;
        std::sscanf(line.c_str(),"%llu %llu",&l,&r);
        left.push_back(l);
        right.push_back(r);
    }
    uint64_t total_distance = 0;

    while(!left.empty() && !right.empty()){
        std::uint64_t l = *std::min_element(left.begin(),left.end());
        std::uint64_t r = *std::min_element(right.begin(),right.end()); 
        std::cout << l << " " << r << std::endl;
        if(l > r){
            total_distance += l - r;
        }
        else {
            total_distance +=  r - l; 
        }
        left.erase(std::find(left.begin(),left.end(),l));
        right.erase(std::find(right.begin(),right.end(),r));
    }
    std::cout << total_distance << std::endl;
    in.close();
    return 0;

}