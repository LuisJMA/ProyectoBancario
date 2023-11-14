#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#define Archivo "clients.csv"
using namespace std;

struct USUARIO
{
	string CI;
	string Cliente;
	string NumbCuenta;
	string TipCuenta;
	string Suspend;
};

void LeerArchivo()
{
	ifstream file(Archivo);
    string linea;
    char delimitador = ','  ; 
	USUARIO usuario;
    getline(file,linea);
    while (getline(file,linea))
    {
	    
        stringstream stream(linea);
        getline(stream, usuario.CI, delimitador);
        getline(stream, usuario.Cliente, delimitador);
        getline(stream, usuario.NumbCuenta, delimitador);
        getline(stream, usuario.TipCuenta, delimitador);
        getline(stream, usuario.Suspend, delimitador);
        
		
		
		cout<<"================================"<<endl;      
	    cout<<"CI: "<<usuario.CI<<endl;
        cout<<"Cliente: "<<usuario.Cliente<<endl;
        cout<<"Numero de Cuenta: "<<usuario.NumbCuenta<<endl;
        cout<<"Tipo de cuenta: "<<usuario.TipCuenta<<endl;
        cout<<"Suspendido: "<<usuario.Suspend<<endl;
        
        	
	}
    file.close();

}

int main()
{
	int y=1;
	while(y==1)
	{
	
		int p;
		
		
			cout << "Menu" << endl;
			cout << "(1) MOstrar datos del cliente" << endl;
			
		cin>>p;
		switch(p)
		{
			case 1:
				LeerArchivo();
				break;
			case 2:
				
				break;
			
			case 3:
				break;
		}
		
		cout<<""<<endl;
		cout<<"================================"<<endl;   
		cout<<"quieres seguir en el programa? "<<endl;cout<<"(1)Si "<<endl;cout<<"(2)No "<<endl;cin>>y;
		if(y==1)
		{
			cout<<""<<endl;
			cout<<"Genial... Sigamos XD"<<endl;
			cout<<"================================"<<endl;   
			
		}
		else if(y==2)
		{
			cout<<""<<endl;
			cout<<"================================"<<endl;   
			cout<<"Nos vemos "<<endl;
			y=2;
		}
		else
		{
			cout<<""<<endl;
			cout<<"================================"<<endl;   
			cout<<"Opcion erronea, se cerrara el programa por defecto"<<endl;
			y=2;	
		} 
	}
	
	return 0;
}
