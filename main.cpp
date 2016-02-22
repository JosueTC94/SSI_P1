//Probar el xor con string

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

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

  cout << endl;
  return binario;
}

vector<int> operacion_xor(string binario_,string clave_)
{
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

void cifrar(vector<int> v)
{
  for(int i=0;i<v.size();i++)
  {
    cout << (char)v[i];
  }
  cout << endl;
}
int main()
{
  string mensaje_original = "";

  vector<int> mensaje_decimal;
  string binario = "";
  string clave;

  cout << "--------------------Practica 1---------------------" << endl;
  cout << "Cifrado de Vernam" << endl;
  cout << "Introduzca la palabra:";
  cin >> mensaje_original;
  mensaje_decimal.resize(mensaje_original.length());
  //binario.resize(mensaje_original.length()*8);

  cout << endl;
  cout << "Mensaje introducido->" << mensaje_original << endl;
  for(int i=0;i<mensaje_original.length();i++)
  {
    cout << "Caracter[" << i << "]:" << mensaje_original[i] << " || Decimal->" << int(mensaje_original[i]) << endl;
    mensaje_decimal[i] = int(mensaje_original[i]);
  }
  cout << endl;

  for(int i=0;i<mensaje_decimal.size();i++)
  {
    cout << "Caracter[" << i << "]:" << mensaje_decimal[i] << ", ";
  }
  cout << endl;
  for(int i=0;i<mensaje_decimal.size();i++)
  {
    binario = binario + pasar_binario(mensaje_decimal[i]);
  }

  cout << "Binario->" << binario << endl;

  /*cout << "Clave:";
  cin >> clave;
  cout << endl;
*/
  clave = "001111000001100001110011";
  //comprobar_clave(clave);

  vector<int> cifrado_binario = operacion_xor(binario,clave);

  //Imprimimos el string cifrado_binario
  cout << "Cifrado_binario:" << endl;
  for(int i=0;i<cifrado_binario.size();i++)
  {
    cout << cifrado_binario[i];
  }

  cout << endl;
  vector<int> cifrado_decimal;
  cifrado_decimal.resize(mensaje_original.length());

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
    cout << "Imprimiendo auxiliar:" << endl;
    for(int i=0;i<auxiliar.size();i++)
    {
      cout << auxiliar[i];
    }
    cout << endl;

    cifrado_decimal[x] = pasar_decimal(auxiliar);
    cout << "Imprimiendo decimal ->" << cifrado_decimal[x] << endl;

    x++;
    j = 0;
  }

  cout << "Cifrado decimal:" << endl;
  for(int i=0;i<cifrado_decimal.size();i++)
  {
    cout << cifrado_decimal[i] << ",";
  }
  cout << endl;

  cout << "Mensaje cifrado: " << endl;
  cifrar(cifrado_decimal);

  return 0;
}
