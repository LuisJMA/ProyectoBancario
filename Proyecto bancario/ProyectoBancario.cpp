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
	string Estado;
};

struct Cliente {
    string codigo_cuenta;
    string nombre_cliente;
    string cedula;
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
        getline(stream, usuario.Estado, delimitador);
        
		
		
		cout<<"================================"<<endl;      
	    cout<<"CI: "<<usuario.CI<<endl;
        cout<<"Cliente: "<<usuario.Cliente<<endl;
        cout<<"Numero de Cuenta: "<<usuario.NumbCuenta<<endl;
        cout<<"Tipo de cuenta: "<<usuario.TipCuenta<<endl;
        cout<<"Suspendido: "<<usuario.Estado<<endl;
        
        	
	}
    file.close();

}

void ConsultNumbCuenta()
{
		int contador;
    	char delimitador = ',';
    	USUARIO usuario;
		string linea;
  		ifstream archivo(Archivo, ios::in);
    	string num_buscar;
    	string verdadero= "true" ;
			
		cout<<"Ingrese Num de cuenta a buscar: "<<endl;
		cin>>num_buscar;
		
        
		
		bool existe = false;
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, usuario.CI, delimitador);
	        getline(stream,usuario.Cliente, delimitador);
	        getline(stream, usuario.NumbCuenta, delimitador);
	        getline(stream, usuario.TipCuenta, delimitador);
	        getline(stream, usuario.Estado, delimitador);
	       

            if(num_buscar.compare(usuario.NumbCuenta) == 0){
                existe = true;
            cout<<"================================"<<endl;      
	    	cout<<"Nombre: "<<usuario.Cliente<<endl;
	    	cout<<"Numero Cuenta: "<<usuario.NumbCuenta<<endl;
	    	cout<<"CI del Cliente: "<<usuario.CI<<endl;
	    	
	    	if(usuario.Estado == verdadero)
			{
				cout<<"Estado de la cuenta: "<<"SUSPENDIDA"<<endl;
			}
        	
            else 
			{
				cout<<"Estado de la cuenta: "<<"ACTIVA"<<endl;
			}
       	}
       	else{
       		contador=1;
       		
		   }
		   
       	
       	
		   }
		if(contador==1 && existe== false )
		{
			cout<<"CLIENTE NO REGISTRADO "<<endl;
			
		}   
		archivo.close();  
		   }


void ConsultCI()
{
		int contador=1;
    	char delimitador = ',';
    	USUARIO usuario;
		string linea;
  		ifstream archivo(Archivo);
    	string numCI_buscar;
    	string verdadero= "true" ;
			
		cout<<"Ingrese Cedula a buscar: "<<endl;
		cin>>numCI_buscar;
		
		bool existe= false; 
		
        
		
		
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, usuario.CI, delimitador);
	        getline(stream, usuario.Cliente, delimitador);
	        getline(stream, usuario.NumbCuenta, delimitador);
	        getline(stream, usuario.TipCuenta, delimitador);
	        getline(stream, usuario.Estado, delimitador);
	       

            if(usuario.CI.compare(numCI_buscar) == 0)
			{
             existe= true;   
            cout<<"================================"<<endl;      
	    	cout<<"Nombre: "<<usuario.Cliente<<endl;
	    	cout<<"Numero Cuenta: "<<usuario.NumbCuenta<<endl;
	    	cout<<"CI del Cliente: "<<usuario.CI<<endl;
	    	
	    	if(usuario.Estado == verdadero)
			{
				cout<<"Estado de la cuenta: "<<"SUSPENDIDA"<<endl;
			}
        	
            else 
			{
				cout<<"Estado de la cuenta: "<<"ACTIVA"<<endl;
			}
       		}
       
		   else
		   {
		   	contador=1;
		   }
       
       	
		   }	
		   if(contador==1 && existe== false)
		   {
       		cout<<"CLIENTE NO REGISTRADO"<<endl;
       		
		   }
		   archivo.close();
}


