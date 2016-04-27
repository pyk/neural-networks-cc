/*
 * C++ version of hacker's guide to Neural Networks
 * http://karpathy.github.io/neuralnets/
 */
#include <iostream>
#include <limits>
#include <cstdlib>

/* Our goal:
 * Somehow we tweak the input x and y to increase the output
 * For x=-2, y=3 the output will be -6, we want to tweak x and y
 * to increase the output to be greater than -6 */
double forwardMultiplyGate(double x, double y)
{
    return x * y;
}

int main()
{
    std::cout << "Gate x*y for x=-2 y=3: ";
    double x = -2;
    double y = 3;
    double output = forwardMultiplyGate(x,y);
    std::cout << output << "\n";

    /* Strategy #1: Random Local Search */
    std::cout << "\nStrategy #1: Random Local Search\n";
    double tweak_amount = 0.01;
    double best_out = -std::numeric_limits<double>::infinity();
    double best_x = x;
    double best_y = y;
    for (int i = 0; i < 100; i++) {
        double r = (double)std::rand()/ (double)RAND_MAX;
        double x_try = x + tweak_amount * (r * 2 - 1);
        double y_try = y + tweak_amount * (r * 2 - 1);
        double out = forwardMultiplyGate(x_try, y_try);
        std::cout << i+1 << " : x_try=" << x_try << "\ty_try=" << y_try;
        std::cout << "\tout=" << out << "\n";
        /* take the best x and y */
        if (out > best_out) {
            best_out = out;
            best_x = x_try;
            best_y = y_try;
        }
    }
    std::cout << "Best out: " << best_out;
    std::cout << ". with x = " << best_x << " and y = " << best_y << "\n";

    /* Strategy #2: Numerical gradient */
    std::cout << "\nStrategy #2: Numerical gradient\n";
    double h = 0.00001;
    /* Compute derivative with respect to x */
    double xph = x + h;
    double fxph = forwardMultiplyGate(xph, y);
    /* derivative with respect to x */
    double dwrtx = (fxph - output)/h;
    std::cout << "drwtx: " << dwrtx << "\n";

    /* Compute derivative with respect to y */
    double yph = y + h;
    double fyph = forwardMultiplyGate(x, yph);
    /* derivative with respect to y */
    double dwrty = (fyph - output)/h;
    std::cout << "dwrty: " << dwrty << "\n";

    /* walkthrough the gradient */
    double step_size = 0.001;
    double xg1 = x + step_size * dwrtx;
    double yg1 = y + step_size * dwrty;
    double outputg1 = forwardMultiplyGate(xg1, yg1);
    std::cout << "outputg1: " << outputg1 << "\n";


}
