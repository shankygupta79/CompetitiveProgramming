#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};
class LinkedList{
    private:
        node *head ,*tail;
        int sizee;
    public:
        LinkedList(){
            head=NULL;
            tail=NULL;
        }
        //O(1)
        void addLast (int n){
            node *tmp=new node();
            tmp->data=n;
            tmp->next=NULL;
            if(sizee>=1){
                tail->next=tmp;
                sizee++;
            }if(sizee==0){
                head=tmp;

                tail=tmp;
                head->next=tail;
                sizee++;
            }
        }
        //O(n)
        void display(){
            node *temp=new node();
            temp=head;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->next;

            }
        }
        node *removefirst(){
            return head;
        }
        int fibonacci(int n){
            if(n==1){
                return 0;
            }
            if(n==2){
                    return 1;
            }else{
                return fibonacci(n-1)+fibonacci(n-2);
            }
        }

};
int main(){
    LinkedList arr;
    arr.addLast(10);
    arr.addLast(20);
    arr.addLast(30);
    node *first=arr.removefirst();
    cout<<"First Member is "<<first->data<<"\n\n";

    cout<<"Display"<<endl;
    arr.display();
    cout<<"\n"<<endl;
    int fibo=arr.fibonacci(6);
    cout<<"Fibonacci is => "<<fibo<<endl;
    return 0;
}
