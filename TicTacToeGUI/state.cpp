#include "state.h"

State::State()
{
    for( int i = 0; i < 3; i++ )
    {
        for( int j = 0; j < 3; j++)
        {
            State::table[i][j] = ' ';
        }
    }
}

State::State( char tableGiven[3][3] )
{
    for( int i = 0; i < 3; i++ )
    {
        for( int j = 0; j < 3; j++)
        {
            State::table[i][j] = tableGiven[i][j];
        }
    }
}

int State::play( char player, int Xposition, int Yposition )
{
    if( State::table[Yposition][Xposition] == ' ' )
    {
        State::table[Yposition][Xposition] = player;
        return 0;
    } else
        return -1;
}

char State::getPosition( int Xposition, int Yposition )
{
    return State::table[Yposition][Xposition];
}

char State::endGame( void )
{
    char aux = State::getPosition(0,0);
    if( aux != ' ' )
    {
        if( (State::getPosition(1,0) == aux && State::getPosition(2,0) == aux) ||
            (State::getPosition(0,1) == aux && State::getPosition(0,2) == aux) ||
            (State::getPosition(1,1) == aux && State::getPosition(2,2) == aux) )
            return aux;
    }
    aux = State::getPosition(2,2);
    if( aux != ' ' )
    {
        if( (State::getPosition(2,0) == aux && State::getPosition(2,1) == aux) ||
            (State::getPosition(0,2) == aux && State::getPosition(1,2) == aux) )
            return aux;
    }
    aux = State::getPosition(1,1);
    if( aux != ' ' )
    {
        if( (State::getPosition(1,0) == aux && State::getPosition(1,2) == aux) ||
            (State::getPosition(0,1) == aux && State::getPosition(2,1) == aux) ||
            (State::getPosition(0,2) == aux && State::getPosition(2,0) == aux) )
            return aux;
    }
    //resta analisar se está cheio
    for( int i = 0; i < 3; i++)
    {
        for( int j = 0; j <3; j++)
        {
            if( State::table[i][j] == ' ' )
                return ' ';
        }
    }
    //deu velha
    return 'V';
}

void State::printState( void )
{
    std::cout << std::endl;
    for( int i = 0; i < 3; i ++ )
    {
        for( int j = 0; j < 3; j ++)
        {
            if( j != 2 )
                std::cout << State::table[i][j] << '|';
            else
                std::cout << State::table[i][j];
        }
        std::cout << std::endl;
    }
}
