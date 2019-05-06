/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#include <iostream>

#include "autos.hpp"
#include "shell.hpp"
#include "clients.hpp"
#include "drivers.hpp"

using namespace std;

int main ()
{
    Shell obj;
    obj.start();
    obj.processing();
    return 0;
}
