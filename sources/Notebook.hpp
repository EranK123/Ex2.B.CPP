#include <string>
#include "Direction.hpp"
#include "Page.hpp"
#include <unordered_map>
namespace ariel{
class Notebook{
private:
static unordered_map<int, Page> notebook;
public:
    // Notebook();
    static void write(int page, int row, int col, Direction dir, std::string const & s);
    static std::string read(int page, int row, int col, Direction dir, int len);
    static void erase(int page, int row, int col, Direction dir, int len);
    static void show(int page);
};
}