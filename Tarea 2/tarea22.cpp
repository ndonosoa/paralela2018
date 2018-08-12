#include <iostream>
#include <fstream>
#include <sstream>
#include <mpi.h>


using namespace std;


int main(int argc, char* argv[]){
 	//Contar(argv[1]);
 ifstream infile(argv[1]);
	string linea;	
	MPI_Status status;
  //size = numero de procesadores, desde el 0.
  //rank = procesador en uso
	int rank, size;
  int cont1=0,cont2=0,cont3=0;
  
	int n=0;
	MPI::Init();
  rank = MPI::COMM_WORLD.Get_rank(); //Se le asigna el procesador que se está usando
  size = MPI::COMM_WORLD.Get_size();
  int cont=0, numrecv[1],receptor[2],numsent[2];
  if(rank==0){
    while(getline(infile, linea)){
     cont++; 
    }
    numsent[0] = 0;
    numsent[1] = cont/3;
    MPI_Send(numsent, 2, MPI_INT,1,0, MPI_COMM_WORLD);
    //cout<<"ya mandó al otro procesador"<<endl;
    numsent[0] = cont/3+1;
    numsent[1] = 2*(cont/3+1);
    MPI_Send(numsent, 2, MPI_INT,2, 0, MPI_COMM_WORLD);
    //cout<<"ya mandó al otro procesador"<<endl;
    numsent[0] = numsent[1]+1;
    numsent[1] = cont;
    MPI_Send(numsent,2, MPI_INT,3, 0, MPI_COMM_WORLD);
  }else if(rank==1){
    MPI_Recv(receptor, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    while(receptor[1]>receptor[0]){
      cont1++;
      receptor[0]++;
    }
    cout<<"El procesador 1 contó: "<<cont1<<endl;

  }else if(rank==2){
    MPI_Recv(receptor, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    while(receptor[1]>receptor[0]){
      cont2++;
      receptor[0]++;
    }
    cout<<"El procesador 2 contó: "<<cont2<<endl;

  }else if(rank==3){
    MPI_Recv(receptor, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    while(receptor[1]>receptor[0]){
      cont3++;
      receptor[0]++;
    }
    cout<<"El procesador 3 contó: "<<cont3<<endl;
  }
  MPI_Finalize();

}