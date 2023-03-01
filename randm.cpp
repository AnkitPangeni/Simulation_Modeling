#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
// Mixed Congruential Method
int a = 3,b=4 ,c = 2, m = 7, x = 5; // choose values for a, c, m, and x
{
for (int i = 0; i < 10; i++)
{
      x = (a * x + c) % m;
     cout << x << " "; 
}
cout << endl;


// Additive Congruential Method

for (int i = 0; i < 10; i++)
{
    x = (x + c) % m; 
    cout << x << " "; 
}
cout << endl;

// Multiplicative Congruential Method

for (int i = 0; i < 10; i++)
{
    x = (a * x) % m; 
    cout << x << " "; 
}
cout << endl;

// Arithmetic Congruential Method

for (int i = 0; i < 10; i++)
{
    x = (a  + b) % m; 
    a=b;
    b=c;
    cout << x << " "; 
}
cout << endl;
}

return 0;
}
