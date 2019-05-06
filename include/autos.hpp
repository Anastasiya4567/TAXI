/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef AUTOS_HPP_INCLUDED
#define AUTOS_HPP_INCLUDED

template <class T> class Autos
{
  private:
    std::string nameTaxi;
    std::string colour;
    T year;
  public:
    Autos (std::string n, std::string c, T y);
    std::string returnName ();
    std::string returnColour ();
    short returnYear ();

};

template class Autos <short int>;
template class Autos <int>;

#endif // AUTOS_H_INCLUDED
