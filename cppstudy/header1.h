#include "header2.h"

using header2::foo;

namespace header1 {
    int foo();
    void bar();

    int func() {
        foo();
    }
}