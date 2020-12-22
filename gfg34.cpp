#include<iostream>
using namespace std;
struct node
{
	int data;
	node*next;
};
typedef node* lptr;
lptr create(int);
lptr insert(lptr,int);
void print(lptr);
void alter(lptr,lptr*,lptr*);
int main()
{
	lptr head=NULL,t=NULL;
	int n,x;
	cout<<"ENTER NO OF ELEMENTS IN LIST\n";
	cin>>n;
	while(n--)
	{
		cout<<"ENTER ELEMENT OF LIST\n";
		cin>>x;
		t=insert(t,x);
		if(head==NULL)
			head=t;
	}
	lptr h1=NULL,h2=NULL;
	cout<<"ORIGINAL LIST\n";
	print(head);
	alter(head,&h1,&h2);
	cout<<"LIST-1\n";
	print(h1);
	cout<<"LIST-2\n";
	print(h2);
	return 0;
}
void alter(lptr head,lptr *h1,lptr *h2)
{
	lptr t1=NULL,t2=NULL;
	while(head!=NULL)
	{
		if(t1==NULL)
		{
			t1=head;
			*h1=t1;
			head=head->next;
		}
		else
		{
			t1->next=head;
			t1=head;
			head=head->next;
		}
		if(head!=NULL)
		{
			if(t2==NULL)
			{
				t2=head;
				*h2=t2;
				head=head->next;
			}
			else
			{
				t2->next=head;
				t2=head;
				head=head->next;
			}
		}
	}
	t2->next=NULL;
	t1->next=NULL;
	return;
}
lptr create(int x)
{
	lptr t=new node();
	t->data=x;
	t->next=NULL;
	return t;
}
lptr insert(lptr t,int x)
{
	if(t==NULL)
		return create(x);
	lptr t1=create(x);
	t->next=t1;
	return t1;
}
void print(lptr t)
{
	while(t!=NULL)
	{
		cout<<t->data<<endl;
		t=t->next;
	}
}