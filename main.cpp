#include "iostream"
#include "string"
#include <cmath>
using namespace std;

string letters= "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string base1, base2, value;
bool Bbase1, Bbase2;

string convertFrom10(int value, string base) {
  string res="";
  while (value != "") {
    int valor = stoi(value, nullptr, 10);
    int Base = stoi(base, nullptr, 10);
    int residuo = valor % Base;
    res = letters[residuo]+ res;
    valor = round(valor / Base);
  }
  return res;
}

int convertTo10(string value, string base) {
  return (stoi(value, nullptr, 10),stoi(base, nullptr, 10));
}
string convert(string value, string base1, string base2) {
  return convertFrom10(convertTo10(value, base1), base2);
}
bool verifValue(string value, string base) {
  int numBase = stoi(base, nullptr, 10);
  if (numBase <= 10) {
    try {
      int numValue = stoi(value, nullptr, 10);;
    } catch (error) {
      console.log(error);
      return false;
    }
  } else {
    for (int i = 0; i < value.length; i++) {
      let subS = value.substring(i, i + 1);
      if (letters.indexOf(subS) >= numBase) {
        return false;
      }
    }
  }
  return true;
}

bool verifBase(int base) {
  return int (base) <= 1 || int (base) >= 37;
}

int main() {
  base1="", base2="", value="a";
  Bbase1=true, Bbase2=true;
  
  while(value!=""){
    Bbase1=true;
    Bbase2=true;
    cout << "ingrese su numero"<< endl;
    cin>> value;

    while(Bbase1){
      cout<<"Ingrese la base del valor"<<endl;
      cin>>base1;
      if(base1!="" && (verifBase(base1))!){
        Bbase1=false;
      }
    }
    while(Bbase2){
      cout<<"Ingrese la base del objetivo"<<endl;
      cin>>base2;
      if(base2!="" && (verifBase(base2))!){
        Bbase2=false;
      }
    }
    cout<<"Conversion from base " + base1 + " to base " + base2 + " of " + value + " is --> " + convert(value, base1, base2) <<endl;
  }
}

