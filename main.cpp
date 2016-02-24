#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>
#include "funciones.cpp"


using namespace std;


int main()
{
  //Declaración de variables
  string mensaje_original = ""; //String que almacena el mensaje original que se cifrará
  vector<int> mensaje_decimal; //Vector de enteros que contendrá los decimales asociados a cada caracter del String mensaje_original
  string binario = ""; //String que contendrá el binario resultante de convertir cada decimal del vector mensaje_decimal a binario de 8 bits
  string clave; //String en el que se almacenará la clave introducida por el usuario por teclado
  vector<int> cifrado_decimal; //String que almacenará los decimales asociados al binario resultante

  string respuesta = "s"; //Variable para almacenar la respuesta del usuario, indicando si quiere realizar otro cifrado o no.

  while(respuesta == "s" || respuesta == "S")
  {
    system("clear");
    
    //Vaciamos vectores
    mensaje_original = "";
    mensaje_decimal.clear();
    binario = "";
    clave = "";
    cifrado_decimal.clear();

    mensaje_original = menu_principal(); //Mostramos mensaje de bienvenida al usuario
    mensaje_decimal.resize(mensaje_original.length());
  
    cout << "----------------------" << endl;
    cout << endl;
    cout << "Mensaje introducido: " << mensaje_original << endl;

    //Pasamos a decimal cada caracter del string mensaje_original
    for(int i=0;i<mensaje_original.length();i++)
    {
      cout << "Caracter[" << i << "]:" << mensaje_original[i] << " || Decimal->" << int(mensaje_original[i]) << endl;
      mensaje_decimal[i] = int(mensaje_original[i]); //Vector de enteros mensaje_decimal
    }

    cout << endl;
    cout << "----------------------" << endl;

    //Genero el número binario llamando a la función pasar_binario por cada decimal del vector mensaje_decimal
    cout << "Pasamos a binario cada decimal:" << endl;
    for(int i=0;i<mensaje_decimal.size();i++)
    {
      binario = binario + pasar_binario(mensaje_decimal[i]);
    }

    //Llamamos a la función imprimir_string para mostrar por pantalla al usuario el binario resultante
    imprimir_string(binario, "Binario");
    cout << "----------------------" << endl;

    //El usuario introduce clave por teclado en formato de 1 y 0
    cout << "Introduzca clave: ";
    cin >> clave;

    //Comprobamos que la longitud de la clave sea la correcta
    comprobar_clave(clave,mensaje_original.length()*8);

    //clave = "0000111100100001";

    cout << endl;
    cout << "----------------------" << endl;

    //Generamos cifrado en 0 y 1, realizando una operación xor entre el mensaje original en binario y la clave introducida por el usuario en binario
    vector<int> cifrado_binario = operacion_xor(binario,clave);

    //Imprimimos el vector de enteros "cifrado_binario"
    imprimir_vector(cifrado_binario,"R");

    cout << endl;

    //Generamos los decimales asociados al cifrado en binario resultante de la operación xor.
    cifrado_decimal.resize(mensaje_original.length());
    cout << "RD: [";
    int contador1=0;
    int contador2=0;
    int contador3=0;
    int maximo = 8;
    
    vector<int> fragmento;
    fragmento.resize(8);
    
    //Con el índice contador1 recorro cifrado_binario desde 0 hasta su tamaño
    while(contador1<cifrado_binario.size())
    {
      //Con el índice contador2 recorro desde 0 a 8 cifrado_binario separando el binario en grupos de 8 y almacenándolo an auxiliar
      while(contador2<maximo)
      {
        fragmento[contador2] = cifrado_binario[contador1];
        contador1++;
        contador2++;
      }
      
      cifrado_decimal[contador3] = pasar_decimal(fragmento); //Paso a decimal un conjunto de 8 bits y devuelvo un decimal que almaceno en el vector de enteros cifrado_decimal
      cout << cifrado_decimal[contador3];
      if(contador3+1 < cifrado_binario.size()/8)
      {
        cout << ",";
      }

      contador3++; //Contador para mostrar por pantalla "," al lado de los decimales.
      contador2 = 0; //Reinicio j para volver a almacenar en auxiliar desde la posición 0 correctamente.
    }
    cout << "]" << endl;
    cout << "----------------------" << endl;

    //Llamo a la función cifrar y se le pasa el vector de enteros resultante de la codificación y se imprime el mensaje codificado
    cifrar(cifrado_decimal, "Mensaje cifrado");
    cout << "¿Desea cifrar un nuevo mensaje?[s|n]: ";
    cin >> respuesta;
  }

  return 0;
}
