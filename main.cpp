#include <iostream>
#include "task_3_1.hpp"

using namespace std;

int main()
{   using namespace task3;
    BigNum<3> P(100);
    BigNum<3> S(50);
    BigNum<3> G(0);
    G = P + S;
    std::cout << G ;
    return 0;
}
