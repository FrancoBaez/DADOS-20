/*
Trabajo final.
DADOS 20.
Autor: Franco Baez.
Legajo: 24915.
E-mail: franco.baez@alumnos.frgp.utn.edu.ar.
*/
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <string.h>

using namespace std;
//funciones: graficas y estetica.
#include "funciones.h"
//calculos: funciones creadas para el juego.
#include "calculos.h"



int main(){
    //seed para generar numeros aleatorios
    srand(time(NULL));
    //Enteros
    int opc, tam=5, MAX = 0, rondas, i, j, sumtiradas, apuesta, puntuacionp1, puntuacionp2, csinpuntos, cperdidapuntos, puntos;
    //Vector de dados
    int vecdados[tam];
    //Vectores strings.
    char jugador1[15], jugador2[15], MAXNAME[15];



    while(true){
        //Creacion del menu.
        textcolor(0,0);
        clrscr();
        recuadro(8, 1, 30, 16, cAZUL_CLARO, cBLANCO);
        textcolor(cNEGRO, cBLANCO);
        gotoxy(10,3);
        cout<<"1-Juego nuevo un jugador.";
        gotoxy(10, 4);
        cout<<"2-Juego nuevo dos jugadores.";
        gotoxy(10, 5);
        cout<<"3-Maxima puntuacion.";
        gotoxy(10, 6);
        cout<<"4-Modo simulado.";
        gotoxy(10, 7);
        cout<<"5-Salir.";
        gotoxy(10, 10);
        cout<<"Elegir opcion: "; cin>>opc;

        switch(opc){
            case 1:
                //MODO 1 JUGADOR
                clrscr();
                cout<<"Ingrese su nombre: "; cin>>jugador1;
                cout<<"Ingrese la cantidad de rondas que desea jugar: "; cin>>rondas;
                clrscr();
                puntuacionp1 = 0;
                csinpuntos = cperdidapuntos = 0;
                //For en j, representado cantidad de rondas a jugar.
                for(j=1; j<=rondas; j++){
                        tam = 5;
                        sumtiradas = 0;
                    cout<<"Ingresa la cantidad de puntos a apostar: "; cin>>apuesta;
                    while(apuesta<0){
                    cout<<endl<<"ERROR! la apuesta debe ser mayor a 0"<<endl;
                    cout<<"Ingrese una apuesta valida: "; cin>>apuesta;
                    clrscr();
                    }
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"TURNO DE "<<jugador1<<"\t|\t";
                    cout<<"RONDA N "<<j<<"\t|\t";
                    cout<<"PUNTOS ACUMULADOS: "<<puntuacionp1<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    //For en i cantidad de tiradas por ronda (Segun reglas del juego se tiraran 5 veces).
                for(i=1; i<=5; i++){
                    cout<<"TIRADA N "<<i<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    Tirada(vecdados, tam);
                    cout<<endl;
                    MostrarVec(vecdados, tam);
                    cout<<endl;
                    cout<<"\nMax Tirada: "<<Maxtirada(vecdados, tam)<<endl<<endl;

                    sumtiradas += Maxtirada(vecdados, tam);
                    pause();
                    tam--;
                   }
                   clrscr();
                   cout<<endl<<"Suma de tiradas maximas: "<<sumtiradas<<endl<<endl;
                   pause();
                   clrscr();
                   //if para saber si la suma de dados es mayor o menor a 20, de ser mayor a 20 se ejecuta la funcion
                   //TiradaPuntos();
                   if(sumtiradas >= 20){
                     cout<<"Tirada de puntaje: "<<endl;
                    pause();
                     puntos=TiradaPuntos(apuesta, sumtiradas);
                     if(puntos == 0){
                        //Contador de rondas sin puntos
                        csinpuntos++;
                     } else{
                         puntuacionp1 += puntos;
                     }

                   } else{
                       //salida y contador donde la suma de dados no es mayor a 20.
                       cout<<"La suma de tus dados no es mayor o igual a 20 :("<<endl;
                       cout<<"Pierdes los puntos apostados."<<endl;
                       pause();
                       puntuacionp1 -= apuesta;
                       cperdidapuntos++;

                   }

                }
                //Salida con los datos pedidos para modo un jugador.
                cout<<"JUGADOR: "<<jugador1<<endl;
                cout<<"CANTIDAD RONDAS SIN PUNTOS: "<<csinpuntos<<endl;
                cout<<"CANTIDAD DE RONDAS CON PERDIDA DE PUNTOS: "<<cperdidapuntos<<endl;
                cout<<"CANTIDAD DE PUNTOS ACUMULADOS: "<<puntuacionp1<<endl;
                cout<<"Para volver al menu precione cualquier tecla";
                pause();
                MaximaPuntuacion (puntuacionp1, &MAX, jugador1, MAXNAME);

                break;
            case 2:
                //MODO DOS JUGADORES.
                clrscr();
                system("color 0A");
                cout<<"Ingrese nombre de jugador 1: "; cin>>jugador1;
                cout<<"Ingrese nombre de jugador 2: "; cin>>jugador2;
                cout<<"Ingrese la cantidad de rondas que desean jugar: "; cin>>rondas;
                clrscr();
                puntuacionp1 = 0;
                puntuacionp2 = 0;
                //For en j, representado cantidad de rondas a jugar.
                for(j=1; j<=rondas; j++){
                        tam = 5;
                        sumtiradas = 0;
                    cout<<"Apuesta "<<jugador1<<endl;
                    cout<<"Ingresa la cantidad de puntos a apostar: "; cin>>apuesta;
                    clrscr();
                    while(apuesta<0){
                    cout<<endl<<"ERROR! la apuesta debe ser mayor a 0"<<endl;
                    cout<<"Ingrese una apuesta valida: "; cin>>apuesta;
                    clrscr();
                    }
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"TURNO DE "<<jugador1<<"\t|\t";
                    cout<<"RONDA N "<<j<<"\t|\t";
                    cout<<"PUNTOS ACUMULADOS: "<<puntuacionp1<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    //For en i cantidad de tiradas por ronda para jugador 1 (Segun reglas del juego se tiraran 5 veces).
                for(i=1; i<=5; i++){
                    cout<<"TIRADA N "<<i<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    Tirada(vecdados, tam);
                    cout<<endl;
                    MostrarVec(vecdados, tam);
                    cout<<endl;
                    cout<<"\nMax Tirada: "<<Maxtirada(vecdados, tam)<<endl<<endl;

                    sumtiradas += Maxtirada(vecdados, tam);
                    pause();
                    tam--;
                   }
                   clrscr();
                   cout<<endl<<"Suma de tiradas maximas: "<<sumtiradas<<endl<<endl;
                   pause();
                   clrscr();
                   if(sumtiradas >= 20){
                     cout<<"Tirada de puntaje: "<<endl;
                    pause();
                     puntos = TiradaPuntos(apuesta, sumtiradas);
                     puntuacionp1 += puntos;
                   } else{
                       cout<<"La suma de tus dados no es mayor o igual a 20 :("<<endl;
                       cout<<"Pierdes los puntos apostados."<<endl;
                       pause();
                       clrscr();
                       puntuacionp1 -= apuesta;
                   }
                        tam = 5;
                        sumtiradas = 0;
                    cout<<"Apuesta "<<jugador2<<endl;
                    cout<<"Ingresa la cantidad de puntos a apostar: "; cin>>apuesta;
                    clrscr();
                    while(apuesta<0){
                    cout<<endl<<"ERROR! la apuesta debe ser mayor a 0"<<endl;
                    cout<<"Ingrese una apuesta valida: "; cin>>apuesta;
                    clrscr();
                    }
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"TURNO DE "<<jugador2<<"\t|\t";
                    cout<<"RONDA N "<<j<<"\t|\t";
                    cout<<"PUNTOS ACUMULADOS: "<<puntuacionp2<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    //For en i cantidad de tiradas por ronda para jugador 2 (Segun reglas del juego se tiraran 5 veces).
                    for(i=1; i<=5; i++){
                    cout<<"TIRADA N "<<i<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    Tirada(vecdados, tam);
                    cout<<endl;
                    MostrarVec(vecdados, tam);
                    cout<<endl;
                    cout<<"\nMax Tirada: "<<Maxtirada(vecdados, tam)<<endl<<endl;

                    sumtiradas += Maxtirada(vecdados, tam);
                    pause();
                    tam--;
                   }
                   clrscr();
                   cout<<endl<<"Suma de tiradas maximas: "<<sumtiradas<<endl<<endl;
                   pause();
                   clrscr();
                   if(sumtiradas >= 20){
                     cout<<"Tirada de puntaje: "<<endl;
                    pause();
                     puntos = TiradaPuntos(apuesta, sumtiradas);
                     puntuacionp2 += puntos;
                   } else{
                       cout<<"La suma de tus dados no es mayor o igual a 20 :("<<endl;
                       cout<<"Pierdes los puntos apostados."<<endl;
                       pause();
                       clrscr();
                       puntuacionp2 -= apuesta;
                   }

                }
                clrscr();
                //Uso de funcion para determinar ganador.
                Winner(puntuacionp1, puntuacionp2, jugador1, jugador2);
                pause();
                if(puntuacionp1>puntuacionp2){
                   MaximaPuntuacion (puntuacionp1, &MAX, jugador1, MAXNAME);
                } else{
                   MaximaPuntuacion (puntuacionp2, &MAX, jugador2, MAXNAME);
                }


                break;
            case 3:
                system("color F3");
                if(MAX == 0){
                    clrscr();
                    cout<<"Sin juegos previos"<<endl;
                    cout<<"Toque cualquier tecla para volver al menu";
                    pause();
                } else{
                    clrscr();
                    cout<<"Jugador con mayor puntaje: "<<MAXNAME;
                    cout<<"\t|\tPuntuacion: "<<MAX<<endl;
                    cout<<"Toque cualquier tecla para volver al menu";
                    pause();

                }

                break;
            case 4:
                //MODO SIMULACION.
                system("color 50");
                clrscr();
                cout<<"Ingrese nombre de jugador 1: "; cin>>jugador1;
                cout<<"Ingrese nombre de jugador 2: "; cin>>jugador2;
                cout<<"Ingrese la cantidad de rondas que desean jugar: "; cin>>rondas;
                clrscr();
                puntuacionp1 = 0;
                puntuacionp2 = 0;
                //For en j, representando cantidad de rondas a jugar.
                for(j=1; j<=rondas; j++){
                        tam = 5;
                        sumtiradas = 0;
                    cout<<"Apuesta "<<jugador1<<endl;
                    cout<<"Ingresa la cantidad de puntos a apostar: "; cin>>apuesta;
                    clrscr();
                    while(apuesta<0){
                    cout<<endl<<"ERROR! la apuesta debe ser mayor a 0"<<endl;
                    cout<<"Ingrese una apuesta valida: "; cin>>apuesta;
                    clrscr();
                    }
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"TURNO DE "<<jugador1<<"\t|\t";
                    cout<<"RONDA N "<<j<<"\t|\t";
                    cout<<"PUNTOS ACUMULADOS: "<<puntuacionp1<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    //For en i cantidad de tiradas por ronda para jugador 1 (Segun reglas del juego se tiraran 5 veces).
                for(i=1; i<=5; i++){
                    cout<<"TIRADA N "<<i<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    SimulacionTirada(vecdados, tam);
                    cout<<endl;
                    cout<<"\nMax Tirada: "<<Maxtirada(vecdados, tam)<<endl<<endl;

                    sumtiradas += Maxtirada(vecdados, tam);
                    pause();
                    tam--;
                   }
                   clrscr();
                   cout<<endl<<"Suma de tiradas maximas: "<<sumtiradas<<endl<<endl;
                   pause();
                   clrscr();
                   if(sumtiradas >= 20){
                     cout<<"Tirada de puntaje: "<<endl;
                    pause();
                     puntos = TiradaPuntosSimulada(apuesta, sumtiradas);
                     puntuacionp1 += puntos;
                   } else{
                       cout<<"La suma de tus dados no es mayor o igual a 20 :("<<endl;
                       cout<<"Pierdes los puntos apostados."<<endl;
                       pause();
                       clrscr();
                       puntuacionp1 -= apuesta;
                   }
                        tam = 5;
                        sumtiradas = 0;
                    cout<<"Apuesta "<<jugador2<<endl;
                    cout<<"Ingresa la cantidad de puntos a apostar: "; cin>>apuesta;
                    clrscr();
                    while(apuesta<0){
                    cout<<endl<<"ERROR! la apuesta debe ser mayor a 0"<<endl;
                    cout<<"Ingrese una apuesta valida: "; cin>>apuesta;
                    clrscr();
                    }
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"TURNO DE "<<jugador2<<"\t|\t";
                    cout<<"RONDA N "<<j<<"\t|\t";
                    cout<<"PUNTOS ACUMULADOS: "<<puntuacionp2<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    //For en i cantidad de tiradas por ronda para jugador 2 (Segun reglas del juego se tiraran 5 veces).
                    for(i=1; i<=5; i++){
                    cout<<"TIRADA N "<<i<<endl;
                    cout<<"--------------------------------------------------------------------------------"<<endl;
                    SimulacionTirada(vecdados, tam);
                    cout<<endl;
                    cout<<"\nMax Tirada: "<<Maxtirada(vecdados, tam)<<endl<<endl;

                    sumtiradas += Maxtirada(vecdados, tam);
                    pause();
                    tam--;
                   }
                   clrscr();
                   cout<<endl<<"Suma de tiradas maximas: "<<sumtiradas<<endl<<endl;
                   pause();
                   clrscr();
                   if(sumtiradas >= 20){
                     cout<<"Tirada de puntaje: "<<endl;
                    pause();
                     puntos = TiradaPuntosSimulada(apuesta, sumtiradas);
                     puntuacionp2 += puntos;
                   } else{
                       cout<<"La suma de tus dados no es mayor o igual a 20 :("<<endl;
                       cout<<"Pierdes los puntos apostados."<<endl;
                       pause();
                       clrscr();
                       puntuacionp2 -= apuesta;
                   }

                }
                clrscr();
                //Uso de funcion para determinar ganador.
                Winner(puntuacionp1, puntuacionp2, jugador1, jugador2);
                pause();
                if(puntuacionp1>puntuacionp2){
                   MaximaPuntuacion (puntuacionp1, &MAX, jugador1, MAXNAME);
                } else{
                   MaximaPuntuacion (puntuacionp2, &MAX, jugador2, MAXNAME);
                }
                break;
            case 5:
                //Salir del programa.
                clrscr();
                system("color 0F");
                cout<<endl<<"Gracias por jugar Dados 20, regrese pronto!"<<endl;
                pause();
                return 0;
                break;
            default:
                //Modo Opcion no disponible/invalidacion a traves de default.
                gotoxy(9, 15);
                textcolor(cROJO_CLARO, cBLANCO);
                cout<<"Opcion invalida";
                pause();
                break;
                }
        }

}


