#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void AbrirArchivo(){
    int i=0,codigo, var=0,cont=0;

    ifstream infile("utem.csv");
  string line, asd;
  string delimeter = ",";  
    while(getline(infile,line) && i<10){
      /*asd.substr(line.rfind(delimeter));
      cout<<asd<<endl;*/
      if(var==0){
        var=1;
      }else{
        string token;
      stringstream ss(line);
      char delimeter = ',';
        while(getline(ss,token, delimeter)){
          if(cont==2){
            if(token == "2018"){
              cout<<"you are right mothafucka"<<endl;
            }
            cout<<token<<endl;
          }
          cont++;
        }
      cont=0;
      i++;
      }
      
    }
    
}

int main(){
  AbrirArchivo();
}
  /*MPI_Status status;
  //size = numero de procesadores, desde el 0.
  //rank = procesador en uso
  int rank, size;

  MPI::Init();
  rank = MPI::COMM_WORLD.Get_rank(); //Se le asigna el procesador que se está usando
  size = MPI::COMM_WORLD.Get_size();
  int rango[2];
  Punto pto[5000];
  float perimetro[1],aux=0;

  LlenarPuntos(pto);
  if(rank==0){
	rango[0] = 0;
	rango[1] = 3221;
	MPI_Send(rango, 2, MPI_INT,1,0, MPI_COMM_WORLD);
	rango[0] = 3222;
	rango[1] = 6444;
	MPI_Send(rango, 2, MPI_INT,2,0, MPI_COMM_WORLD);
	rango[0] = 6445;
	rango[1] = 9665;
	MPI_Send(rango, 2, MPI_INT,3,0, MPI_COMM_WORLD);

	MPI_Recv(perimetro, 1, MPI_FLOAT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	aux = aux + perimetro[0];
	MPI_Recv(perimetro, 1, MPI_FLOAT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	aux = aux + perimetro[0];

	MPI_Recv(perimetro, 1, MPI_FLOAT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	aux = aux + perimetro[0];

	cout<<"El perimetro final es: "<<aux<<endl;

  }
  if(rank==1){
  	MPI_Recv(rango, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  	FILE *infile;
  	int x,y,z,cont=0;
  	infile = fopen("triangulos", "r");
  	//cout<<"el rango inf y superior son: "<<rango[0]<<" "<<rango[1]<<endl;
  	while(!feof(infile)){
  		fscanf(infile,"%d %d %d\n", &x,&y,&z);
  		if(cont>=rango[0] && cont<=rango[1]){
  		perimetro[0] += CalcularDistancias(pto,x,y,z);
  		}
  		cont++;

  	}
  	MPI_Send(perimetro, 1, MPI_FLOAT,0,0, MPI_COMM_WORLD);
  	//cout<<"Hola este es el perimetro: "<<perimetro<<endl;
  }
  if(rank==2){
  	MPI_Recv(rango, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  	FILE *infile;
  	int x,y,z,cont=0;
  	infile = fopen("triangulos", "r");
  //	cout<<"el rango inf y superior son: "<<rango[0]<<" "<<rango[1]<<endl;

  	while(!feof(infile)){
  		fscanf(infile,"%d %d %d\n", &x,&y,&z);
  		if(cont>=rango[0] && cont<=rango[1]){
  		perimetro[0] += CalcularDistancias(pto,x,y,z);
  		}
  		cont++;

  	}
  	MPI_Send(perimetro, 1, MPI_FLOAT,0,0, MPI_COMM_WORLD);
  //	cout<<"Hola este es el perimetro: "<<perimetro<<endl;

  }
  if(rank==3){
  	MPI_Recv(rango, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  	FILE *infile;
  	int x,y,z,cont=0;
  	infile = fopen("triangulos", "r");
  //	cout<<"el rango inf y superior son: "<<rango[0]<<" "<<rango[1]<<endl;

  	while(!feof(infile)){
  		fscanf(infile,"%d %d %d\n", &x,&y,&z);
  		if(cont>=rango[0] && cont<=rango[1]){
  		perimetro[0] += CalcularDistancias(pto,x,y,z);
  		}
  		cont++;
  	}
  	MPI_Send(perimetro, 1, MPI_FLOAT,0,0, MPI_COMM_WORLD);
  //	cout<<"Hola este es el perimetro: "<<perimetro<<endl;

  }
 
  //cout<<"La suma del perimetro total es: "<<perimetro<<endl;
  //MostrarPuntos(pto);
  MPI_Finalize();
	
	return 0;
}*/
