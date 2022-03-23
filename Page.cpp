#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <unordered_map>
using namespace std;  
using namespace ariel;
using ariel::Direction;

class Page{
    private:
    unordered_map<int, string> page; //row, text of row
    public:
    void write(int row, int col, Direction dir, std::string const & s);
    std::string read(int row, int col, Direction dir, int len);
    void erase(int row, int col, Direction dir, int len);
    void show();
    
};


string init_string(unordered_map<int, string> page, int row){
    if(page.count(row) == 0){
        for(int i = 0; i < 100; i++){
            page[row].append("_");
        }
    }
    return page[row];
}

void Page::write(int row, int col, Direction dir, std::string const & s){
    if(row < 0 || col < 0){
        throw std::invalid_argument("Negative numbers"); 
    }
    page[row] = init_string(page, row);
    int temp = s.length();
    if(dir == Direction::Horizontal){
        for(int i = 0; i < s.length(); i++){
            if(page[row].at(col) == '~'){
                throw std::invalid_argument("Cant write on deleted text"); 
            }
            page[row].insert(col, 1, s[i]);
            col++;
            temp--;
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
     if(row < 0 || col < 0){
        throw std::invalid_argument("Negative numbers"); 
    }
    string s;
    if(dir == Direction::Horizontal){
        for(int i = 0; i < len; i++){
            s += page[row].at(col);
            col++;
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
     if(row < 0 || col < 0){
        throw std::invalid_argument("Negative numbers"); 
    }
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


int main(){
    Page p;
    p.write(0,3,Direction::Horizontal, "HEY");
    p.write(5,3,Direction::Vertical, "HEY");
    p.erase(5,3,Direction::Vertical, 2);
    cout << p.read(0,3,Direction::Horizontal, 3) << endl;
    p.show();


    return 0;
}
