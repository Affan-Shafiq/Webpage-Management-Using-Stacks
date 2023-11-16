#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class stack {
    private:
        Node* top;
    public:
        stack() {
            top = NULL;
        }
        void push(string d) {
            Node* newNode = new Node;
            newNode->data = d;
            newNode->next = top;
            top = newNode;
            cout << "Webpage Saved" << endl;
        }
        string pop() {
            if(top == NULL) {
                cout << "Stack Underflow!!!" << endl;
                return "0";
            }
        Node* temp = top;
        string poppedItem = temp->data;
        top = top->next;
        delete temp;
        cout << "Webpage Popped" << endl;
        return poppedItem;
        }
        void clearStack() {
            if(top == NULL) {
                cout << "Stack Already Clear!!!" << endl;
                return;
            }
            while(top != NULL) {
                Node* temp = top;
                top = top->next;
                delete temp;
            }
        cout << "Stack Cleared!!!" << endl;
        }
};

int main() {
    stack backStack;
    stack forwardStack;
    string poppedItem;
    char choice;
    
    backStack.push("Youtube");
    backStack.push("Google");
    backStack.push("GitHub");
    forwardStack.push("Amazon");
    forwardStack.push("Yahoo");
    forwardStack.push("GCR");
    
    
    do {
        cout << endl << endl;
        cout << "F. For Forward\nB. For Backward\nN. For New Page\nE. For Exit" << endl;
        cin >> choice;
        switch(choice) {
            case 'b':
            case 'B':
                poppedItem = backStack.pop();
                if(poppedItem == "0") {
                break;
                }
                forwardStack.push(poppedItem);
                cout << "Backed Successfully!!! " << poppedItem << endl;
                break;
            case 'f':
            case 'F':
                poppedItem = forwardStack.pop();
                if(poppedItem == "0") {
                break;
                }
                backStack.push(poppedItem);
                cout << "Fowarded Successfully!!! " << poppedItem << endl;
                break;
            case 'n':
            case 'N':
                cout << "Enter New Page:" << endl;
                cin >> poppedItem;
                backStack.push(poppedItem);
                forwardStack.clearStack();
                break;
            default:
                cout << "Exited Successfully!!!" << endl;
        }
    } while((choice != 'e') && (choice != 'E'));
    return 0;
}



