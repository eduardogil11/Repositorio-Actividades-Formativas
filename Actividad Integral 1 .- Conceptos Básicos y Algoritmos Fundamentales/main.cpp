#include <iostream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib>

using namespace std;

struct Datos
{
  string name,champ;
  int game;
};

template <class T>
int busca(vector <T> &A, int bajo, int alto) {
	int i;
	for (i = bajo + 1; i <= alto; i++) {
		if (A[bajo] > A[i]) {
			return A[bajo];
		} else if (A[bajo] < A[i]){
			return A[i];
		}
	}
	return -1;
}

template <class T>
int particion(vector <T> &A, int bajo, int alto, int piv) {
	int i, j;
	
	i = bajo;
	j = alto;
	while (i < j) {
		swap(A[i], A[j]); 
		while (A[i] < piv) {
			i++;
		}
		while (A[j] >= piv) {
			j--;
		}
	}
	return i;
}

template <class T>
void quick(vector <T> &A, int bajo, int alto) {     
	int piv, pos;
	
	piv = busca(A, bajo, alto);
	if (piv != -1) {
		pos = particion(A, bajo, alto, piv);
		quick(A, bajo, pos - 1);
		quick(A, pos, alto);
	}
}


int main(){    
	ifstream myfile;
	char ignorar;
	vector<Datos> data;
	int d, cont, i = 0;
	vector<int> des;
  vector<int> ori;
  
	Datos datos;
	myfile.open("smash.txt");
	if (myfile)
	{
		cout <<"Super Smash Bros"<< endl;
		while (!(myfile.eof()))
		{
			myfile>>datos.name;
			myfile>>datos.game;
			getline(myfile, datos.champ);

			data.push_back(datos);

      cont = cont + 1;
		}
		myfile.close();
	}
	else
	{
		cout << "Error" << endl;
  }

  for(i=0; i < cont ; i++){
    if (data[i].name == "Super_Mario"){
      d = 100;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "Pokémon"){
      d = 200;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "The_Legend_of_Zelda"){
      d = 300;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "Kirby"){
      d = 400;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "Donkey_Kong"){
      d = 500;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "Fire_Emblem"){
      d = 600;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    
    else if (data[i].name == "Metroid"){
      d = 700;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "Star_Fox"){
      d = 800;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
    else if (data[i].name == "Mother"){
      d = 900;
      d = d+data[i].game;
	  des.push_back(d);
    ori.push_back(d);
    }
  }

	quick(des, 0, des.size()-1);
  
  for (int m=0; m < cont; m++){
    for (i=0; i < cont; i++){
      
      if (des[m]==ori[i]){
        cout<<data[i].name<<" "<<data[i].game<<data[i].champ<<endl;

        ofstream myfile("success.txt");
        if (myfile.is_open()){
        myfile<<data[i].name<<" ";
        myfile<<data[i].game<<" ";
        myfile<<data[i].champ<<endl;
        
        myfile.close();
        }
	  }
    }
  
  }  
	return 0;
}