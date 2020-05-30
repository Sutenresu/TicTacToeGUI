#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "node.h"
#include "state.h"
#include <vector>
#include <iostream>

#define INFINITY_P 999
#define INFINITY_N -999
#define CPU 'O'
#define EASY 1
#define HARD 2
#define GAME_MODE HARD
//#define TESTING_GENERATING
//#define DEBUG

int idCurrentNode = 0;
std::vector<int> storedAction(2,0);
std::vector<Node> generateNodes( Node currentNode, bool maxCalling );
int max( Node currentNode, int alpha, int beta );
int min( Node currentNode, int alpha, int beta );

State empty,currentState;
Node game;
int posicaoX = 0, posicaoY = 0;

int max( Node currentNode, int alpha, int beta )
{
    #ifdef DEBUG
        std::cout << "Iniciando chamada de max para o nó: " << currentNode.getIdNode() << std::endl;
    #endif
    //Verifica se é terminal
    char utility = currentNode.getNodeState().endGame();

    if( utility != ' ' )
    {
        #ifdef DEBUG
            std::cout << "É utilidade!" << std::endl;
        #endif
        if( utility == CPU )
        {
            if( GAME_MODE == EASY )
                return 10;
            else
                return 10 - currentNode.getDepth();
        }
        if( utility == 'V')
        {
            if( GAME_MODE == EASY )
                return 0;
            else
                return 0 - currentNode.getDepth();
        }
        if( GAME_MODE == EASY )
            return -10;
        else
            return -10 - currentNode.getDepth();
    }
    #ifdef DEBUG
        std::cout << "Não é utilidade!" << std::endl;
        std::getchar();
    #endif
    int result = INFINITY_N;

    std::vector<Node> childNodes;

    childNodes = generateNodes( currentNode, true );

    //Varrer os filhos
    int minResult;
    for( int i = 0; i < (int) childNodes.size() ; i++ )
    {
        #ifdef DEBUG
            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
            std::cout << "alpha = " << alpha << std::endl;
            std::cout << "beta = " << beta << std::endl;
            std::cout << "result = " << result << std::endl;
            std::cout << "Iniciando chamada de min para o nó: " << childNodes[i].getIdNode() << std::endl;
            childNodes[i].getNodeState().printState();
            std::getchar();
        #endif
        minResult = min( childNodes[i], alpha, beta );
        #ifdef DEBUG
            std::cout << "Finalizando chamada de min para o nó: " << childNodes[i].getIdNode() << std::endl;
            childNodes[i].getNodeState().printState();
            std::cout << "minResult = " << minResult << std::endl;
            std::getchar();
        #endif
        if( result < minResult )
        {
            result = minResult;
            // std::cout << "Atualizei o valor" << std::endl;
            // childNodes[i].getNodeState().printState();
            if( childNodes[i].getDepth() == 1 )
            {
                // std::cout << "É da primeira camada" << std::endl;
                storedAction = childNodes[i].getPrevAction();
                // childNodes[i].getNodeState().printState();
            }
        }
        #ifdef DEBUG
            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
            std::cout << "result = " << result << std::endl;
        #endif
        if( result >= beta )
        {
            #ifdef DEBUG
                std::cout << "Abortando busca, beta = " << beta << std::endl;
            #endif
            return result;
        }
        if( result > alpha )
            alpha = result;
        #ifdef DEBUG
            std::cout << "alpha = " << alpha << std::endl;
        #endif
    }

    return result;
}

