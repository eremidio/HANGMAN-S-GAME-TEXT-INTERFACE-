 //Vamos escrever um programa que inicializa strings em C++ com caractéres repetidos

/*Cabeçalho*/
#include<iostream>
#include<string>
using namespace std;


int main(){
//Variáveis
string palpite, nome;
size_t pos;
//Procedimentos
//Entrando com dados
cout<<"Digite uma palavra: ";
cin>>nome;

//Inicializando a string codificada
string nome_secreto(nome.length(), '*');
cout<<"Palavra codificada: "<<nome_secreto<<".\n";

do{
cout<<"Digite uma letra que está na palavra: ";
cin>>palpite;
pos=nome.find(palpite);
nome_secreto.replace(pos, palpite.length(), palpite);

//Substituindo multílas ocorrências de uma mesma letra
while(string::npos>(pos=nome.find(palpite, pos))){ 
nome_secreto.replace(pos, palpite.length(), palpite);
++pos;
                                                  };
cout<< nome_secreto<<"\n";
  }while(nome_secreto!=nome);
cout<<"Você decodificou a palavra com sucesso!\n";
return 0;

}
