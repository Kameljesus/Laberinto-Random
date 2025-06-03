#include <iostream>
using namespace std;

void introduce_operandos(int& num1, int& num2)
{
   cout << "Primer operando: ";
   cin >> num1;
   cout << "Segundo operando: ";
   cin >> num2;
}

int main()
{
   int a, b;
   introduce_operandos(a, b);
   cout << "Ingresaste: " << a << " y " << b << endl;
   return 0;
}