void ConsultName()
{
		char delimitador = ',';
		int contador;
    	USUARIO usuario;
		string linea;
  		ifstream archivo(Archivo, ios::in);
    	string nombre_buscar;
    	string verdadero= "true";

       
        
		
			
		cout<<"Ingrese nombre del Cliente: "<<endl;
		cin.ignore();// esto elimina los espacios en blaco para que se pueda ejecutar bien el getline
		getline(cin,nombre_buscar);// lee el nombre de la pelicula completo con espacios
		
        
		
		bool existe = false;
        getline(archivo,linea);
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, usuario.CI, delimitador);
	        getline(stream, usuario.Cliente, delimitador);
	        getline(stream, usuario.NumbCuenta, delimitador);
	        getline(stream, usuario.TipCuenta, delimitador);
	        getline(stream, usuario.Estado, delimitador);
	        

            if(nombre_buscar.compare(usuario.Cliente) == 0)
			{
             existe = true ;   
            cout<<"================================"<<endl;      
	    	cout<<"Nombre: "<<usuario.Cliente<<endl;
	    	cout<<"Numero Cuenta: "<<usuario.NumbCuenta<<endl;
	    	cout<<"CI del Cliente: "<<usuario.CI<<endl;
	    	
	    	if(usuario.Estado == verdadero)
			{
				cout<<"Estado de la cuenta: "<<"SUSPENDIDA"<<endl;
			}
        	
            else 
			{
				cout<<"Estado de la cuenta: "<<"ACTIVA"<<endl;
			}
       		}
           	 else
				{
				
			
				contador=1;
			
				}
           	 
            
       	}
       	
		if(contador==1 && existe==false)
		 {
		 	cout<<"CLIENTE NO REGISTRADO"<<endl;
		 }   
       	
       	archivo.close();
		   }


void suspendercuentas()
{
		int contador;
    	char delimitador = ',';
    	USUARIO usuario;
		string linea;
  		ifstream archivo(Archivo);
  		ofstream oarchivo("loquesea.csv");
  		
    	string num_buscar;
    	
		int opcion;	
		cout<<"Ingrese Num de cuenta a buscar: "<<endl;
		cin>>num_buscar;
		
		
        
		
		bool existe = false;
        
        while (getline(archivo,linea))
        {
             
            stringstream stream(linea);
            
	        getline(stream, usuario.CI, delimitador);
	        getline(stream,usuario.Cliente, delimitador);
	        getline(stream, usuario.NumbCuenta, delimitador);
	        getline(stream, usuario.TipCuenta, delimitador);
	        getline(stream, usuario.Estado, delimitador);
	       

            if(num_buscar.compare(usuario.NumbCuenta) == 0)
			{
				existe= true;
				cout<<"Que opcion quiere realizar"<<endl;
				cout<<"1. ACTIVAR CUENTA"<<endl;
				cout<<"2. SUSPENDER CUENTA"<<endl;
				cin>>opcion;
				
				switch(opcion)
				{
					case 1:
						if(usuario.Estado == "true" )
						{
							
							usuario.Estado= "false" ;
							cout << "CUENTA ACTIVADA"<<endl;	
						}
						else
						{
							cout<<"La cuenta ya esta activa"<<endl;
						}
						break;
					
					case 2:
                    if (usuario.Estado == "false")
                    {
                        usuario.Estado = "true";
                        cout << "CUENTA SUSPENDIDA" << endl;
                    }
                    else 
					{
							cout<<"La cuenta ya esta suspendida"<<endl;
						
                    
					}
               break;
       		}
       		// Guarda los cambios en el archivo temporal
            oarchivo << usuario.CI << delimitador;
            oarchivo << usuario.Cliente << delimitador;
            oarchivo << usuario.NumbCuenta << delimitador;
            oarchivo << usuario.TipCuenta << delimitador;
            oarchivo << usuario.Estado << "\n";
       	
		   
       		}
       		
       	else
        {
            contador = 1;

            // Guarda la línea original en el archivo temporal
            oarchivo << linea << "\n";
        }
       	
		   }
		if(contador==1 && existe== false )
		{
			cout<<"CLIENTE NO REGISTRADO "<<endl;
			
		}   
		archivo.close(); 
		oarchivo.close();
		remove(Archivo);
    	rename("loquesea.csv", Archivo);
}


int main()
{
	int p, k, y;
	
	while(true)
	{
	
		
		
		
			cout << "Menu" << endl;
			cout << "(1) MOstrar datos del cliente" << endl;
			cout << "(2) BUscar cliente "<<endl;
			cout << "(3) SUSPENDER/ACTIVAR CUENTAS"<<endl;
			
		cin>>p;
		switch(p)
		{
			case 1:
				LeerArchivo();
				break;
			
			
			case 2:
				cout<<"1. Buscar por numero de cuenta"<<endl;cout<<"2. Buscar por cedula"<<endl; cout<<"3. Buscar por nombre"<<endl; cin>>k;
				
				if(k==1)
				{
					ConsultNumbCuenta();
					break;
				}
				else if(k==2)
				{
					ConsultCI();
					
					break;
				}
				else if(k==3)
				{
					ConsultName();
					break;
				}
				else
				{
					cout<<"Opcion erronea"<<endl;
					break;
					
				}	
				break;
				
				
				case 3:
					suspendercuentas();
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
			return 0;
		}
		else
		{
			cout<<""<<endl;
			cout<<"================================"<<endl;   
			cout<<"Opcion erronea, se cerrara el programa por defecto"<<endl;
			exit(0);
			break;	
		} 
	}
	
	return 0;
}
