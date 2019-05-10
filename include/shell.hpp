/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef SHELL_HPP_INCLUDED
#define SHELL_HPP_INCLUDED

#include <vector>

#include "autos.hpp"
#include "drivers.hpp"
#include "clients.hpp"

class Shell
{
    private:
    std::vector <Auto<short int>> vCars;
    std::vector <Driver> vDrivers;
    std::vector <Client> vClients;

    public:
    Shell () {};
    void start ();
    void processing ();
    void help();
    void AddAuto ();
    void DeleteAuto (std::string name);
    void ShowAutos ();
    void AddDriver ();
    template <typename K> void DeleteDriver (K code);
    void ShowDrivers ();
    void AddClient ();
    void DisChange (std::string surname, double discount2);
    void ShowClients ();
};

#endif // SHELL_HPP_INCLUDED
