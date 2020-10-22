#include <iostream>
#include <string>

using namespace std;

// TODO: Create a struct containing a string (element_name)as well as a node pointer (Node* next)
struct Node{
  string element_name;
  Node* next;
};

class Queue {
    // --- public members ---
  public:
    Queue();
    ~Queue();
    //returns if Queue is empty
    bool isEmpty();
    //adds node with passed val as the element_name
    void Enqueue(string val);
    //deletes front node and returns its value
    string Dequeue();
    //returns string of Queue nodes from back to front
    string toString();
    // --- private members ---
  private:
    Node* front;
    Node* back;
};

Queue::Queue(){
  front = NULL;
  back = NULL;
}
Queue::~Queue(){

  while(!isEmpty()){
    cout << "deleting " << Dequeue() << endl;
  }

}
void Queue::Enqueue(string val){

  Node* newBack = new Node;
  newBack->element_name = val;

  if(back == NULL){
    back = newBack;
  }
  else{
    back->next = newBack;
    back = newBack;
  }
  if(front == NULL){
    front = newBack;
  }

}

string Queue::Dequeue(){

  if(!isEmpty()){
    string value = front->element_name;
    Node* oldFront = front;
    front = front->next;

    delete oldFront;
    return value;
  }
  else{
    cout << "Error. Can't DeQueue a empty Queue!";
    exit(1);
  }
}
string Queue::toString(){
  string result = "<-(front)";

  if(front == NULL){
    return "(back)-> NULL <-(front)";
  }
  else{
    Node* current = front;
    while(current != NULL){
      result = current->element_name + " " + result;
      current = current->next;
    }
    return "(back)->" + result;
  }
}

//returns if Queue is empty
bool Queue::isEmpty(){
  if(front == NULL){
    return true;
  }
  else{
    return false;
  }
}


int main() {

    Queue* q = new Queue();

    q->Enqueue("Turtle");
    q->Enqueue("Cat");
    q->Enqueue("Dog");
    q->Enqueue("Fish");

    cout << q->toString() << endl;

    q->Dequeue();
    q->Dequeue();

    cout << q->toString() << endl;

    delete q;

    return 0;
}
