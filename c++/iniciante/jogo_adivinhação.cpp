#include <iostream>
#include <random>
#include <ctime>
using namespace std;

int gen_random(){
  srand((unsigned) time(0));
  int randomNumber;
  for (int index = 0; index < 10; index++) {
    randomNumber = (rand() % 100) + 1;
}
return randomNumber;
}

bool isNumeric(string str) {
   for (int i = 0; i < str.length(); i++)
      if (isdigit(str[i]) == false)
         return false;
      return true;
}

int main (){

std::cout << "**************************************" << std::endl;
std::cout << "*Bem vindo ao jogo  da adivinhacao!!!*" << std::endl;
std::cout << "**************************************" << std::endl;

bool jogando = true;
int rodada = 1;
const int NUMERO_SECRETO = gen_random();


while (jogando == true){

    std::cout << rodada << " rodada" << std::endl;
    string chute_str;

    if (rodada < 2){
        std::cout << "Digite seu chute: ";
        std::cin >> chute_str;  
    }
    else{
        std::cout << "Digite seu próximo chute: ";
        std::cin >> chute_str;
    }

    bool check_input = isNumeric(chute_str);

    if (check_input == true){

        rodada++;
        int chute = stoi(chute_str);
        int resto = abs(chute - NUMERO_SECRETO);
        bool acertou = chute == NUMERO_SECRETO;
        bool menor_que = chute < NUMERO_SECRETO;
        bool maior_que = chute > NUMERO_SECRETO;


        if(menor_que)
        {std::cout << "O seu chute: " << chute << " foi menor do que o número secreto" << std::endl;}       

        else if(maior_que)
        {std::cout << "O seu chute: " << chute << " foi maior do que o número secreto" << std::endl;}

        else if (acertou) {std::cout << "Parabéns! você acertou !!! " << std::endl; jogando = false;}

    }

    else{
        std::cout << "Chute um número !" << std::endl;
    }

}
}
