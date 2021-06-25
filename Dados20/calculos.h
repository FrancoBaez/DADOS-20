#ifndef CALCULOS_H_INCLUDED
#define CALCULOS_H_INCLUDED

//Funcion para poner vectores en cero.
void VecCero(int* vec, int tam){
    int i;
    for(i=0; i<tam; i++){
        vec[i]=0;
    }
}
//Simulacion de tirada de dados con funcion rand().
void Tirada(int* vec, int tam){
    int i;
    for(i=0; i<tam; i++){
        vec[i] = (rand()%6) + 1;
    }
}
//Funcion que muestra contenido de vectores.
void MostrarVec(int* vec, int tam){
    int i;
    for(i=0; i<tam; i++){

        cout<<vec[i]<<", ";
    }
}
//Funcion que determina el maximo de la tirada, dentro del vector dados.
int Maxtirada(int* vec, int tam){
    int i, maxtirada;
    for(i=0; i<tam; i++){
        if(i==0){
            maxtirada = vec[i];
        } else if(vec[i]>maxtirada){
            maxtirada = vec[i];
        }
    }
    return maxtirada;
}
//Funcion de Tirada de puntos, devuelve la cantidad de puntos acumulados segun reglas del juego.
int TiradaPuntos(int apuesta, int sumtiradas){
    int vec[5], i, numgp, cnumgp = 0, puntuacion;

    if(sumtiradas == 20){
        numgp=1;
    } else if(sumtiradas == 21){
        numgp=2;
    } else if(sumtiradas == 22){
        numgp=3;
    } else if(sumtiradas == 23){
        numgp=4;
    } else if(sumtiradas == 24){
        numgp=5;
    } else{
        numgp=6;
    }
    Tirada(vec, 5);
    MostrarVec(vec, 5);
    pause();
    clrscr();
    for(i=0; i<5; i++){
        if(vec[i]==numgp){
            cnumgp++;
        }
    }
    puntuacion = apuesta * cnumgp;
    return puntuacion;

}
//Funcion que escribre y guarda la maxima puntuacion dentro de la ejecucion del programa.
void MaximaPuntuacion (int puntos, int* MAXPUNTOS, char* name, char* MAXNAME){

    if(*MAXPUNTOS <= puntos){
     *MAXPUNTOS = puntos;
     strcpy(MAXNAME, name);

    }
}
//Funcion para cargar valores a vector dados.
void SimulacionTirada(int* vec, int tam){
    int i;
    for(i=0; i<tam; i++){
        cin>>vec[i];
    }
}
//Funcion para cargar valores a vector dados, en simulacion de tirada de puntos.
int TiradaPuntosSimulada(int apuesta, int sumtiradas){
    int vec[5], i, numgp, cnumgp = 0, puntuacion;

    if(sumtiradas == 20){
        numgp=1;
    } else if(sumtiradas == 21){
        numgp=2;
    } else if(sumtiradas == 22){
        numgp=3;
    } else if(sumtiradas == 23){
        numgp=4;
    } else if(sumtiradas == 24){
        numgp=5;
    } else{
        numgp=6;
    }
    SimulacionTirada(vec, 5);
    MostrarVec(vec, 5);
    pause();
    clrscr();
    for(i=0; i<5; i++){
        if(vec[i]==numgp){
            cnumgp++;
        }
    }
    puntuacion = apuesta * cnumgp;
    return puntuacion;

}
//Funcion para comparar y escribir el ganador en modo de juego: 2 jugadores.
void Winner(int puntuacionp1, int puntuacionp2, char*p1, char*p2){
    if(puntuacionp1>puntuacionp2){
        cout<<"GANADOR: "<<p1<<endl;
        cout<<"PUNTUACION: "<<puntuacionp1;
    } else{
        cout<<"GANADOR: "<<p2<<endl;
        cout<<"PUNTUACION: "<<puntuacionp2;
    }
}




#endif // CALCULOS_H_INCLUDED
