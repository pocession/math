// A practice of Newton Raphson method to solve equations by c

# include <math.h>
# include <stdio.h>
# include <cs50.h>

typedef double (*TFunc)(double);

// df(Xn)
double df(TFunc f, double x)
{
    const double dx = 1.0e-6;
    double dy = f(x+dx) - f(x-dx);
    return dy / (2.*dx);
}

// f(Xn)
double f(double x)
{
    return x*x - 25;
}

// find Xn+1
double iter_f(double float_input, double fx, double dfx)
{
    double x;
    return x = float_input - (fx / dfx);
}

int main()
{
    printf("The function is (x*x - 25); now enter a float as an initial guess: ");
    double float_input = get_float(); // user input, initial guess, x0
    double dfx = df(f, float_input); // get the derivative df(x)
    double fx = f(float_input); // get f(x)
    double x1 = iter_f(float_input, fx, dfx); //get Xn+1 = Xn - f(Xn)/df(Xn)
    printf("Initail guess, x0, is: %lf\n", float_input);
    printf("df(x0) is: %lf\n", dfx);
    printf("x1 is: %lf\n", x1);

}