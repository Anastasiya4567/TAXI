/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef AUTOS_HPP_INCLUDED
#define AUTOS_HPP_INCLUDED

template <class T> class Auto
{
  private:
    std::string nameTaxi;
    std::string colour;
    T year;
  public:
    Auto (std::string n, std::string c=" ", T y=0);
    std::string getName ();
    std::string getColour ();
    short getYear ();
    friend bool operator == (const Auto<short int> &auto1, const std::string Name);

};

template class Auto <short int>;
template class Auto <int>;

#endif // AUTOS_H_INCLUDED
