/*
 * C++ version of hacker's guide to Neural Networks
 * http://karpathy.github.io/neuralnets/
 */
#include <iostream>

/* Our goal:
 * Somehow we tweak the input x and y to increase the output
 * For x=-2, y=3 the output will be -6, we want to tweak x and y
 * to increase the output to be greater than -6 */
int forwardMultiplyGate(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << "Gate x*y for x=-2 y=3: ";
    std::cout << forwardMultiplyGate(-2, 3) << "\n";
}
