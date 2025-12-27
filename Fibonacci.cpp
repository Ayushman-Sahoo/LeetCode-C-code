#include <iostream>
using namespace std;
// Recursive function to find Fibonacci number
int fibonacci(int n) {
    if (n == 0)
        return 0;          // base case 1
    if (n == 1)
        return 1;          // base case 2
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is " << fibonacci(n) << endl;

    return 0;
}
//loop
/*#include <iostream>
using namespace std;

int main() {
    int n;
    int a = 0, b = 1, c;

    cout << "Enter number of terms: ";
    cin >> n;

    cout << "Fibonacci series: ";

    for (int i = 1; i <= n; i++) {
        cout << a << " ";
        c = a + b;
        a = b;
        b = c;
    }

    return 0;
}
    */