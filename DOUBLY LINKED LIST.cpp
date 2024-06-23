#include <iostream>
using namespace std;

// NODE CLASS TO REPRESENT EACH NODE IN THE DOUBLY LINKED LIST
class Node {
public:
    int data;      // DATA HELD BY THE NODE
    Node* prev;    // POINTER TO THE PREVIOUS NODE
    Node* next;    // POINTER TO THE NEXT NODE

    Node() : data(NULL), prev(NULL), next(NULL) {}  // DEFAULT CONSTRUCTOR
    Node(int data) : data(data), prev(NULL), next(NULL) {}  // PARAMETERIZED CONSTRUCTOR
};

// CLASS FOR DOUBLY LINKED LIST
class DoubkyLinkedList {
    Node* HEAD; // POINTER TO THE FIRST NODE
    Node* TAIL; // POINTER TO THE LAST NODE
public:

    DoubkyLinkedList() : HEAD(NULL), TAIL(NULL) {}  // DEFAULT CONSTRUCTOR INITIALIZE HEAD & TAIL TO NULL
  
    Node* CreateNode(int data) {  // FUNCTION TO CREATE A NEW NODE
        Node* temp = new Node(data); 
        return temp;  
    }
    
    void InsertAtStart(int data) {  // FUNCTION TO INSERT NODE AT THE START
        Node* temp = new Node(data); 
        if (HEAD == NULL) {  // IF LIST IS EMPTY
            HEAD = temp;  // HEAD AND TAIL POINT TO NEW NODE
            TAIL = temp;
        }
        else {  // IF LIST IS NOT EMPTY
            HEAD->prev = temp;  // NEW NODE POINTS TO OLD HEAD AS NEXT
            temp->next = HEAD;
            HEAD = temp;  // HEAD NOW POINTS TO NEW NODE
        }
    }

    
    void InsertAtEnd(int data) {  // FUNCTION TO INSERT NODE AT THE END
        Node* temp = new Node(data);  
        if (HEAD == NULL) {  // IF LIST IS EMPTY
            HEAD = temp;  // HEAD AND TAIL POINT TO NEW NODE
            TAIL = temp;
        }
        else {  // IF LIST IS NOT EMPTY
            TAIL->next = temp;  // OLD TAIL POINTS TO NEW NODE AS NEXT
            temp->prev = TAIL;
            TAIL = temp;  // TAIL NOW POINTS TO NEW NODE
        }
    }

    
    void InsertAtSpecificPosition(int data, int position) {  // FUNCTION TO INSERT NODE AT A SPECIFIC POSITION
        if (position < 1) {  // INVALID POSITION CHECK
            cout << "INVALID POSITION! INSERTING AT START";
            InsertAtStart(data);
            return;
        }
        Node* temp = CreateNode(data);
        Node* curr = HEAD, * prev = HEAD;  // TRAVERSAL POINTERS

        for (int count = 1; count < position; count++) {  // TRAVERSE TO THE SPECIFIC POSITION
            if (curr == NULL) {  // IF POSITION IS OUT OF BOUNDS
                cout << "INDEX OUT OF BOUND! INSERTING AT END" << endl;
                InsertAtEnd(data);  // INSERT AT END
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        prev->next = temp;  
        temp->prev = prev;  // INSERTING NODE IN BETWEEN
        temp->next = curr;
        curr->prev = temp;
    }

    
    void DeleteAtStart() {  // FUNCTION TO DELETE NODE AT THE START
        if (HEAD == NULL) {  // IF LIST IS EMPTY
            cout << "LIST IS ALREADY EMPTY! NOTHING TO DELETE" << endl;
            return;
        }
        if (HEAD == TAIL) {  // IF LIST HAS ONLY ONE NODE
            delete HEAD;
            HEAD = TAIL = NULL;  // RESET HEAD AND TAIL TO NULL
            return;
        }
        Node* temp = HEAD;  // STORE CURRENT HEAD IN TEMP
        HEAD = HEAD->next;  // MOVE HEAD TO THE NEXT NODE
        HEAD->prev = NULL;  // SET PREVIOUS POINTER OF NEW HEAD TO NULL
        delete temp;  // DELETE OLD HEAD
    }

    void DeleteAtEnd() { // FUNCTION TO DELETE NODE AT THE END
        if (HEAD == NULL) {  // IF LIST IS EMPTY
            cout << "LIST IS ALREADY EMPTY! NOTHING TO DELETE" << endl;
            return;
        }
        if (HEAD == TAIL) {  // IF LIST HAS ONLY ONE NODE
            delete HEAD;
            HEAD = TAIL = NULL;  // RESET HEAD AND TAIL TO NULL
            return;
        }
        Node* temp = TAIL;  // STORE CURRENT TAIL IN TEMP
        TAIL = TAIL->prev;  // MOVE TAIL TO THE PREVIOUS NODE
        TAIL->next = NULL;  // SET NEXT POINTER OF NEW TAIL TO NULL
        delete temp;  // DELETE OLD TAIL
    }

    void DeleteAtSpecificPosition(int position) {     // FUNCTION TO DELETE NODE AT A SPECIFIC POSITION
        if (position < 1) {  // INVALID POSITION CHECK
            cout << "INVALID POSITION! DELETING AT START" << endl;
            DeleteAtStart();
            return;
        }
        if (HEAD == TAIL) {  // IF LIST HAS ONLY ONE NODE
            delete HEAD;
            HEAD = TAIL = NULL;  // RESET HEAD AND TAIL TO NULL
            return;
        }
        Node* curr = HEAD, * prev = HEAD;  // TRAVERSAL POINTERS
        for (int count = 1; count < position; count++) {  // TRAVERSE TO THE SPECIFIC POSITION
            if (curr == NULL) {  // IF POSITION IS OUT OF BOUNDS
                cout << "INDEX OUT OF BOUND! DELETING AT END" << endl;
                DeleteAtEnd();
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        if (curr == TAIL) {  // IF DELETING THE TAIL NODE
            Node* temp = TAIL;
            TAIL = TAIL->prev;  // MOVE TAIL TO THE PREVIOUS NODE
            TAIL->next = NULL;  // SET NEXT POINTER OF NEW TAIL TO NULL
            delete temp;  // DELETE OLD TAIL
            return;
        }
        Node* temp = curr;  // STORE CURRENT NODE IN TEMP
        curr = curr->next;  // MOVE CURRENT TO THE NEXT NODE
        curr->prev = prev;  // LINK PREVIOUS NODE TO CURRENT NODE
        prev->next = curr;
        delete temp;  // DELETE OLD NODE
    }

    void ForwardTraversal() {   // FUNCTION FOR FORWARD TRAVERSAL OF LIST
        Node* curr = HEAD; 
        cout << "FORWARD TRAVERSAL DATA : ";
        while (curr != NULL) {  // TRAVERSE TILL END
            cout << curr->data << " ";  
            curr = curr->next;  
        }
        cout << endl;
    }
    void ReverseTraversal() {  // FUNCTION FOR REVERSE TRAVERSAL OF LIST
        Node* curr = TAIL;  
        cout << "REVERSE TRAVERSAL DATA : ";
        while (curr != NULL) {  // TRAVERSE TILL START
            cout << curr->data << " ";  
            curr = curr->prev;  
        }
        cout << endl;
    }
};

int main(){
    DoubkyLinkedList l1; 

    l1.InsertAtEnd(1);     // INSERTING NODES AT THE END
    l1.InsertAtEnd(2);
    l1.InsertAtEnd(3);
    l1.InsertAtEnd(4);
    l1.InsertAtEnd(5);
    l1.InsertAtEnd(6);
    l1.InsertAtEnd(7);
    l1.InsertAtEnd(8);
    l1.InsertAtEnd(9);
    l1.InsertAtEnd(10);

    // DISPLAY CURRENT LIST
    cout << "CUURENT LIST " << endl;
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // INSERT NODE AT START
    cout << "----------------------------------" << endl;
    cout << "INSERTING AT START" << endl;
    l1.InsertAtStart(0);
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // INSERT NODE AT END
    cout << "----------------------------------" << endl;
    cout << "INSERTING AT END" << endl;
    l1.InsertAtEnd(11);
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // INSERT NODE AT SPECIFIC POSITION
    cout << "----------------------------------" << endl;
    cout << "INSERTING AT SPECIFIC POSITION" << endl;
    l1.InsertAtSpecificPosition(12, 7);
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // DELETE NODE AT START
    cout << "----------------------------------" << endl;
    cout << "DELETEING AT START" << endl;
    l1.DeleteAtStart();
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // DELETE NODE AT END
    cout << "----------------------------------" << endl;
    cout << "DELETEING AT END" << endl;
    l1.DeleteAtEnd();
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // DELETE NODE AT SPECIFIC POSITION
    cout << "----------------------------------" << endl;
    cout << "DELETEING AT SPECIFIC POSITION" << endl;
    l1.DeleteAtSpecificPosition(4);
    l1.ForwardTraversal();
    l1.ReverseTraversal();

    // FORWARD TRAVERSA
    cout << "----------------------------------" << endl;
    cout << "FORWARD TRAVERSAL " << endl;
    l1.ForwardTraversal();

    // REVERSE TRAVERSA
    cout << "----------------------------------" << endl;
    cout << "REVERSE TRAVERSAL " << endl;
    l1.ReverseTraversal();
}
