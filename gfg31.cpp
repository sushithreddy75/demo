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
lptr rev(lptr,int,int);
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
	cout<<"ENTER X\n";
	cin>>x;
	cout<<"LIST BEFORE REVERSING\n";
	print(head);
	head=rev(head,x,1);
	cout<<"REVERSED LIST\n";
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
lptr rev(lptr h,int x,int q)
{
	if(q==1)
	{
		lptr t=h,p=NULL,n=NULL;
		for(int i=0;i<x && t!=NULL;i++)
		{
			//p=t;
			n=t->next;
			t->next=p;
			p=t;
			t=n;
		}
		if(t==NULL)
			return p;
		h->next=rev(t,x,-1);
		return p;
	}
	else
	{
		lptr t=h,p=NULL,n=NULL;
		for(int i=0;i<x && t!=NULL;i++)
		{
			p=t;n=t->next;
			t=n;
		}
		if(t==NULL)
			return h;
		p->next=rev(t,x,1);
		return h;
	}
}