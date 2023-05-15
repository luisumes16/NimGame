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


void partida(){
    cout<<"vamos por la vuelta"<<vueltas<<" "<<endl;
    cout<<"PUNTO PLAY1: "<<puntos_jugador1<<" PUNTOS PLAY2: "<<puntos_jugador2<<endl;

}



int piramide(string jugador1, string jugador2, int fila1, int fila2, int fila3, bool turno, int total, int ganados){
    if(total != 0) {
        cout << total << endl;
        cout << turno << endl;
        cout << fila1 << " " << fila2 << " " << fila3 << endl;
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
                cout<<"ha ganado el jugador "<<jugador1<<" obtiene "<<puntos_jugador1<<" puntos"<<endl;
                /*
                puntos_jugador2 = puntos_jugador2+3;
                cout<<"el jugador: "<<jugador2<<" ha ganado"<<"tiene: "<<puntos_jugador1<<"puntos"<<endl;
                */
            } else {
                puntos_jugador2 = puntos_jugador2+3;
                cout<<"ha ganado el jugador "<<jugador2<<" obtiene "<<puntos_jugador2<<" puntos"<<endl;
                /*
                puntos_jugador1 = puntos_jugador1+3;
                cout<<"el jugador: "<<jugador1<<" ha ganado"<<"tiene: "<<puntos_jugador1<<"puntos"<<endl;
                */
            }
        }


        /*
         * if(total == 0){
            return 3;
            /*
            puntos_jugador1 = puntos_jugador1+1;
            cout<<"los jugadores han empatado"<<puntos_jugador1<<endl;
            */

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
    int partida;
    int veces;

    cout<<"ingrese el nombre del jugador 1"<<endl;
    cin>>jugador1;

    cout<<"ingrese el nombre del jugador 2"<<endl;
    cin>>jugador2;


    do{
        resultado = piramide(jugador1, jugador2, fila1, fila2, fila3, turno, total, ganados);
        cout<<resultado<<endl;
        
        partida();

        if(resultado==1) {
            //Termino
            anterior_jugador1 = puntos_jugador1;
            anterior_jugador2 = puntos_jugador2;
            cout<<"YA TERMINO"<<endl;

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