int min( Node currentNode, int alpha, int beta )
{
    #ifdef DEBUG
        std::cout << "Iniciando chamada de min para o nó: " << currentNode.getIdNode() << std::endl;
    #endif
    //Verifica se é terminal
    char utility = currentNode.getNodeState().endGame();
    if( utility != ' ' )
    {
        #ifdef DEBUG
            std::cout << "É utilidade!" << std::endl;
        #endif
        if( utility == CPU )
        {
            if( GAME_MODE == EASY )
                return 10;
            else
                return 10 - currentNode.getDepth();
        }
        if( utility == 'V')
        {
            if( GAME_MODE == EASY )
                return 0;
            else
                return 0 - currentNode.getDepth();
        }
        if( GAME_MODE == EASY )
            return -10;
        else
            return -10 - currentNode.getDepth();
    }
    #ifdef DEBUG
        std::cout << "Não é utilidade!" << std::endl;
        std::getchar();
    #endif
    int result = INFINITY_P;

    std::vector<Node> childNodes;

    childNodes = generateNodes( currentNode, false );

    //Varrer os filhos
    int maxResult;
    for( int i = 0; i < (int) childNodes.size() ; i++ )
    {
        #ifdef DEBUG
            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
            std::cout << "alpha = " << alpha << std::endl;
            std::cout << "beta = " << beta << std::endl;
            std::cout << "result = " << result << std::endl;
            std::cout << "Iniciando chamada de max para o nó: " << childNodes[i].getIdNode() << std::endl;
            childNodes[i].getNodeState().printState();
            std::getchar();
        #endif
        maxResult = max( childNodes[i], alpha, beta );
        #ifdef DEBUG
            std::cout << "Finalizando chamada de max para o nó: " << childNodes[i].getIdNode() << std::endl;
            childNodes[i].getNodeState().printState();
            std::cout << "maxResult = " << maxResult << std::endl;
            std::getchar();
        #endif
        if( result > maxResult )
        {
            result = maxResult;
        }
        #ifdef DEBUG
            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
            std::cout << "result = " << result << std::endl;
        #endif
        if( result <= alpha )
        {
            #ifdef DEBUG
                std::cout << "Abortando busca, alpha = " << alpha << std::endl;
            #endif
            return result;
        }
        if( result < beta )
            beta = result;
        #ifdef DEBUG
            std::cout << "beta = " << beta << std::endl;
        #endif
    }

    return result;
}

