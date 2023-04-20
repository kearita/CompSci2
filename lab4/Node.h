#ifndef NODE_H
#define NODE_H


class Node {
    public:
        Node();
        virtual ~Node();
        Node *next;
        void setValue(int);
        int getValue();



    private:
        int value;
};

#endif // NODE_H
