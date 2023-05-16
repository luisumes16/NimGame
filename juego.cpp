/* Nuestro juego
Brayan de León, carnet 202307024
Luis Colop, 202308052
Heber Garcia, 202307031
*/

#include <iostream>
using namespace std;
int puntos_jugador1 = 0;
int puntos_jugador2 = 0;
int anterior_jugador1 = 0;
int anterior_jugador2 = 0;

int vueltas=0;


void partida(string jugador1,string jugador2){
    cout<<endl;
    cout<<"Vamos por la vuelta: "<<vueltas<<endl;
    cout<<"El jugador: "<<jugador1<<", tiene: "<<puntos_jugador1<<" puntos."<<endl;
    cout<<"El jugador: "<<jugador2<<", tiene: "<<puntos_jugador2<<" puntos."<<endl;
}



int piramide(string jugador1, string jugador2, int fila1, int fila2, int fila3, bool turno, int total, int ganados){
    if(total != 0) {
        int fila = 0;
        int restante = 0;
        cout << "      ";
        for (int i = 0; i < fila1; i++) {
            cout << " * ";

        }
        cout << endl;
        cout << "   ";
        for (int i = 0; i < fila2; i++) {
            cout << " * ";
        }
        cout << endl;
        cout << "";
        for (int i = 0; i < fila3; i++) {
            cout << " * ";
        }
        cout << endl;

        //TURNOS
        if (turno == true) {
            cout << "Es el turno del jugador: " << jugador1 << endl;
            turno = false;
        } else {
            cout << "Es el turno del jugador: " << jugador2 << endl;
            turno = true;
        }

        //partidos ganados
        if (total == 1) {
            if (turno == true) {
                puntos_jugador1 = puntos_jugador1+3;
                cout<<"ha ganado el jugador "<<jugador1<<", ahora tiene "<<puntos_jugador1<<" puntos"<<endl;

            } else {
                puntos_jugador2 = puntos_jugador2+3;
                cout<<"Ha ganado el jugador "<<jugador2<<", ahora tiene "<<puntos_jugador2<<" puntos"<<endl;
            }
        }




        //Quitar puntos
        cout << "Cuantos va a quitar?" << endl;
        cin >> restante;
        cout << "De que fila?" << endl;
        cin >> fila;

        switch (fila) {
            case 1:
                if (restante > fila1) {
                    cout << "numero es invalido" << endl;
                } else {
                    fila1 = fila1 - restante;
                    total = total - restante;
                }
                piramide(jugador1, jugador2, fila1, fila2, fila3, turno, total, ganados);
                break;

            case 2:
                if (restante > fila2) {
                    cout << "numero es invalido" << endl;
                } else {
                    fila2 = fila2 - restante;
                    total = total - restante;
                }
                piramide(jugador1, jugador2, fila1, fila2, fila3, turno, total, ganados);
                break;

            case 3:
                if (restante > fila3) {
                    cout << "numero es invalido" << endl;
                } else {
                    fila3 = fila3 - restante;
                    total = total - restante;
                }
                piramide(jugador1, jugador2, fila1, fila2, fila3, turno, total, ganados);
                break;
            default:
                if (fila > 3){
                    cout<<"El numero de fila ingresado no existe"<<endl;
                }
                break;
        }
    }
    if(total == 0 && puntos_jugador1 == anterior_jugador1 && puntos_jugador2 == anterior_jugador2){
        puntos_jugador1 +=1;
        puntos_jugador2 +=1;
    }

    return 1;


}

int main(){
    int fila1 = 3;
    int fila2 = 5;
    int fila3 = 7;
    int total= 15;
    int ganados = 0;
    int resultado = 0;
    bool turno = true;
    bool avanzar = true;
    string jugador1=" ";
    string jugador2=" ";
    int opcion;

    cout<<"ingrese el nombre del jugador 1"<<endl;
    cin>>jugador1;

    cout<<"ingrese el nombre del jugador 2"<<endl;
    cin>>jugador2;


    do{
        resultado = piramide(jugador1, jugador2, fila1, fila2, fila3, turno, total, ganados);

        vueltas+=1;
        partida(jugador1,jugador2);

        if(resultado==1) {
            //Termino
            anterior_jugador1 = puntos_jugador1;
            anterior_jugador2 = puntos_jugador2;
        }else{

        }


        cout<<"desea coontinuar el juego? si [1] no [2]"<<endl;
        cin>>opcion;
        if(opcion == 2){
            avanzar = false;
        }
    } while(avanzar == true);

    cout<<"fin del juego"<<endl;

    return 0;

}
