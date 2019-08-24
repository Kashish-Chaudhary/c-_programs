/*program to convert infix expression to postfix using stack
    input-
    3*4*5-5-6+(4+5)/2   //string from user
    output-
    345**5645+2/+--

*/
#include<stdio.h>
#include<stdlib.h>
struct Stack
{
char data;
struct Stack *next;
};
void push(struct Stack **n,char c)
{
    struct Stack *temp=(struct Stack*)malloc(sizeof(struct Stack));
    temp->data=c;
    temp->next=*n;
    *n=temp;
}
int precedence(char a)
{
    if((a=='%'))
        return 2;
   if((a=='/') || a=='*')
   {
       return 1;
   }
   else if((a=='+')|| a=='-')
   {
       return 0;
   }
   else
    return -1;
}
int main()
{struct Stack *head;
head=NULL;
int n;
scanf("%d",&n);
char *a=(char *)malloc(sizeof(char)*n);
char *b=(char *)malloc(sizeof(char)*n);
int k=0,l=0,p=0;
for(int i=0;i<n;i++)
{
    scanf("%c",&a[i]);
}
for(int i=0;i<n;i++)
{
    if(a[i]=='(')
    {
        push(&head,a[i]);
    }
    else if((a[i]>='a'&& a[i]<='z') || (a[i]>='A' && a[i]<='Z'))
    {
        b[k]=a[i];k++;
    }
    else if(a[i]=='+' || a[i]=='*' || a[i]=='/' || a[i]=='-' || a[i]=='%')
    {
        if(precedence(a[i])>precedence(head->data))
        {
            push(&head,a[i]);
        }
        else
        {
            while((precedence(a[i])<=precedence(head->data)) && head->data!='('){
            b[k]=head->data;
            k++;
            head=head->next;

            }
             push(&head,a[i]);
        }
    }
    else if(a[i]==')')
    {
        while(head->data!='(')
        {

            b[k]=head->data;k++;
            head=head->next;
        }
        head=head->next;
    }

}
 while(head!=NULL  && head->data!='(')
    {
            b[k]=head->data;
            k++;
            head=head->next;
        }
        for(int i=0;i<k;i++)
        {

            printf("%c",b[i]);
        }
}