std::vector<Node> generateNodes( Node currentNode, bool maxCalling )
{
    std::vector<Node> childNodes;
    Node nodeToExpand = currentNode;
    Node newNode;
    State nodeState = nodeToExpand.getNodeState();
    std::vector<int> positionVec(2,0);
    char player = CPU;
    if( !maxCalling )
    {
        if( CPU == 'X' )
            player = 'O';
        else
            player = 'X';
    }
    #ifdef TESTING_GENERATING
        std::cout << "Nó a ser expandido" << std::endl;
        currentNode.getNodeState().printState();
    #endif
    //Gerando os filhos
    for( int i = 0; i < 3; i++ )
    {
        for( int j = 0; j < 3; j++ )
        {
            if( nodeState.play( player, i, j ) == 0 )
            {
                positionVec[0] = j;
                positionVec[1] = i;
                newNode.setNodeState( nodeState );
                newNode.setIdParent( nodeToExpand.getIdNode() );
                newNode.setIdNode( ++idCurrentNode );
                newNode.setDepth( nodeToExpand.getDepth() + 1 );
                newNode.setPrevAction( positionVec );

                #ifdef TESTING_GENERATING
                    nodeState.printState();
                    std::cout << "Id do pai: " << newNode.getIdParent() << std::endl;
                    std::cout << "Id do nó: " << newNode.getIdNode() << std::endl;
                    std::cout << "Profundidade: " << newNode.getDepth() << std::endl;
                #endif
                childNodes.push_back( newNode );
            }
            nodeState = nodeToExpand.getNodeState();
        }
    }
    // if(childNodes[0].getDepth() == 1)
    // {
    //     std::cout << "Nós da primeira camada" << std::endl;
    //     for( int i = 0; i <childNodes.size(); i++)
    //         childNodes[i].getNodeState().printState();
    // }
    return childNodes;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainText->setText("Você é o X.\nFaça sua jogada!");
    game.setNodeState(empty);
    game.getNodeState().printState();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::playGame(int buttonX, int buttonY)
{
    currentState = game.getNodeState();
    int resultPlay = -1;
    if( currentState.endGame()== ' ' )
    {
        resultPlay = currentState.play('X', buttonX, buttonY );
        if( resultPlay == 0 )
        {
            game.setNodeState( currentState );
            game.getNodeState().printState();

            if(buttonX == 0 && buttonY == 0) ui->button00->setText("X");
            if(buttonX == 0 && buttonY == 1) ui->button01->setText("X");
            if(buttonX == 0 && buttonY == 2) ui->button02->setText("X");
            if(buttonX == 1 && buttonY == 0) ui->button10->setText("X");
            if(buttonX == 1 && buttonY == 1) ui->button11->setText("X");
            if(buttonX == 1 && buttonY == 2) ui->button12->setText("X");
            if(buttonX == 2 && buttonY == 0) ui->button20->setText("X");
            if(buttonX == 2 && buttonY == 1) ui->button21->setText("X");
            if(buttonX == 2 && buttonY == 2) ui->button22->setText("X");

            ui->mainText->setText("Agora o PC joga...");
            std::cout << "\nresultado: " << max( game, INFINITY_N, INFINITY_P ) << std::endl;
            std::cout << "Ação do PC : Colocar " << CPU << " em X: " << storedAction[1] << " e Y: " << storedAction[0] << std::endl;
            currentState = game.getNodeState();
            currentState.play( 'O', storedAction[1], storedAction[0] );
            game.setNodeState( currentState );
            game.getNodeState().printState();

            if(storedAction[1] == 0 && storedAction[0] == 0) ui->button00->setText("O");
            if(storedAction[1] == 0 && storedAction[0] == 1) ui->button01->setText("O");
            if(storedAction[1] == 0 && storedAction[0] == 2) ui->button02->setText("O");
            if(storedAction[1] == 1 && storedAction[0] == 0) ui->button10->setText("O");
            if(storedAction[1] == 1 && storedAction[0] == 1) ui->button11->setText("O");
            if(storedAction[1] == 1 && storedAction[0] == 2) ui->button12->setText("O");
            if(storedAction[1] == 2 && storedAction[0] == 0) ui->button20->setText("O");
            if(storedAction[1] == 2 && storedAction[0] == 1) ui->button21->setText("O");
            if(storedAction[1] == 2 && storedAction[0] == 2) ui->button22->setText("O");
        }
        ui->mainText->setText("Você é o X.\nFaça sua jogada!");
        if( currentState.endGame() == 'X' )
        {
            ui->mainText->setText("Parabéns, você ganhou! ");
        }
        if( currentState.endGame() == 'O' )
        {
            ui->mainText->setText("Que pena, você perdeu");
        }
        if( currentState.endGame() == 'V' )
        {
            ui->mainText->setText("Empate!\nClique no botão restart para iniciar um novo jogo...");
        }

    } else if( currentState.endGame() == 'X' )
    {
        ui->mainText->setText("Parabéns, você ganhou! ");
    } else if( currentState.endGame() == 'O' )
    {
        ui->mainText->setText("Que pena, você perdeu");
    }
}

void MainWindow::on_button00_clicked()
{
    playGame(0,0);
}

void MainWindow::on_button01_clicked()
{
    playGame(0,1);
}

void MainWindow::on_button02_clicked()
{
    playGame(0,2);
}

void MainWindow::on_button10_clicked()
{
    playGame(1,0);
}

void MainWindow::on_button11_clicked()
{
    playGame(1,1);
}

void MainWindow::on_button12_clicked()
{
    playGame(1,2);
}

void MainWindow::on_button20_clicked()
{
    playGame(2,0);
}

void MainWindow::on_button21_clicked()
{
    playGame(2,1);
}

void MainWindow::on_button22_clicked()
{
    playGame(2,2);
}

void MainWindow::on_buttonRetry_clicked()
{
    ui->mainText->setText("Você é o X.\nFaça sua jogada!");
    game.setNodeState(empty);
    ui->button00->setText(" ");
    ui->button01->setText(" ");
    ui->button02->setText(" ");
    ui->button10->setText(" ");
    ui->button11->setText(" ");
    ui->button12->setText(" ");
    ui->button20->setText(" ");
    ui->button21->setText(" ");
    ui->button22->setText(" ");

    game.getNodeState().printState();
}
