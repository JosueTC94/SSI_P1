#include <iostream>
#include <vector>

using namespace std;

vector<int> pasar_binario(int num)
{
  int i,j,num2,res;
  vector<int> x;

  x.resize(8);

  num2 = num;
  for(i = 1 ; i <= num ; i++){ // Determina (i) las divisiones que se harán
   num2 = num2 / 2;
      if(num2 == 1)
         break;
  }
  for(j = 1 ; j <= i+1; j++){ // Realiza las operaciones para la conversión
      res = num % 2;
      if(res == 1)
         x[j] = 1;
      else if(res == 0)
              x[j] = 0;
      num = num / 2;
  }

  int w = i+2;
  //cout << "W->" << w << endl;

  if(i+1 < x.size())
  {
    while(w <= x.size())
    {
        //cout << "w->" << w << endl;
        //cout << "x[" << w << "]:" << x[w] << endl;
        x[w] = 0;
        w++;
    }
  }

  vector<int> x_;
  x_.resize(x.size());

  //Reordeno vector
  int p = 0;
  for(int n = 8;n>0;n--)
  {
    //cout << "Inserto en x_ en la posicion " << p << " :" << x[n] << endl;
    x_[p] = x[n];
    //cout << "x_[" << p << "]:" << x_[p] << endl;
    p++;
  }
  /*cout << endl;
  cout << "Tamanio x: " << x.size() << endl;
  cout << "Ordenado:" << endl;
  for(int i=0;i<8;i++)
  {
    cout << x_[i];
  }*/
  return x_;
  }
}
