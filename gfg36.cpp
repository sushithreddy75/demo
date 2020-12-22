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
lptr del(lptr);
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
	//cout<<"ENTER X\n";
	//cin>>x;
	cout<<"LIST BEFORE DELETING\n";
	print(head);
	head=del(head);
	cout<<"MODIFIED LIST\n";
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
lptr del(lptr head)
{
	lptr p=NULL,t=head,n;
	while(t!=NULL)
	{
		n=t->next;
		if(n!=NULL && t->data<n->data)
		{
			if(p==NULL)
			{
				head=n;
				delete(t);
				free(t);
				t=head;
			}
			else
			{
				p->next=n;
				delete(t);
				free(t);
				t=n;
			}
		}
		else
		{
			p=t;
			t=n;
		}
	}
	return head;
}