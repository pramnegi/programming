#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data ;
	struct node *next;
};
struct node * head  = NULL;
struct node * add_beginning(int val )
{
	struct node * temp = (struct node *)malloc(sizeof(node));
	temp->data = val ;
	temp->next = head;
	return temp ;
}
struct node* add_end(int val )
{
	if(head==NULL)
	{
		head = add_beginning(val);
		return head;
	}
	else
	{
		struct node * temp = head;
		while((temp->next!=NULL ))
		{
			temp = temp -> next;
		}

		struct node * tempu = (struct node *)malloc(sizeof(node));
		tempu->data = val ;
		tempu ->next = NULL;
		temp->next = tempu;
		return head ;

	}
}
void delete_beginning ()
{
	if(head==NULL)
	{
		cout<<"hey the list is empty"<<endl;
		return ;
	}
	else
	{
		head = head->next;
		return ;
	}
}
void traverse()
{
	struct node * temp = head;
	if(head==NULL)
	{
		cout<<"hey the link list is empty"<<endl;
	}
	while(temp)
	{
		cout<<temp->data<<"\t";
		temp = temp->next;
	}
	cout<<endl;
}

int printTerm(int x)
{
	if(head==NULL)
	{
		cout<<"list is empty"<<endl;
	}
	else
		{
			int i=1;
			while(i<x)
				{
					head = head->next;
					i+=1;
				}
			cout<<head->data<<endl;
		}
}
void print_reverse(struct node * ulta)
{
	stack< int >s;
	while(ulta)
	{
		s.push(ulta->data);
		ulta = ulta->next;
	}
	while(!s.empty())
	{
		cout<<s.top()<<"\t";
		s.pop();
	}
	cout<<endl;
}

int main()
{
	head = NULL;
	while(1)
	{
		printf("1  :: add at beginning \n");
		printf("2  :: add at end \n");
		printf("3  :: delete from beginning \n");
		printf("4  :: print the current link list  \n");
		printf("5  :: print the current link list in reverse order \n");
		printf("6  :: print x th term\n");
		printf("7 :: exit\n");
		printf("enter the option  -- >> ");
		int num;
		scanf("%d",&num);
		switch(num)
		{
			case 1:
			{
				int value ;
				cin>>value;
				head = add_beginning(value);
				break;
			}
			case 2:
			{
				int value ;
				cin>>value;
				head = add_end(value);
				break;
			}
			case 3:
			{
				delete_beginning();
				break;
			}
			case 4:
			{
				traverse();
				break;
			}
			case 5:
			{
				struct node * temp = head;
				print_reverse(temp);
				break;
			}
			case 6:
			{
                int x;
				cout<<"enter the index of term to be printed\n"<<endl;
				cin>>x;
				printTerm(x);
				break;
			}
			case 7:
			{

				return 0;
				break;

			}

			default:
			{
				cout<<"enter the correct option"<<endl<<endl;
				break;
			}
		}
	}
	return 0;
}
