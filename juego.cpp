 /* Nuestro juego
 Brayan de León, carnet 202307024
 Luis Colop, 202308052
 Heber Garcia 
*/

#include <iostream>
using namespace std;

void piramide(int fila1, int fila2,int fila3){

    for(int i = 0; i<fila1; i++){
        cout<<"    | ";
    }
    cout<<endl;
    for(int i = 0; i<fila2; i++){
        cout<<"  | ";
    }
    cout<<endl;
    for(int i = 0; i<fila3; i++){
        cout<<" | ";
    }
    cout<<endl;

    int opcion,sustraendo;
    cout<<"\na que fila desea acceder (1,2,3)\n";
    cin>>opcion;
    cout<<"\ncuantos elementos desea retirar\n";
    cin>>sustraendo;
    switch(opcion){
        case 1:
            fila1 = fila1 - sustraendo;
            piramide(fila1,fila2,fila3);
            break;
        case 2:
            fila2 = fila2 - sustraendo;
            piramide(fila1,fila2,fila3);
            break;
        case 3:
            fila3 = fila3 - sustraendo;
            piramide(fila1,fila2,fila3);
            break;
                default: cout<<"Valor incorrecto";
    }

}

int main() {
 
    int fila1 = 3;
    int fila2 = 5;
    int fila3 = 7;
 
    piramide(fila1, fila2,fila3);


    return 0;
}
