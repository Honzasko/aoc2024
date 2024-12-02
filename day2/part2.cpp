#include <cstddef>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>
#include <cstdint>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string t,char d){
    std::vector<std::string> result;
    std::string tx = "";
    for(size_t i = 0;i < t.size();i++)
    {
        if(t[i] == d){
            result.push_back(tx);
            tx = "";
        }
        else {
            tx += t[i];
        }
    }
    if(tx != ""){
        result.push_back(tx);
    }
    return result;
}

std::vector<std::string> lines;

bool dec(std::vector<uint64_t> x){
    for(size_t i = 1;i < x.size();i++)
    {
        if(x[i-1] < x[i] || (x[i-1] - x[i]) > 3 || x[i-1] == x[i]) return false;
    }
    return true;
}

bool inc(std::vector<uint64_t> x){
    for(size_t i = 1;i < x.size();i++)
    {
        if(x[i-1] > x[i] || (x[i] - x[i-1]) > 3 || x[i-1] == x[i]) return false;
    }
    return true;
}

bool task(std::vector<uint64_t> x){

    if(x[0] > x[1]){
        return dec(x);
    }
    else {
        return inc(x);
    }
}

int main(){
    std::ifstream in;
    in.open("input.txt");
    if(!in.is_open()) return 1;
    uint64_t total = 0;
    std::string line;
    while (std::getline(in,line)) {
        lines.push_back(line);
    }
    in.close();

    for(size_t i = 0;i < lines.size();i++){
        std::vector<std::string> l = split(lines[i], ' ');
        std::vector<uint64_t> x;
        for(size_t i = 0;i < l.size();i++){
            uint64_t n;
            std::istringstream iss(l[i]);
            iss >> n;
            x.push_back(n);
        }
        bool res = task(x);
        if(res) total++;
        else {
            int corrections = 0;
            for(size_t j = 0;j < x.size();j++)
            {
               std::vector<uint64_t> xx = x;
               xx.erase(xx.begin() + j);
               bool res2 = task(xx);
               if(res2) {
                corrections++;
               }

            }
            if(corrections == 1) total++;
        }
    }
    std::cout << total << std::endl;
    
    return 0;
}