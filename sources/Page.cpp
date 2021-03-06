#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Page.hpp"
using namespace std;  
using namespace ariel;
using ariel::Direction;

const int x = 100;
const int y = 32;
const int z = 126;

string init_string(unordered_map<int, string> page, int row){
    if(page.count(row) == 0){
        for(int i = 0; i < x; i++){
            page[row].append("_");
        }
    }
    return page[row];
}

void Page::write(int row, int col, Direction dir, std::string const & s){
    page[row] = init_string(page, row);
    if(dir == Direction::Horizontal){
        if(s.length() > x){
            throw std::invalid_argument("Cant write here");
        }
        for(unsigned long i = 0; i < s.length(); i++){
            if(page[row].at((unsigned long)col) == '~' || page[row].at((unsigned long)col) != '_' || s[i] == '~' || s[i] < y || s[i] > z){
                throw std::invalid_argument("Cant write here"); 
            }
            // page[row].insert((unsigned long)col, 1, s[i]);
            page[row][(unsigned long)col] = s[i];
            col++;
            if(col > x){
                throw std::invalid_argument("Reached the limit of the row"); 
            }
        }
    }else{
         for(unsigned long i = 0; i < s.length(); i++){
              if(page[row].at((unsigned long)col) == '~' || page[row].at((unsigned long)col) != '_' || s[i] == '~' || s[i] < y || s[i] > z){
                throw std::invalid_argument("Cant write here"); 
            }
            //  page[row].insert((unsigned long)col, 1, s[i]);
            page[row][(unsigned long)col] = s[i];
            row++;
            page[row] = init_string(page, row);
         }
    }
}

std::string Page::read(int row, int col, Direction dir, int len){
    string s;
    page[row] = init_string(page, row);
    if(dir == Direction::Horizontal){
        if(len > x){
            throw std::invalid_argument("Reached the limit of the row"); 
        }
        for(int i = 0; i < len; i++){
            s += page[row].at((unsigned long)col);
            col++;
              if(col > x){
                throw std::invalid_argument("Reached the limit of th row"); 
            }
        }
    }else{
        for(int i = 0; i < len; i++){
            s += page[row].at((unsigned long)col);
            row++;
            page[row] = init_string(page, row);
    }
}
return s;
}

void Page::erase(int row, int col, Direction dir, int len){
    page[row] = init_string(page, row);
    if(dir == Direction::Horizontal){
        for(int i = 0; i < len; i++){
            if(col >= x){
               throw std::invalid_argument("Cant erase here"); 
            }
            page[row].replace((unsigned long)col, 1, "~");
            col++;

        }
    }else{
        for(int i = 0; i < len; i++){
            page[row].replace((unsigned long)col, 1, "~");
            row++;
            page[row] = init_string(page, row);   
    }
}
}

int cmp(pair<int, string> & a, pair<int,string> & b){
    if (a.first < b.first){
        return 1;
    }
    return 0;
}

void Page::show(){
    vector<pair<int, string> > v(page.begin(), page.end());
    std::sort(v.begin(), v.end(), cmp);
    for (unsigned long i = 0; i < v.size(); i++)
{
    cout << v[i].first << " :: " << v[i].second << endl;
}
}


// int main(){
//     Page p;
//     p.write(0,3,Direction::Horizontal, "HEY");
//     p.write(5,3,Direction::Vertical, "HEY");
//     p.erase(13,3,Direction::Horizontal, 2);
//     p.write(12,26,Direction::Horizontal, "HEY");
//     cout << p.read(0,3,Direction::Horizontal, 3) << endl;
//     p.show();


//     return 0;

//     Page n;
//     n.write(0, 3, Direction::Horizontal, "HEY");
//     n.write(4, 3, Direction::Horizontal, "HEY");
//     n.write(16, 25, Direction::Horizontal, "HEY");
//     n.write(18, 25, Direction::Vertical, "HEY");
//     n.erase(15, 24, Direction::Vertical, 5);
//    n.show();

// }
