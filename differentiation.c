// A practice of using numberical method to find derivative of a function using c
# include <stdio.h>
# include <math.h>

typedef double (*TFunc)(double);

// general approximation of derivative using symmetric difference quotient method
// df ~ (f(x+dx) - f(x-dx)) / 2*dx
double diff(TFunc f, double x)
{
  const double dx = 1.0e-9; // set the dx, a small float close to zero
  double dy = f(x+dx) - f(x-dx);
  return dy / (2.*dx);
}

// the function f
double f(double x)
{
   return x*x;
}

// get the derivative of function with x = 5 (float)
int main()
{
    double fp = diff(f, 5.);
    printf("%lf\n", fp);
}