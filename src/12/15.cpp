//
// Created by wfy on 2022/12/7.
//

#include "iostream"
#include "memory"

struct destination{};
struct connection{};

connection connect(destination *);
void disconnect(connection ) ;


void f(destination &dest) {
    connection con = connect(&dest);
    std::shared_ptr<connection> sharedPtr(&con, [](connection * connection) {
        disconnect(*connection);
    });

}
int main()
{

}