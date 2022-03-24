#include "sources/Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Page.hpp"
using namespace std;  
using namespace ariel;
using ariel::Direction;


string init_string(unordered_map<int, string> page, int row){
    if(page.count(row) == 0){
        for(int i = 0; i < 100; i++){
            page[row].append("_");
        }
    }
    return page[row];
}

void Page::write(int row, int col, Direction dir, std::string const & s){
    page[row] = init_string(page, row);
    if(dir == Direction::Horizontal){
        for(int i = 0; i < s.length(); i++){
            if(page[row].at(col) == '~'){
                throw std::invalid_argument("Cant write on deleted text"); 
            }
            page[row].insert(col, 1, s[i]);
            col++;
            if(col > 100){
                throw std::invalid_argument("Reached the limit of th row"); 
            }

        }
    }else{
         for(int i = 0; i < s.length(); i++){
              if(page[row].at(col) == '~'){
                throw std::invalid_argument("Cant write on deleted text"); 
            }
             page[row].insert(col, 1, s[i]);
             row++;
             page[row] = init_string(page, row);
         }
    }
}

std::string Page::read(int row, int col, Direction dir, int len){
    string s;
    if(dir == Direction::Horizontal){
        for(int i = 0; i < len; i++){
            s += page[row].at(col);
            col++;
              if(col > 100){
                throw std::invalid_argument("Reached the limit of th row"); 
            }
        }
    }else{
        for(int i = 0; i < len; i++){
            s += page[row].at(col);
            row++;
    }
}
return s;
}

void Page::erase(int row, int col, Direction dir, int len){
    if(dir == Direction::Horizontal){
        for(int i = 0; i < len; i++){
            page[row].replace(col, 1, "~");
            col++;

        }
    }else{
        for(int i = 0; i < len; i++){
            page[row].replace(col, 1, "~");
            row++;   
    }
}
}

int cmp(pair<int, string> a, pair<int,string> b){
    return a.first < b.first;
}

void Page::show(){
    vector<pair<int, string> > v(page.begin(), page.end());
    std::sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < v.size(); i++)
{
    cout << v[i].first << " :: " << v[i].second << endl;
}
}


// int main(){
//     Page p;
//     p.write(0,3,Direction::Horizontal, "HEY");
//     p.write(5,3,Direction::Vertical, "HEY");
//     // p.erase(5,3,Direction::Vertical, 2);
//     p.write(12,26,Direction::Horizontal, "HEY");
//     cout << p.read(0,3,Direction::Horizontal, 3) << endl;
//     p.show();


//     return 0;
// }
