#include <string>
#include "Direction.hpp"
#include "Page.hpp"
#include <unordered_map>
namespace ariel{
class Notebook{
private:
unordered_map<int, Page> notebook;
public:
    void write(int page, int row, int col, Direction dir, std::string const & s);
    std::string read(int page, int row, int col, Direction dir, int len);
    void erase(int page, int row, int col, Direction dir, int len);
    void show(int page);
};
}