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
    std::vector<std::string> valid_instructions; 

    std::regex pattern(R"(mul\s*\(\s*(\d+)\s*,\s*(\d+)\s*\))");
    std::regex pattern2(R"(do\(\))");
    std::regex pattern3(R"(don't\(\))");

    std::smatch matches;

    std::sregex_iterator begin(text.begin(),text.end(),pattern);
    std::sregex_iterator end;
 
    std::sregex_iterator begin2(text.begin(),text.end(),pattern2);
    std::sregex_iterator end2;

    std::sregex_iterator begin3(text.begin(),text.end(),pattern3);
    std::sregex_iterator end3;

    while (begin != end) {
        if (begin2->position() < begin->position() && begin2 != end2) {
            std::string instruction = begin2->str();
            valid_instructions.push_back(begin2->str());
            if(begin2 != end2) begin2++;
        }
        if (begin3->position() < begin->position() && begin3 != end3) {
            std::string instruction = begin3->str();
            valid_instructions.push_back(begin3->str());
            if(begin3 != end3) begin3++;
        }
         std::string instruction = begin->str();
        valid_instructions.push_back(instruction);
        begin++;
    }

    uint64_t result = 0;
    bool enabled = true;
    for(size_t i = 0;i < valid_instructions.size();i++){
        if(valid_instructions[i] == "do()"){
            enabled = true;
        }
        else if(valid_instructions[i] == "don't()"){
            enabled = false;
        }
        else {
            if(enabled){
                uint64_t x,y;
                std::sscanf(valid_instructions[i].c_str(),"mul(%llu,%llu)",&x,&y);
                result += x * y;
            }
        }
    
    }
    std::cout << result << std::endl;

    return 0;    
}