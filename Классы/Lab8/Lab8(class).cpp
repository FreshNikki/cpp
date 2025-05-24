#include "Person.h"
#include "Employee.h"
#include "Dialog.h"

int main ()
{
    Person *a = new Person;
    a->Input();
    a->Show();
    
    Employee *b = new Employee;
    b->Input();
    b->Show();
    
    Dialog d;
    d.Execute();
    return 0;
}
