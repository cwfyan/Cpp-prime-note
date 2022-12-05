
#include "fstream"
#include "iterator"
int main()
{
    std::fstream out("D:\\C++\\CPP prime note\\src\\chapter10\\number.txt");
    std::ostream_iterator<int> ostreamIterator(out, "\n");
    size_t count = 1000;
    while ( --count ) {
        ostreamIterator = rand();
    }
}