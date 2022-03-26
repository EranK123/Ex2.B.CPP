#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include "Page.cpp"
using namespace std;  
using namespace ariel;
using ariel::Direction;

  void Notebook::write(int page, int row, int col, Direction dir, string const & s){
     if(page < 0 || row < 0 || col < 0 || col > x){
        throw std::invalid_argument("Bad Inputs"); 
    }
    notebook[page].write(row, col, dir, s);
}

string Notebook::read(int page, int row, int col, Direction dir, int len){
    if(page < 0 || row < 0 || col < 0 || col > x || len < 0 || len > x || notebook.count(page) == 0){
        throw std::invalid_argument("These numbers cannot be applied"); 
    }
    return notebook[page].read(row, col, dir, len);
}

void Notebook::erase(int page, int row, int col, Direction dir, int len){
      if(page < 0 || row < 0 || col < 0 || col > x || len < 0 || len > x){
        throw std::invalid_argument("These numbers cannot be applied"); 
    }
    return notebook[page].erase(row, col, dir, len);
}

void Notebook::show(int page){
    if(page < 0 || notebook.count(page) == 0){
        throw std::invalid_argument("These numbers cannot be applied"); 
    }
    cout << "Page: " << page << endl;
    notebook[page].show();
}

int main(){
    Notebook n;
    n.write(0, 0, 3, Direction::Horizontal, "HEY");
    n.write(0, 4, 3, Direction::Horizontal, "HEY");
    n.write(0, 16, 25, Direction::Horizontal, "HEY");
    n.write(1, 0, 3, Direction::Horizontal, "HEY");
    n.write(1, 4, 3, Direction::Horizontal, "HEY");
    n.write(1, 16, 25, Direction::Horizontal, "HEY");
    n.write(1, 18, 25, Direction::Vertical, "HEY");
    n.erase(0, 15, 24, Direction::Vertical, 5);
   n.show(0);
   n.show(1);

   n.show(2);

}

