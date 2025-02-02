#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char b[100];
int top=-1;
int isop(char a)
{
    if(a=='+'||a=='-'||a=='*'||a=='/')
    {
    return 1;
    }
    return 0;
}
int prec(char a)
{
    if(a=='^')
    {
    return 3;
    }
    
    if(a=='*'||a=='/')
    {
    return 2;
    }
    
    if(a=='+'||a=='-')
    {
    return 1;
    }
    
    return 0;
}
void push(char a)
{
    top++;
    b[top]=a;
}
char pop()
{
    if(top!=-1)
    {
        char x=b[top];
        top--;
        return x;
    }
    return '\0';
}
void main()
{
    char in[100];
    char post[100];
    int i=0;
    printf("enter the infix expression:");
    scanf("%s",in);
    int j=0;
    while(in[i]!='\0')
    {
        
        if(in[i]=='(')
        {
        push(in[i]);
        }
        else if(in[i]==')')
        {
            while(b[top]!='(')
            {
                post[j]=pop();
                j++;
            }
            pop();
        }
        else if(!isop(in[i]))
        {
            post[j]=in[i];
            j++;
        }
        else if(isop(in[i]))
        {
            while(prec(in[i])<=prec(b[top])&&top!=-1)
            {
                post[j]=pop();
                j++;
            }
            push(in[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        post[j]=pop();
        j++;
    }
    post[j]='\0';
    printf("the postfix expression:%s",post);
}