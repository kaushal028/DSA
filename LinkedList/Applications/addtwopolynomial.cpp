/*
This code adds two polynomials represented as singly linked lists.
Limitations:
- Input terms must be inserted in descending order of exponents.
- If input is not sorted, the result may be incorrect.
- Duplicate exponents are not combined during insertion.
- Output is not formatted as a standard polynomial expression.
*/
#include<iostream>
using namespace std;
class Node
{
    public:
    int coefficient;
    int exponent;
    Node* next;
    Node(int c,int e)
    {
     coefficient=c;
     exponent=e;
     next=NULL;
    }
};
class linked_list
{
    Node* head;
    Node* tail;
public:
linked_list()
{
    head=tail=NULL;
}
void insert(int coeff,int expo)//Just doing push_back
{
    if(coeff==0)
    {
        return;
    }
    Node* newnode=new Node(coeff,expo);
if(head==NULL)
{
    head=tail=newnode;
}
else
{
    tail->next=newnode;
    tail=newnode;
}
}
void print_list()
{
    Node* temp=head;
    if(temp==NULL)
    {
        cout<<"0"<<endl;
        return;
    }
    while(temp!=NULL)
    {
    cout<<temp->coefficient<<"\t"<<temp->exponent<<endl;
    temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

linked_list addPolynomial(const linked_list& l1, const linked_list& l2)//pass by reference
{//making the fn parameter const prevents modification of the list that we pass
    //pass by reference so we dont do hassle of copying the list directly pass the list
    Node* head1 = l1.head;
    Node* head2 = l2.head;
    linked_list result;

    while(head1 != NULL && head2 != NULL)
    {
        if(head1->exponent > head2->exponent)
        {
            result.insert(head1->coefficient, head1->exponent);
            head1 = head1->next;
        }
        else if(head1->exponent < head2->exponent)
        {
            result.insert(head2->coefficient, head2->exponent);
            head2 = head2->next;
        }
        else
        {
            int sumcoeff = head1->coefficient + head2->coefficient;
            if(sumcoeff != 0)
                result.insert(sumcoeff, head1->exponent);
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    while(head1 != NULL)
    {
        result.insert(head1->coefficient, head1->exponent);
        head1 = head1->next;
    }
    while(head2 != NULL)
    {
        result.insert(head2->coefficient, head2->exponent);
        head2 = head2->next;
    }
    return result;
}
};



int main()
    {

linked_list ll1;
linked_list ll2;

ll1.insert(4,2);
ll1.insert(4,1);
ll1.insert(4,0);
ll2.insert(4,3);
ll2.insert(4,2);
ll2.insert(4,0);
ll1.print_list();
ll2.print_list();
linked_list sum = ll1.addPolynomial(ll1,ll2);
sum.print_list();

return 0;
    }
