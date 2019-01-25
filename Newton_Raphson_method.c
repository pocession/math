// A practice of Newton Raphson method to solve equations by c

# include <math.h>
# include <stdio.h>
# include <cs50.h>
# define epsilon 0.01

// declare functions
double f(double); //f(x)
double df(double); //df(x)
double iter_f(double); // x1 = x0 - f(x0)/df(x0)
double hf(double); //fabs(f(x)/df(x))

// declare function pointer
double (*func)(double);
double (*func_f)(double);
double (*func_df)(double);
double (*func_hf)(double);


// get f(x)
double f(double x)
{
    return x*x -25;
}


// get df(x), using symmetric difference quotient method
double df(double x)
{
    double dx = 1.0e-6;
    func_f = f;
    double dy = (*func_f)(x+dx) - (*func_f)(x-dx); // pass x, dx to f(x)
    return dy / (2.*dx);
}

// get x1
double iter_f(double x)
{
    func_f = f;
    func_df = df;

    double fx = (*func_f)(x);
    double dfx = (*func_df)(x);

    double x1 = x - (fx/dfx);
    return x1;
}

// get fx/dfx
double hf(double x)
{
    func_f = f;
    func_df = df;

    double fx = (*func_f)(x);
    double dfx = (*func_df)(x);

    double h = fabs(fx/dfx);
    return h;
}

int main()
{
    printf("Enter your initial guess x0: \n");
    double x0 = get_float();
    func_f = f;
    func_df = df;
    func_hf = hf;
    func = iter_f;

    for(int i = 0; i < 9; i++) // Max steps of guessing, 10 steps
    {
        double fx = (*func_f)(x0);
        double dfx = (*func)(x0);
        double x1 = (*func)(x0);
        double hfx = (*func_hf)(x0);
        printf("%dth guess, x0: %lf, fx: %lf, dfx: %lf, fx/dfx: %lf, x1: %lf\n", i + 1, x0, fx, dfx, hfx, x1);
        if (hfx <= 0.01)
        {
            printf("End of guess at %dth step\n", i + 1);
            break;
        }
        x0 = x1;
    }
}