/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef DRIVERS_HPP_INCLUDED
#define DRIVERS_HPP_INCLUDED

class Driver
{
  private:
    std::string drivSur;
    std::string code; // in a base
    unsigned short int exp; // points of experience

  public:
    Driver (std::string c, std::string d=" ", short int e=0);
    std::string getDSur ();
    std::string getCode ();
    short int getExp ();
    friend bool operator == (const Driver &driv1, const std::string Code);
};

#endif // DRIVERS_HPP_INCLUDED
