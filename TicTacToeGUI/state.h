#ifndef STATE_H
#define STATE_H

#include <cstdlib>
// #include <ctime>
#include <iostream>
#include <vector>
// #include <string>

/* Definição do Problema: Jogo da Velha
 * 0 1 2
 * _|_|_ 0
 * _|_|_ 1
 *  | |  2
 */
class State
{
public:
    State();
    //Constrói um estado com tabuleiro vazio
    State( char tableGiven[3][3] );
    //Constrói um estado com tabuleiro definido
    int play( char player, int Xposition, int Yposition );
    //Retornos: -1 = movimento inválido. 0 = sucesso.
    char endGame( void );
    //Retornos: 'X', 'O' em caso de vitória. 'V' em caso de velha. ' ' se o jogo não acabou
    char getPosition( int Xposition, int Yposition );
    //Recebe o comando em x,y e retorna a posição correspondente do tabuleiro
    void printState( void );
private:

    char table[3][3];

};

#endif //STATE_H
