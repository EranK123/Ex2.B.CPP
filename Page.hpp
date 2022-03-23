#include "Direction.hpp"
#include <iostream>
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