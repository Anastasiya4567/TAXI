/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef CLIENTS_HPP_INCLUDED
#define CLIENTS_HPP_INCLUDED

class Client
{
    private:
        std::string cliSur;
        std::string cliName;
        double discount; //in %
    public:
        Client (std::string s, std::string n, double d);
        std::string getCSur ();
        std::string getCName ();
        double getDis ();
        void getDis (double discount2); //overload function, it really only changes the value of discount
};

#endif // CLIENTS_HPP_INCLUDED
