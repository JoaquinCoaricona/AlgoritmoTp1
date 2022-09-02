#include <iostream>
#include <fstream>



using namespace std;




int main()
   {
           
      

       cout<<endl;
       cout<<endl;
       cout<<"************************************************************************"<<endl;
       cout<<endl;
       cout<<endl;
     
      const int clientes = 8;
      const int productos = 5;
      const int parametros = 2;

    
      
      int contador_pedidos[productos]={};

     
      float vector[clientes][productos][parametros+1]={0};

    

      fstream datos;
      datos.open("Datos.txt");
   
    
      int dato = 0;
      int codigo_prod = 0;
      float peso = 0;
      float km = 0;



    

      while(datos>>dato){

                  
                  datos>>codigo_prod;
                  datos>>peso;
                  vector[dato][codigo_prod][0]=vector[dato][codigo_prod][0]+peso;
                  datos>>km;
                  vector[dato][codigo_prod][1]=vector[dato][codigo_prod][1]+km;
                  
                  //cout<<vector[dato][codigo_prod][1]<<endl; //al ejecutar este codigo dan bien las primeras lectuas pero despues comienza a fallar
                  //cout<<km<<endl;
                  contador_pedidos[codigo_prod]+=1;
                  
                  }


      datos.close();

      fstream nombres;
      
      nombres.open("Nombres.txt");

      string vec_nombres[8];
      string vec_productos[5];

      for(int i = 0; i<8;i++){
            nombres>>vec_nombres[i];
      }

            for(int i = 0; i<5;i++){
            nombres>>vec_productos[i];
      }



      nombres.close();

      int clientes_contador[8]={0};

      cout<<"Listado por clientes, de los tipos de productos que superen los 13000 Kg acumulados:"<<endl;
      cout<<endl;

      for (int i = 0;i<clientes;i++){
            cout<<vec_nombres[i]<<": ";
         for (int j = 0;j<productos;j++){
            if(vector[i][j][0]>13000){
                /*  
                if(j==productos-1){
                  cout<<vec_productos[j]<<".";
                }  else{
                cout<<vec_productos[j];     
                cout<<", ";
                clientes_contador[i]=clientes_contador[i]+1;  
               }
               */

               cout<<vec_productos[j];     
                cout<<", ";
                clientes_contador[i]=clientes_contador[i]+1;  
               }
               
            }
            cout<<endl;
      }

      int clientalnumero;
      int mayorcomprador=0;

      for( int i=0;i<clientes;i++){
         if(mayorcomprador<clientes_contador[i]){
               mayorcomprador=clientes_contador[i];
               clientalnumero=i;
         }
       

         
      }

      int vector_auxiliar_clientes[productos]={};
            
      
        for(int i=0;i<productos;i++){
      vector[clientalnumero][i][3]=i;
     
      }
      
      
      
       
      int aux=0;
      int aux2=0;
      for (int i =0;i<productos;i++){
            for (int j=0;j<productos;j++){
                  if(vector[clientalnumero][j][1]>vector[clientalnumero][j+1][1]){
                        aux=vector[clientalnumero][j][1];
                        vector[clientalnumero][j][1]=vector[clientalnumero][j+1][1];
                        vector[clientalnumero][j+1][1]=aux;
                        
                        aux2=vector[clientalnumero][j][3];
                      
                        vector[clientalnumero][j][3]=vector[clientalnumero][j+1][3];
                        vector[clientalnumero][j+1][3]=aux2;
                        
                  }
            }
      }
      
      cout<<endl;
      cout<<endl;
     
      
      for(int i=0;i<productos;i++){
            vector_auxiliar_clientes[i]=vector[clientalnumero][i][3];
            
      }
      
       for (int i =0;i<productos;i++){
            cout<<vec_productos[vector_auxiliar_clientes[i]]<<": "<<vector[clientalnumero][i][1]<<endl;
       }
      
      cout<<endl;
      cout<<endl;   
      cout<<"Cantidad de entregas para el tipo de producto ";
     cout<<vec_productos[vector_auxiliar_clientes[productos-1]]<<": "<<contador_pedidos[vector_auxiliar_clientes[productos-1]]<<endl;
      
  
     cout<<endl;
       cout<<endl;
       cout<<"************************************************************************"<<endl;
       cout<<endl;
       cout<<endl;
   
   
   
}