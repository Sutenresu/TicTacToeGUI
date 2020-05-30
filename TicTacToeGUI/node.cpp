#include "node.h"

Node::Node(int idNodeGenerated, int idParentGiven, std::vector<int> prevAction, int depth)
{
    Node::idNode = idNodeGenerated;
    Node::idParent = idParentGiven;
    Node::prevAction.push_back( prevAction[0] );
    Node::prevAction.push_back( prevAction[1] );
    Node::depth = depth;
}

Node::Node(void)
{
    Node::idNode = 0;
    Node::idParent = 0;
    Node::prevAction.push_back( 0 );
    Node::prevAction.push_back( 0 );
    Node::depth = 0;
}

int Node::getIdNode()
{
    return Node::idNode;
}

int Node::getIdParent()
{
    return Node::idParent;
}

std::vector<int> Node::getPrevAction()
{
    return Node::prevAction;
}

int Node::getDepth()
{
    return Node::depth;
}

State Node::getNodeState()
{
    return Node::nodeState;
}

void Node::setIdNode(int idNode){
    Node::idNode = idNode;
}

void Node::setIdParent(int idParent){
    Node::idParent = idParent;
}

void Node::setPrevAction(std::vector<int> prevAction){
    Node::prevAction = prevAction;
}

void Node::setDepth(int depth)
{
    Node::depth = depth;
}

void Node::setNodeState(State nodeState)
{
    Node::nodeState = nodeState;
}

