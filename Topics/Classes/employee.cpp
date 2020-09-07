#include <iostream>

using namespace std;

#include "ccc_empl.h"

int main()
{  
   Employee cristian("Hacker, Cristian", 45000.00);

   double new_salary = cristian.get_salary() + 3000;
   cristian.set_salary(new_salary);

   cout << "Name: " << cristian.get_name() << "\n";
   cout << "Salary: " << cristian.get_salary() << "\n";

   return 0;
}

