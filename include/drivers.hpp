/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef DRIVERS_HPP_INCLUDED
#define DRIVERS_HPP_INCLUDED

class Drivers
{
  private:
    std::string drivSur;
    std::string code; // in a base
    unsigned short int exp; // points of experience

  public:
    Drivers(std::string d, std::string c, short int e);
    std::string returnDSur ();
    std::string returnCode ();
    short int returnExp ();
    friend bool operator == (Drivers &driv1, std::string Code);
};



#endif // DRIVERS_HPP_INCLUDED
