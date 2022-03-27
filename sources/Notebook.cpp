#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
// #include "Page.cpp"
using namespace std;  
using namespace ariel;
using ariel::Direction;

    const int x = 100;

  void Notebook::write(int page, int row, int col, Direction dir, string const & s){
     if(page < 0 || row < 0 || col < 0 || col >= x){
        throw std::invalid_argument("Bad Inputs"); 
    }
    notebook[page].write(row, col, dir, s);
}

string Notebook::read(int page, int row, int col, Direction dir, int len){
    if(page < 0 || row < 0 || col < 0 || len < 0){
        throw std::invalid_argument("These numbers cannot be applied"); 
    }
    return notebook[page].read(row, col, dir, len);
}

void Notebook::erase(int page, int row, int col, Direction dir, int len){
      if(page < 0 || row < 0 || col < 0 || col >= x || len < 0){
        throw std::invalid_argument("These numbers cannot be applied"); 
    }
    return notebook[page].erase(row, col, dir, len);
}

void Notebook::show(int page){
    if(page < 0){
        throw std::invalid_argument("These numbers cannot be applied"); 
    }
    cout << "Page: " << page << endl;
    notebook[page].show();
}

// int main(){
//     ariel::Notebook notebook;
//         notebook.write(1, 1, 10, Direction::Horizontal, "hello world");
//         notebook.write(1, 1, 8, Direction::Horizontal, "bye");
//         notebook.show(1);
   

// }

