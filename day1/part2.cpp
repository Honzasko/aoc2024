#include <cstddef>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstdint>
#include <sys/types.h>
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
    std::uint64_t total = 0;
    for(std::size_t i = 0; i < left.size();i++)
    {
        std::uint64_t t = 0;
        for(std::size_t j = 0; j < right.size();j++)
        {
            if(left[i] == right[j]) t++;
        }
        total += left[i] * t;
    }

    std::cout << total << std::endl;
    in.close();
    return 0;

}