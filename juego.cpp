 /* Nuestro juego
 Brayan de León, carnet 202307024
 Luis Colop, 202308052
 Heber Garcia 
*/

#include <iostream>
using namespace std;


void piramide(int fila1, int fila2, int fila3){
    cout<<fila1<<" "<<fila2<<" "<<fila3<<endl;
    int fila = 0;
    int restante = 0;
    cout<<"      ";
    for(int i = 0; i<fila1; i++){
        cout<<" * ";

    }
    cout<<endl;
    cout<<"   ";
    for(int i = 0; i<fila2; i++) {
        cout << " * ";
    }
    cout<<endl;
    cout<<"";
    for(int i = 0; i<fila3; i++) {
        cout << " * ";
    }
    cout<<endl;
    //Quitar puntos
    cout<<"Cuantos va a quitar?"<<endl;
    cin>>restante;
    cout<<"De que fila?"<<endl;
    cin>>fila;

    switch(fila){
        case 1:
            fila1 = fila1 - restante;
            piramide(fila1, fila2, fila3);
            break;
        case 2:
            fila2 = fila2 - restante;
            piramide(fila1, fila2, fila3);
            break;
        case 3:
            fila3 = fila3 - restante;
            piramide(fila1, fila2, fila3);
            break;
        default:
            break;
    }


}

int main(){
    int fila1 = 3;
    int fila2 = 5;
    int fila3 = 7;

    piramide(fila1, fila2, fila3);
}

