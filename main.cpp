//Probar el xor con string
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;


void imprimir_string(string v, string nombre_v)
{
    cout << endl;
    cout << nombre_v << ": " << v << endl;
}

void imprimir_vector(vector<int> v, string nombre_v)
{
    cout << endl;
    cout << nombre_v << ": ";
    for(int i=0;i<v.size();i++)
    {
      cout << v[i];
    }
    cout << endl;
}

string pasar_binario(int v)
{
  string binario;

  int divisor = 2;
  int dividendo = 0;
  int resto = 0;

  dividendo = v;
  while(dividendo >= divisor)
  {
      resto = dividendo % 2;
      if(resto == 1)
      {
          binario = "1" + binario;
      }
      else
      {
          binario = "0" + binario;
      }
      dividendo = dividendo / divisor;
  }
  if(dividendo == 1)
  {
    binario = "1" + binario;
  }
  else
  {
      binario = "0" + binario;
  }
  if(binario.length() < 8)
  {
    while(binario.length() < 8)
    {
      binario = "0" +binario;
    }
    //cout << "En sistema binario " << v[0] << " se escribe " << binario  << endl;
  }

  cout << "En sistema binario " << v << " se escribe " << binario  << endl;
  return binario;
}

vector<int> operacion_xor(string binario_,string clave_)
{
    cout << "Xor entre mensaje original y clave:" << endl;
    cout << "[O:Mensaje original,C: Clave, R: Resultado en binario,RD: Resultado en decimal]" << endl;
    imprimir_string(binario_, "0");
    imprimir_string(clave_,"C");
    vector<int> auxiliar;
    auxiliar.resize(binario_.length());
    for(int i=0;i<binario_.length();i++)
    {
      auxiliar[i] = (((int)binario_[i]) ^ ((int)clave_[i]));
    }

    return auxiliar;
}

int pasar_decimal(vector<int> v)
{
  int auxiliar = 0;
  int i=0;
  int j=7;
  while(i<v.size() && j>=0)
  {
      auxiliar += v[i] * pow(2,j);
      i++;
      j--;
  }
  return auxiliar;
}

void cifrar(vector<int> v, string nombre_v)
{
  cout << nombre_v << ": ";
  for(int i=0;i<v.size();i++)
  {
    cout << (char)v[i];
  }
  cout << endl;
}

string menu_principal(void)
{
  string auxiliar = "";
  cout << "--------------------Practica 1---------------------" << endl;
  cout << "----------------CIFRADO DE VERNAM------------------" << endl;
  cout << "Introduzca el mensaje:";
  cin >> auxiliar;
  return auxiliar;
}

void comprobar_clave(string c, int tam_mensaje)
{
    if(c.length() != tam_mensaje)
    {
      cerr << "La clave no es correcta" << endl;
      exit(-1);
    }
}

int main()
{
  //Declaración de variables
  string mensaje_original = "";
  vector<int> mensaje_decimal;
  string binario = "";
  string clave;
  vector<int> cifrado_decimal;

  string opcion = "n";
  string respuesta = "s";

  while(respuesta == "s" || respuesta == "S")
  {
    system("clear");
    //Vaciamos vectores
    mensaje_original = "";
    mensaje_decimal.clear();
    binario = "";
    clave = "";
    cifrado_decimal.clear();

    mensaje_original = menu_principal();

    mensaje_decimal.resize(mensaje_original.length());
    cout << "----------------------" << endl;
    cout << endl;
    cout << "Mensaje introducido: " << mensaje_original << endl;

    //Pasamos a decimal cada caracter del string mensaje_original
    for(int i=0;i<mensaje_original.length();i++)
    {
      cout << "Caracter[" << i << "]:" << mensaje_original[i] << " || Decimal->" << int(mensaje_original[i]) << endl;
      mensaje_decimal[i] = int(mensaje_original[i]);
    }

    cout << endl;
    cout << "----------------------" << endl;
    //Genero el número binario
    cout << "Pasamos a binario cada decimal:" << endl;
    for(int i=0;i<mensaje_decimal.size();i++)
    {
      binario = binario + pasar_binario(mensaje_decimal[i]);
    }

    imprimir_string(binario, "Binario");
    cout << "----------------------" << endl;

    //El usuario introduce clave por teclado en formato de 1 y 0
    cout << "Introduzca clave: ";
    cin >> clave;

    comprobar_clave(clave,mensaje_original.length()*8);

    //clave = "0000111100100001";
    //comprobar_clave(clave);
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
    int i=0;
    int j=0;
    int x=0;
    int limite = 8;
    vector<int> auxiliar;
    auxiliar.resize(8);
    while(i<cifrado_binario.size())
    {
      while(j<limite)
      {
        auxiliar[j] = cifrado_binario[i];
        i++;
        j++;
      }
      //cout << "Imprimiendo auxiliar:" << endl;
      /*for(int i=0;i<auxiliar.size();i++)
      {
        cout << auxiliar[i];
      }*/
      cifrado_decimal[x] = pasar_decimal(auxiliar);
      cout << cifrado_decimal[x];
      if(x+1 < cifrado_binario.size()/8)
      {
        cout << ",";
      }
      //cout << "Imprimiendo decimal ->" << cifrado_decimal[x] << endl;

      x++;
      j = 0;
    }
    cout << "]" << endl;
    cout << "----------------------" << endl;

    cifrar(cifrado_decimal, "Mensaje cifrado");
    cout << "¿Desea cifrar un nuevo mensaje?[s|n]: ";
    cin >> respuesta;
  }

  return 0;
}
