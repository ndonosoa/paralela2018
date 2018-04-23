#include <iostream>
#include <fstream>
#include <string>


using namespace std;



int LeerFichero(char nombre[]){
	ifstream infile(nombre);
	string line;
	int i=0;
		
		while(getline(infile,line)){
			i++;
		}
		
		return i-1;
}

int main(int argc, char* argv[]){

	int total=0;
	total = LeerFichero(argv[1]);
	cout<<"La cantidad de datos es: "<<total<<endl;

	return 0;
}