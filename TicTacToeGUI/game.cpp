//#include "node.h"
//#include "state.h"
//#include <vector>
//#include <iostream>

//#define INFINITY_P 999
//#define INFINITY_N -999
//#define CPU 'O'
//#define EASY 1
//#define HARD 2
//#define GAME_MODE HARD
////#define TESTING_GENERATING
////#define DEBUG

//int idCurrentNode = 0;
//std::vector<int> storedAction(2,0);
//std::vector<Node> generateNodes( Node currentNode, bool maxCalling );
//int max( Node currentNode, int alpha, int beta );
//int min( Node currentNode, int alpha, int beta );


//int max( Node currentNode, int alpha, int beta )
//{
//    #ifdef DEBUG
//        std::cout << "Iniciando chamada de max para o nó: " << currentNode.getIdNode() << std::endl;
//    #endif
//    //Verifica se é terminal
//    char utility = currentNode.getNodeState().endGame();

//    if( utility != ' ' )
//    {
//        #ifdef DEBUG
//            std::cout << "É utilidade!" << std::endl;
//        #endif
//        if( utility == CPU )
//        {
//            if( GAME_MODE == EASY )
//                return 10;
//            else
//                return 10 - currentNode.getDepth();
//        }
//        if( utility == 'V')
//        {
//            if( GAME_MODE == EASY )
//                return 0;
//            else
//                return 0 - currentNode.getDepth();
//        }
//        if( GAME_MODE == EASY )
//            return -10;
//        else
//            return -10 - currentNode.getDepth();
//    }
//    #ifdef DEBUG
//        std::cout << "Não é utilidade!" << std::endl;
//        std::getchar();
//    #endif
//    int result = INFINITY_N;

//    std::vector<Node> childNodes;

//    childNodes = generateNodes( currentNode, true );

//    //Varrer os filhos
//    int minResult;
//    for( int i = 0; i < (int) childNodes.size() ; i++ )
//    {
//        #ifdef DEBUG
//            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
//            std::cout << "alpha = " << alpha << std::endl;
//            std::cout << "beta = " << beta << std::endl;
//            std::cout << "result = " << result << std::endl;
//            std::cout << "Iniciando chamada de min para o nó: " << childNodes[i].getIdNode() << std::endl;
//            childNodes[i].getNodeState().printState();
//            std::getchar();
//        #endif
//        minResult = min( childNodes[i], alpha, beta );
//        #ifdef DEBUG
//            std::cout << "Finalizando chamada de min para o nó: " << childNodes[i].getIdNode() << std::endl;
//            childNodes[i].getNodeState().printState();
//            std::cout << "minResult = " << minResult << std::endl;
//            std::getchar();
//        #endif
//        if( result < minResult )
//        {
//            result = minResult;
//            // std::cout << "Atualizei o valor" << std::endl;
//            // childNodes[i].getNodeState().printState();
//            if( childNodes[i].getDepth() == 1 )
//            {
//                // std::cout << "É da primeira camada" << std::endl;
//                storedAction = childNodes[i].getPrevAction();
//                // childNodes[i].getNodeState().printState();
//            }
//        }
//        #ifdef DEBUG
//            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
//            std::cout << "result = " << result << std::endl;
//        #endif
//        if( result >= beta )
//        {
//            #ifdef DEBUG
//                std::cout << "Abortando busca, beta = " << beta << std::endl;
//            #endif
//            return result;
//        }
//        if( result > alpha )
//            alpha = result;
//        #ifdef DEBUG
//            std::cout << "alpha = " << alpha << std::endl;
//        #endif
//    }

//    return result;
//}

//int min( Node currentNode, int alpha, int beta )
//{
//    #ifdef DEBUG
//        std::cout << "Iniciando chamada de min para o nó: " << currentNode.getIdNode() << std::endl;
//    #endif
//    //Verifica se é terminal
//    char utility = currentNode.getNodeState().endGame();
//    if( utility != ' ' )
//    {
//        #ifdef DEBUG
//            std::cout << "É utilidade!" << std::endl;
//        #endif
//        if( utility == CPU )
//        {
//            if( GAME_MODE == EASY )
//                return 10;
//            else
//                return 10 - currentNode.getDepth();
//        }
//        if( utility == 'V')
//        {
//            if( GAME_MODE == EASY )
//                return 0;
//            else
//                return 0 - currentNode.getDepth();
//        }
//        if( GAME_MODE == EASY )
//            return -10;
//        else
//            return -10 - currentNode.getDepth();
//    }
//    #ifdef DEBUG
//        std::cout << "Não é utilidade!" << std::endl;
//        std::getchar();
//    #endif
//    int result = INFINITY_P;

//    std::vector<Node> childNodes;

//    childNodes = generateNodes( currentNode, false );

