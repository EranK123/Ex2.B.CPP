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
    vector<vector<char> > page;
    int max_row = 1;
    public:
    Page();
    void write(int row, int col, Direction dir, std::string const & s);
    std::string read(int row, int col, Direction dir, int len);
    void erase(int row, int col, Direction dir, int len);
    void show();
    vector<vector<char> > getPage(){
        return page;
    }
};

Page::Page(){
    vector<vector<char> > page(1, vector<char>(100));
    for(int i = 0; i < max_row; i++){
        for(int j = 0; j < 100; j++){
            page[i][j] = '_';
        }
    }
}

void resize(int row, int & max_row, vector<vector<char> > page){
    page.resize(row, vector<char>(100));
    for(int i = max_row; i < row; i++){
        for(int j = 0; j < 100; j++){
            page[i][j] = '_';
        }
    }
    max_row = row;
}

void Page::write(int row, int col, Direction dir, std::string const & s){
    if(row > max_row){
        resize(row, max_row, page);
    }
    if(dir == Direction::Horizontal){
        for(int i = 0; i < s.length(); i++){
            page[row][col] = s.at(i);
            col++;
        }
    }else{
        for(int i = 0; i < s.length(); i++){
            page[row][col] = s.at(i);
            row++;
        }
    }
}

string Page::read(int row, int col, Direction dir, int len){
    string s = "";
    if(dir == Direction::Horizontal){
    for(int i = 0; i < len; i++){
        s += page[row][col];
        col++;
    } 
}else{
    for(int i = 0; i < len; i++){
        s += page[row][col];
        row++;
}
}
return s;
}




int main(){
    cout << "fa" << endl;
    Page p;
    cout << "fa" << endl;
    p.write(5,3,Direction::Horizontal, "HEY");
    cout << p.read(5,3,Direction::Horizontal, 3) << endl;
    return 0;
}

