
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
  cout << "Mensaje cifrado: " << endl;
  cout << nombre_v << ": ";
  for(int i=0;i<v.size();i++)
  {
    //cout << "Entro" << endl;
    cout << (char)(v[i]);
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