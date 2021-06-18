//CABECERA LA COLA
#ifndef DYNAMICQUEUE_H_INCLUDED
#define DYNAMICQUEUE_H_INCLUDED

//DEFINICION DE LA CLASE COLA
template <class T>
class Queue
{
private:
    //DEFINICION PARA EL NODO
    class Node
    {
    private:
        T *dataPtr;
        Node *prev;
        Node *next;

    public:
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

        Node();
        Node(const T &);
        ~Node();

        void setDataPtr(T *);
        void setData(const T &);
        void setPrev(Node *);
        void setNext(Node *);

        T *getDataPtr() const;
        T getData() const;
        Node *getPrev() const;
        Node *getNext() const;
    };

    Node *header;

    void copyAll(const Queue<T> &);

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

    Queue();
    Queue(const Queue &);

    ~Queue();

    bool isEmpty();

    void enqueue(const T &);

    T dequeue();

    T getFront() const;

    Queue &operator=(const Queue &);
};

//IMPLEMENTACION DE LA CLASE COLA

//INICIO IMPLEMENTACION DEL NODO
template <class T>
Queue<T>::Node::Node()
{
    dataPtr = nullptr;
    prev = nullptr;
    next = nullptr;
}

template <class T>
Queue<T>::Node::Node(const T &element)
{
    dataPtr = new T(element);
    prev = nullptr;
    next = nullptr;

    if (dataPtr == nullptr)
    {
        throw Exception("Memoria insuficiente para crear un nodo");
    }
}

template <class T>
Queue<T>::Node::~Node()
{
    delete dataPtr;
}

template <class T>
void Queue<T>::Node::setDataPtr(T *ptr)
{
    dataPtr = ptr;
}

template <class T>
void Queue<T>::Node::setData(const T &element)
{
    if (dataPtr == nullptr)
    {
        if (dataPtr = new T(element) == nullptr)
        {
            throw Exception("Memoria no disponible para ingresar dato");
        }
    }
    else
    {
        *dataPtr = element;
    }
}

template <class T>
void Queue<T>::Node::setPrev(Node *ptr)
{
    prev = ptr;
}

template <class T>
void Queue<T>::Node::setNext(Node *ptr)
{
    next = ptr;
}

template <class T>
T *Queue<T>::Node::getDataPtr() const
{
    return dataPtr;
}

template <class T>
T Queue<T>::Node::getData() const
{
    if (dataPtr == nullptr)
    {
        throw Exception("El dato solicitado no existe");
    }

    return *dataPtr;
}

template <class T>
typename Queue<T>::Node *Queue<T>::Node::getPrev() const
{
    return prev;
}

template <class T>
typename Queue<T>::Node *Queue<T>::Node::getNext() const
{
    return next;
}
//FIN IMPLEMENTACION DEL NODO

template <class T>
void Queue<T>::copyAll(const Queue<T> &queue)
{
    Node *aux(queue.header->getNext());
    Node *newNode;

    while (aux != queue.header)
    {
        try
        {
            if((newNode = new Node(aux->getData())) == nullptr)
            {
                throw Exception("Memoria no disponible para copiar cola");
            }
        }
        catch(typename Node::Exception excep)
        {
            throw Exception(excep.what());
        }
        
        newNode->setPrev(header->getPrev());
        newNode->setNext(header);

        header->getPrev()->setNext(newNode);
        header->setPrev(newNode);

        aux = aux->getNext();
    }
}

template <class T>
void Queue<T>::deleteAll()
{
    Node *aux;

    while (header->getNext() != header)
    {
        aux = header->getNext();

        header->setNext(aux->getNext());

        delete aux;
    }

    header->setPrev(header);
}

template <class T>
Queue<T>::Queue()
{
    header = new Node;

    if (header == nullptr)
    {
        throw Exception("Memoria no disponible para iniciar la lista");
    }

    header->setPrev(header);
    header->setNext(header);
}

template <class T>
Queue<T>::Queue(const Queue &queue)
{
    Queue();
    copyAll(queue);
}

template <class T>
Queue<T>::~Queue()
{
    deleteAll();
    delete header;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return header->getNext() == header;
}

template <class T>
void Queue<T>::enqueue(const T &element)
{
    Node *aux;
    //new Node(element);
    aux = new Node(element);
    try
    {
        if ((aux == nullptr))
        {
            throw Exception("Memoeioa no disponible para encolar");
        }
    }
    catch (typename Node::Exception excep)
    {
        throw Exception(excep.what());
    }

    aux->setPrev(header->getPrev());
    aux->setNext(header);

    header->getPrev()->setNext(aux);
    header->setPrev(aux);
}

template <class T>
T Queue<T>::dequeue()
{
    if (isEmpty())
    {
        throw Exception("Insuficiencia de datos para desencolar");
    }

    T result(header->getNext()->getData());

    Node *aux(header->getNext());

    aux->getPrev()->setNext(aux->getNext());
    aux->getNext()->setPrev(aux->getPrev());

    delete aux;

    return result;
}

template <class T>
T Queue<T>::getFront() const
{
    if (isEmpty())
    {
        throw Exception("Insuficiencia de datos, no hay frente");
    }

    return header->getNext()->getData();
}

template <class T>
Queue<T> &Queue<T>::operator=(const Queue &queue)
{
    deleteAll();
    copyAll(queue);

    return *this;
}

#endif