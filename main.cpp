#include <iostream>
#include <cstring>
using namespace std;

string tab(int tamanio, int valor){
  int espacio = 0;
  string texto = "";
  espacio = valor - tamanio;

  for(int i = 0; i < espacio; i++){
    texto = texto + " ";
  }
  return texto;
}

int main() {
  time_t ti, tf, tti, ttf;
  int npl, pts[11], hit[11], miss[11], chro[11];
  int ptst=0, hitt=0, misst=0, chrot=0;
  string name[11], nom[11], ape[11], ciu[11], col[11], cos[11];
  char con, vDatos[30];
  
  srand(time(NULL));
  char letra = 'a' + rand() % 26;
////////////////////////////////////////////////////////////////////////////////////  
cout << "Bienvenido jugador, hoy vamos a jugar stop." << endl;
cout << "Esta son las reglas: \n"<<endl;
cout << "1).Te vamos a mostrar una letra aleatoria del abecedario y con esta debes escribir una palabra en la categoria que se te pida."<<endl;
cout << "2) La palabra tiene que comenzar por la letra dada anteriormente."<<endl;
cout << "3) Con cada acierto obtienes 50 puntos, con cada error pierdes 50 puntos"<<endl;
  cout << "4) Si no sabes que escribir, solo pon un punto ( . )"<<endl;
/////////////////////////////////////////////////////////////////////////////////////
  
  cout<<"¿Quieres Jugar? (s/n): ";
  cin >> con;
  
  if (con == 's'){
    tti = time(0);
    cout << "Bienvenido(s), cuantos jugadores desean jugar (maximo 10): ";
    cin >> npl;
    cout << endl;

    for(int i=1;i<=npl;i++){//limpia los arreglos, algunos tienen residuos
      pts[i] = 0;
      hit[i] = 0;
      miss[i] = 0;
      chro[i] = 0;
    } 
    
    for(int i=1;i<=npl;i++){
      cout << "Ingrese el nombre del jugador " << i << ": ";
      cin >> name[i];
    } cout << endl;
    
    for(int i=1;i<=npl;i++){
      cout << "Bienvenid@ " << name[i] << endl;
    } cout << endl;
    
    cout << "La letra que deben usar es: " << letra << endl;
    cout << endl;
    
    for (int i=1;i<=npl;i++){
      cout << endl << "Turno del jugador " << name[i] << ": " << endl;
      ti = time(0);
      cout << "Nombre: ";
      cin >> nom[i];
      strcpy(vDatos,nom[i].c_str());
      if (vDatos[0] == letra){pts[i] = (pts[i]+50);hit[i]++;
      } else {pts[i] = (pts[i]-50);miss[i]++;}
      cout << "Apellido: ";
      cin >> ape[i];
      strcpy(vDatos,ape[i].c_str());
      if (vDatos[0] == letra){pts[i] = (pts[i]+50);hit[i]++;
      } else {pts[i] = (pts[i]-50);miss[i]++;}
      cout << "Ciudad: ";
      cin >> ciu[i];
      strcpy(vDatos,ciu[i].c_str());
      if (vDatos[0] == letra){pts[i] = (pts[i]+50);hit[i]++;
      } else {pts[i] = (pts[i]-50);miss[i]++;}
      cout << "Color: ";
      cin >> col[i];
      strcpy(vDatos,col[i].c_str());
      if (vDatos[0] == letra){pts[i] = (pts[i]+50);hit[i]++;
      } else {pts[i] = (pts[i]-50);miss[i]++;}
      cout << "Cosa: ";
      cin >> cos[i];
      strcpy(vDatos,cos[i].c_str());
      if (vDatos[0] == letra){pts[i] = (pts[i]+50);hit[i]++;
      } else {pts[i] = (pts[i]-50);miss[i]++;}
      tf = time(0);

      chro[i] = tf-ti;
      
    } cout << endl;
    ttf = time(0);
    
  cout<<" ------------------------------------------------------------------------------------------------------------------------------";
  cout<<"|JUGADOR    |  NOMBRE      |  APELLIDO    |  CIUDAD   |   COLOR    |   COSA    |  ACIERTOS  |  FALLOS  |  PUNTOS  |  Tiempo   |"<<endl;
  cout<<" ------------------------------------------------------------------------------------------------------------------------------"<< endl;
    
    for (int i=1;i<=npl;i++){
        cout<<"|"
        <<name[i]<<tab(name[i].size(),11)<<"|"
        <<nom[i]<<tab(nom[i].size(),14)<<"|"
        <<ape[i]<<tab(ape[i].size(),14)<<"|"
        <<ciu[i]<<tab(ciu[i].size(),11)<<"|"
        <<col[i]<<tab(col[i].size(),12)<<"|"
        <<cos[i]<<tab(cos[i].size(),11)<<"|"
        <<hit[i]<<tab(hit[i],11)<<"|"
        <<miss[i]<<tab(miss[i],11)<<"|"
        <<pts[i]<<tab(pts[i],11)<<"|"
        <<chro[i]<<tab(chro[i],14)<<"|"
        ;
    }
    cout<<"----------------------------------------------------------------------------------------------------------";

    for (int i=1;i<=npl;i++){
      ptst += pts[i];
      hitt += hit[i];
      misst += miss[i];
      chrot += chro[i];
    }
    cout << "\n\n\n\nESTADISTICAS TOTALES\n\n" << endl;
    cout << "\n\nTiempo Total de ejecucion: " << (ttf-tti) << " Segundos\n";
    cout << "Tiempo Total consumido por todos los jugadores: " << chrot << " Segundos\n";
    cout << "Puntos Totales: " << ptst << endl;
    cout << "Fallos Totales: " << misst << endl;
    cout << "Aciertos Totales: " << hitt << endl;
    
///////////////////////////////////////////////////////////////////////////////////////
  } else if (con != 'n') {
    cout << "No se reconoce la operacion, programa terminado." << endl;
  }
  cout << endl;
  cout << "Ya pueden irse un saludo";
  
}