//    //Varrer os filhos
//    int maxResult;
//    for( int i = 0; i < (int) childNodes.size() ; i++ )
//    {
//        #ifdef DEBUG
//            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
//            std::cout << "alpha = " << alpha << std::endl;
//            std::cout << "beta = " << beta << std::endl;
//            std::cout << "result = " << result << std::endl;
//            std::cout << "Iniciando chamada de max para o nó: " << childNodes[i].getIdNode() << std::endl;
//            childNodes[i].getNodeState().printState();
//            std::getchar();
//        #endif
//        maxResult = max( childNodes[i], alpha, beta );
//        #ifdef DEBUG
//            std::cout << "Finalizando chamada de max para o nó: " << childNodes[i].getIdNode() << std::endl;
//            childNodes[i].getNodeState().printState();
//            std::cout << "maxResult = " << maxResult << std::endl;
//            std::getchar();
//        #endif
//        if( result > maxResult )
//        {
//            result = maxResult;
//        }
//        #ifdef DEBUG
//            std::cout << "Dados do nó pai: " << currentNode.getIdNode() << std::endl;
//            std::cout << "result = " << result << std::endl;
//        #endif
//        if( result <= alpha )
//        {
//            #ifdef DEBUG
//                std::cout << "Abortando busca, alpha = " << alpha << std::endl;
//            #endif
//            return result;
//        }
//        if( result < beta )
//            beta = result;
//        #ifdef DEBUG
//            std::cout << "beta = " << beta << std::endl;
//        #endif
//    }

//    return result;
//}

//std::vector<Node> generateNodes( Node currentNode, bool maxCalling )
//{
//    std::vector<Node> childNodes;
//    Node nodeToExpand = currentNode;
//    Node newNode;
//    State nodeState = nodeToExpand.getNodeState();
//    std::vector<int> positionVec(2,0);
//    char player = CPU;
//    if( !maxCalling )
//    {
//        if( CPU == 'X' )
//            player = 'O';
//        else
//            player = 'X';
//    }
//    #ifdef TESTING_GENERATING
//        std::cout << "Nó a ser expandido" << std::endl;
//        currentNode.getNodeState().printState();
//    #endif
//    //Gerando os filhos
//    for( int i = 0; i < 3; i++ )
//    {
//        for( int j = 0; j < 3; j++ )
//        {
//            if( nodeState.play( player, i, j ) == 0 )
//            {
//                positionVec[0] = j;
//                positionVec[1] = i;
//                newNode.setNodeState( nodeState );
//                newNode.setIdParent( nodeToExpand.getIdNode() );
//                newNode.setIdNode( ++idCurrentNode );
//                newNode.setDepth( nodeToExpand.getDepth() + 1 );
//                newNode.setPrevAction( positionVec );

//                #ifdef TESTING_GENERATING
//                    nodeState.printState();
//                    std::cout << "Id do pai: " << newNode.getIdParent() << std::endl;
//                    std::cout << "Id do nó: " << newNode.getIdNode() << std::endl;
//                    std::cout << "Profundidade: " << newNode.getDepth() << std::endl;
//                #endif
//                childNodes.push_back( newNode );
//            }
//            nodeState = nodeToExpand.getNodeState();
//        }
//    }
//    // if(childNodes[0].getDepth() == 1)
//    // {
//    //     std::cout << "Nós da primeira camada" << std::endl;
//    //     for( int i = 0; i <childNodes.size(); i++)
//    //         childNodes[i].getNodeState().printState();
//    // }
//    return childNodes;
//}

//int main()
//{
//    //char tabela[3][3] = {' ',' ','O','O','X',' ','X','X','O'};
//    //State table( tabela );
//    State vazio,currentState;
//    Node game;
//    game.setNodeState( vazio );
//    game.getNodeState().printState();
//    std::cout << "Jogo da velha.\n X -> jogador.\n O -> computador" << std::endl;
//    int posicaoX = 0, posicaoY = 0;
//    while( game.getNodeState().endGame() == ' ' )
//    {
//        std::cout << "Sua jogada" << std::endl;
//        std::cout << "Informe a posição X da sua jogada: ";
//        std::cin >> posicaoX;
//        std::cout << "Informe a posição y da sua jogada: ";
//        std::cin >> posicaoY;

//        currentState = game.getNodeState();
//        currentState.play( 'X', posicaoX, posicaoY );
//        game.setNodeState( currentState );

//        game.getNodeState().printState();
//        std::getchar();

//        std::cout << "\nJogada do PC" << std::endl;
//        std::cout << "\nresultado: " << max( game, INFINITY_N, INFINITY_P ) << std::endl;
//        std::cout << "Ação do PC : Colocar " << CPU << " em X: " << storedAction[1] << " e Y: " << storedAction[0] << std::endl;

//        currentState = game.getNodeState();
//        currentState.play( 'O', storedAction[1], storedAction[0] );
//        game.setNodeState( currentState );

//        game.getNodeState().printState();
//        std::getchar();
//    }

//    return 0;
//}
