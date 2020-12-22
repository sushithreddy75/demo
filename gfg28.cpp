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
lptr merge(lptr,lptr);
void print(lptr);
int main()
{
	lptr h1=NULL,h2=NULL,t=NULL;
	int n,x;
	cout<<"ENTER NO OF ELEMENTS IN LIST-1\n";
	cin>>n;
	while(n--)
	{
		cout<<"ENTER ELEMENT OF LIST-1\n";
		cin>>x;
		t=insert(t,x);
		if(h1==NULL)
			h1=t;
	}
	cout<<"ENTER NO OF ELEMENTS IN LIST-2\n";
	cin>>n;
	t=NULL;
	while(n--)
	{
		cout<<"ENTER ELEMENT OF LIST-2\n";
		cin>>x;
		t=insert(t,x);
		if(h2==NULL)
			h2=t;
	}
	cout<<"LIST-1\n";
	print(h1);
	cout<<"LIST-2\n";
	print(h2);
	lptr head=merge(h1,h2);
	cout<<"LIST AFTER MERGING\n";
	print(head);
	return 0;
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
lptr merge(lptr h1,lptr h2)
{
	lptr head=NULL;
	while(h1!=NULL && h2!=NULL)
	{
		if(h1->data<h2->data)
		{
			if(head==NULL)
			{
				head=h1;
				h1=h1->next;
				head->next=NULL;
			}
			else
			{
				lptr t=h1;
				h1=h1->next;
				t->next=head;
				head=t;
			}
		}
		else
		{
			if(head==NULL)
			{
				head=h2;
				h2=h2->next;
				head->next=NULL;
			}
			else
			{
				lptr t=h2;
				h2=h2->next;
				t->next=head;
				head=t;
			}
		}
	}
	while(h1!=NULL)
	{
		lptr t=h1;
		h1=h1->next;
		t->next=head;
		head=t;
	}
	while(h2!=NULL)
	{
		lptr t=h2;
		h2=h2->next;
		t->next=head;
		head=t;
	}
	return head;
}