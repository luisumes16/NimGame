 /* Nuestro juego
 Brayan de León, carnet 202307024
 Luis Colop, 202308052
 Heber Garcia 
*/

#include <iostream>
using namespace std;


void piramide(string jugador1, string jugador2, int fila1, int fila2, int fila3){
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
 
  	 //alternar turnos
	   if(turno==true){
		  cout<<"perdido "<<jugador1<<endl;
	   }else{
	  	cout<<"ganado "<<jugador2<<endl;
    	}
 
 	//turnos de los jugadores
    	if(turno==true){
		   cout<<"turno del jugador "<<jugador1<<endl;
		   turno=false;
	    }else{
		   cout<<"turno del jugador "<<jugador2<<endl;
		   turno=true;
	    }
    //Quitar puntos
    cout<<"turno: "<<jugador1<<endl:
    cout<<"Cuantos va a quitar?"<<endl;
    cin>>restante;
    cout<<"De que fila?"<<endl;
    cin>>fila;

    switch(fila){
        case 1:
            if(restante>fila1){
              cout<<"numero es invalido"<<endl;
            }else{
             fila1=fila1-restante;
            }
             piramide(jugador1. jugador2, fila1, fila2, fila3);
             break;
   
        case 2:
             if(restante>fila2){
               cout<<"numero es invalido"<<endl;
             }else{
              fila2 = fila2 - restante;
             }
             piramidre(jugador1, jugador2, fila1, fila2, fila3);
            break;
      
        case 3:
           if(restante>fila3){
            cout<<"numero es invalido"<<endl;
           }else{
            fila3 = fila3 - restante;
           }
            piramide(jugador1, jugador2, fila1, fila2, fila3);
            break;
        default:
            break;
    }


}

int main(){
    int fila1 = 3;
    int fila2 = 5;
    int fila3 = 7;
    string jugador1=" ";
    string jugador2=" ";
    bool turno=true;
    int total=15;
 
   cout<<"ingrese el nombre del jugador 1"<<endl;
   cin>>jugador1;
 
   cout<<"ingrese el nombre del jugador 2"<<endl;
   cin>>jugador2;

    piramide(jugador1, jugador2, fila1, fila2, fila3);
}

