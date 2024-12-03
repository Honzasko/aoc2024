#include <cstddef>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <regex>
#include <cstdint>
#include <vector>

int main(){
    std::ifstream in;
    in.open("input.txt");
    if(!in.is_open()) return 1;
    
    std::string line;
    std::string text = "";
    while (std::getline(in,line)) {
        text += line;
    }
    in.close();

    std::regex pattern(R"(mul\s*\(\s*(\d+)\s*,\s*(\d+)\s*\))");

    std::smatch matches;

    std::sregex_iterator begin(text.begin(),text.end(),pattern);
    std::sregex_iterator end;

    std::vector<std::string> valid_instructions; 

    while (begin != end) {
        std::string instruction = begin->str();
        valid_instructions.push_back(instruction);
        begin++;
    }

    uint64_t result = 0;

    for(size_t i = 0;i < valid_instructions.size();i++){
        uint64_t x,y;
        std::sscanf(valid_instructions[i].c_str(),"mul(%llu,%llu)",&x,&y);
        result += x * y;
    
    }
    std::cout << result << std::endl;

    return 0;    
}