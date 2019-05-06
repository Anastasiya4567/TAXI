/* Anastasiya Chaplianskaya
prowadzacy: Wiktor Kusmirek
projekt2 - Korporacja taksowkarska
*/
#ifndef CLIENTS_HPP_INCLUDED
#define CLIENTS_HPP_INCLUDED

class Clients
{
    private:
        std::string cliSur;
        std::string cliName;
        double discount; //in %
    public:
        Clients (std::string s, std::string n, double d);
        std::string returnCSur ();
        std::string returnCName ();
        double returnDis ();
        void returnDis (double discount2); //overload function, it really only changes the value of discount
};

#endif // CLIENTS_HPP_INCLUDED
