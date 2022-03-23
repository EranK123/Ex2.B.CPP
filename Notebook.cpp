#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>
#include "Page.hpp"
using namespace std;  
using namespace ariel;
using ariel::Direction;

// Notebook::Notebook(){
  
// }

void Notebook::write(int page, int row, int col, Direction dir, string const & s){
     if(page < 0 || row < 0 || col < 0 || col > 100){
        throw std::invalid_argument("Bad Inputs"); 
    }
    notebook[page].write(row, col, dir, s);
}

string Notebook::read(int page, int row, int col, Direction dir, int len){
    if(page < 0 || row < 0 || col < 0 || col > 100 || len < 0 || len > 100){
        throw std::invalid_argument("Negative numbers cannot be applied"); 
    }
    return notebook[page].read(row, col, dir, len);
}

void Notebook::erase(int page, int row, int col, Direction dir, int len){
      if(page < 0 || row < 0 || col < 0 || col > 100 || len < 0 || len > 100){
        throw std::invalid_argument("Negative numbers cannot be applied"); 
    }
    return notebook[page].erase(row, col, dir, len);
}
void Notebook::show(int page){
    if(page < 0){
        throw std::invalid_argument("Negative numbers cannot be applied"); 
    }
    notebook[page].show();
}

int main(){
    Notebook n;
    n.write(0, 0, 3, Direction::Horizontal, "HEY");
   cout << n.read(0, 0, 3, Direction::Horizontal, 3) << endl;

}

