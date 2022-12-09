//
// Created by wfy on 2022/12/7.
//

#include "iostream"
#include "memory"

struct destination{};
struct connection{};

connection connect(destination *);
void disconnect(connection ) ;

void release(connection *p) {
    disconnect(*p);
}
void f(destination &dest) {
    connection con = connect(&dest);
    std::shared_ptr<connection> sharedPtr(&con, release);

}
int main()
{

}