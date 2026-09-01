#include <iostream>
#include <string>
using namespace std;

const int PAUS = 1;
const int COPAS = 2;
const int ESPADAS = 3;
const int OURO = 4;

struct carta{
    int valor;
    int naipe;
   };

void mostrarNaipe (int naipe){
        if (naipe == 1)
        {
            cout << "Paus" << endl;
        }
        else if (naipe == 2)
        {
            cout << "Copas" << endl;
        }
        else if (naipe == 3)
        {
            cout << "Espadas" << endl;
        }
        else if (naipe == 4)
        {
            cout << "Ouro" << endl;
        }
        
    }


    // P = 1 
    // C = 2 
    // E = 3  
    // O = 4       

    //4  = 4
    //5  = 5
    //6  = 6
    //7  = 7
    //Q  = 8
    //J  = 9
    //K  = 10
    //A  = 11
    //2  = 12
    //3  = 13


int main(){
   carta carta1;

        carta1.valor = 4;
        carta1.naipe = PAUS;
        mostrarNaipe(carta1.naipe);


    cout << "Carta 1: " << carta1.valor << " de ";
    mostrarNaipe(carta1.naipe);

return 0;
}

 
