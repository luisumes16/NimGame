/* Nuestro juego NIM
Brayan de León, 202307024
Luis Colop, 202308052
Heber Garcia: 202307031
*/

#include <iostream>
using namespace std;


int piramide(int puntosjugador2, int puntosjugador1, int total, bool turno, string jugador1, string jugador2, int fila1, int fila2, int fila3){
	
	cout<<endl;
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
	
	//evaluacion de puntos ganados
	if(total==1){
		if(turno==true){
		return 1;
		/*puntosjugador2=puntosjugador2+3;
		cout<<"ha ganado el jugador "<<jugador2<<endl;
		cout<<puntosjugador2<<" puntos"<<endl;*/
	}else{
		return 0;
		/*puntosjugador1 = puntosjugador1+ 3 ;
		cout<<"Ha ganado el jugador "<<jugador1<<endl;
		cout<<puntosjugador1<<" puntos"<<endl;*/
	}
		
	}
	
	
	//turnos de los jugadores
	if(turno==true){
		cout<<endl;
		cout<<"turno del jugador "<<jugador1<<endl;
		turno=false;
	}else{
		cout<<endl;
		cout<<"turno del jugador "<<jugador2<<endl;
		turno=true;
	}
	
	//Quitar puntos y seleccion de fila
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
			total=total-restante;
		}
		piramide(puntosjugador2, puntosjugador1, total, turno, jugador1, jugador2, fila1, fila2, fila3);
		break;
		
	case 2:
		if(restante>fila2){
			cout<<"numero es invalido"<<endl;
		}else{
		fila2 = fila2 - restante;
		total=total-restante;
		}
		piramide(puntosjugador2, puntosjugador1, total, turno, jugador1, jugador2, fila1, fila2, fila3);
		break;
		
	case 3:
		   if(restante>fila3){
			   cout<<"numero invalido"<<endl;
		   }else{
			fila3 = fila3 - restante;
			total=total-restante;
		
		}
		piramide(puntosjugador2, puntosjugador1, total, turno, jugador1, jugador2, fila1, fila2, fila3);
		
	default:
	break;
	}
	

}
	
	int main(){
		int fila1 = 3;
		int fila2 = 5;
		int fila3 = 7;
		string jugador1="";
		string jugador2="";
		bool turno=true;
		int total=15;
		int puntosjugador1=0;
		int puntosjugador2=0;
		bool avanzar=true;
		int resultado=0;
		int opcion1=0;
		
		
		cout<<"ingrese el nombre del jugador 1"<<endl;
		cin>>jugador1;
		
		cout<<endl;
		
		cout<<"ingrese el nombre del jugador 2"<<endl;
		cin>>jugador2;
		
		do{
			
			resultado= piramide(puntosjugador2, puntosjugador1, total, turno, jugador1, jugador2, fila1, fila2, fila3);
		if(resultado==1){
			cout<<"ha ganado el jugador "<<jugador2<<endl;
		}else{
			cout<<"ha ganado el jugador "<<jugador1<<endl;
			
		}
		
		cout<<"Desea continuar el juego? si [1] no [2]"<<endl;
		   cin>>opcion1;
		   
		   if(opcion1==2){
			   avanzar=false;
		   }
			
		} while(avanzar==true);
	

		
		return 0;
	}
		

