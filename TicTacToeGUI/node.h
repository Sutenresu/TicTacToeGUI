#ifndef NODE_H
#define NODE_H

#include "state.h"

class Node
{
public:
    //Para externalizar a geração do número de identificação e facilitar o problema
    Node(int idNodeGenerated, int idParentGiven, std::vector<int> prevAction, int depth);
    Node(void);
    int getIdNode();
    int getIdParent();
    std::vector<int> getPrevAction();
    int getDepth();
    void setNodeState(State nodeState);
    void setIdNode(int idNode);
    void setIdParent(int idParent);
    void setPrevAction( std::vector<int> prevAction );
    void setDepth(int depth);
    State getNodeState();

private:
    State nodeState;
    //Para termos controle de que nó é quem, e fazer o esquema de pai e filho
    int idNode;
    int idParent;
    int depth;
    std::vector<int> prevAction;
};

#endif // NODE_H
