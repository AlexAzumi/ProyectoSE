//CABECERA DE LA PILA
#ifndef DYNAMICSTACK_H_INCLUDED
#define DYNAMICSTACK_H_INCLUDED

#include <exception>
#include <string>

//INICIO DEFINICION DE LA CLASE PILA
template <class T>
class Stack
{
private:
    class Node
    {
    private:
        T data;
        Node *link;

    public:
        Node();
        Node(const T &);

        void setData(const T &);
        void setLink(Node *);

        T getData() const;
        Node *getLink() const;
    };

    Node *anchor;

    void copyAll(const Stack &);

    void deleteAll();

public:

    //CLASE PARA LA EXCEPCION
    class Exception : public std::exception
    {
    private:
        std::string msg;

    public:
        explicit Exception(const char *message) : msg(message) {}

        explicit Exception(const std::string &message) : msg(message) {}

        virtual ~Exception() throw() {}

        virtual const char *what() const throw()
        {
            return msg.c_str();
        }
    };

    Stack();
    Stack(const Stack &);

    ~Stack();

    bool isEmpty() const;

    void push(const T &);

    T pop();

    T getTop() const;

    Stack &operator=(const Stack &);
};
//FIN DEFINICION CLASE PILA

//INICIO IMPLEMENTACION DE LA CLASE PILA

//INICIO IMPLEMENTACION DEL NODO
template <class T>
Stack<T>::Node::Node()
{
    link = nullptr;
}

template <class T>
Stack<T>::Node::Node(const T &element)
{
    data = element;
    link = nullptr;
}

template <class T>
void Stack<T>::Node::setData(const T &element)
{
    data = element;
}

template <class T>
void Stack<T>::Node::setLink(Node *newLink)
{
    link = newLink;
}

template <class T>
T Stack<T>::Node::getData() const
{
    return data;
}

template <class T>
typename Stack<T>::Node *Stack<T>::Node::getLink() const
{
    return link;
}
//FIN IMPLEMENTACION DEL NODO

template <class T>
void Stack<T>::copyAll(const Stack &stack)
{
    Node *aux = stack.anchor;
    Node *last = nullptr;
    Node *newNode;

    while (aux != nullptr)
    {
        newNode = new Node(aux->getData());

        if (last == nullptr)
        {
            anchor == newNode;
        }
        else
        {
            last->setLink(newNode);
        }

        last = newNode;

        aux = aux->getLink();
    }
}

template <class T>
void Stack<T>::deleteAll()
{
    Node *aux;

    while (anchor != nullptr)
    {
        aux = anchor;

        anchor = anchor->getLink();

        delete aux;
    }
}

template <class T>
Stack<T>::Stack()
{
    anchor = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack<T> &stack)
{
    anchor = nullptr;
    copyAll(stack);
}

template <class T>
Stack<T>::~Stack()
{
    deleteAll();
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return anchor == nullptr;
}

template <class T>
void Stack<T>::push(const T &element)
{
    Node *aux(new Node(element));

    if(aux == nullptr)
    {
        throw Exception("Memoria no disponible para apilar");
    }

    aux->setLink(anchor);

    anchor = aux;
}

template <class T>
T Stack<T>::pop()
{
    if(anchor == nullptr)
    {
        throw Exception("Insuficiencia de datos para desapilar");
    }

    T result(anchor->getData());

    Node *aux(anchor);

    anchor = anchor->getLink();

    delete aux;

    return result;
}

template <class T>
T Stack<T>::getTop() const
{
    if(anchor == nullptr)
    {
        throw Exception("Insuficiencia de datos");
    }

    return anchor->getData();
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &stack)
{
    deleteAll();

    copyAll(stack);

    return *this;
}

#endif