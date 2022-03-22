#include <string>
#include "Direction.hpp"
namespace ariel{
class Notebook{
private:
// char ***notebook;
public:
    Notebook();
    void write(int page, int row, int col, Direction dir, std::string const & s);
    static std::string read(int page, int row, int col, Direction dir, int len);
    void erase(int page, int row, int col, Direction dir, int len);
    void show(int page);
};
}