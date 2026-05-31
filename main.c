/*
    Name      : Hanan Mohammed K
    Batch_no. : 25021B_135
    Project   : Arbitrary Pricision Calculator
    input     : ./a.out 10 + 1000000000000
    output    : 1000000000010

*/

#include"apc.h"

int main(int argc, char *argv[])
{
    dll*head1 = NULL;
    dll*head2 = NULL;
    dll*tail1 = NULL;
    dll*tail2 = NULL;

    dll*res_head = NULL;
    dll*res_tail = NULL;
    
    if(argc<4)
    {
        printf("less no of arguments passed\n");
        return 1;
    }
    else if(argc>4)
    {
        printf("More number of argumentrs passed\n");
        return 1;
    }
    
    else if(argc == 4)
    {
        
        int sign1,sign2;
        int result = validate(argv[1], argv[2], argv[3]);
        if (result == FAILURE)
        return 1;

        if (result == 5)      // first negative
        {
            sign1 = -1;
            sign2 = 1;
        }
        else if (result == 2) // second negative
        {
            sign1 = 1;
            sign2 = -1;
        }
        else if (result == 3) // both negative
        {
            sign1 = -1;
            sign2 = -1;
        }
        else                  // both positive
        {   
            sign1 = 1;
            sign2 = 1;
        }

        
        int len1,len2;
   
        len1 = strlen(argv[1]);
        len2 = strlen(argv[3]);

        int i=0,j=0;
        if(sign1 == -1)
        i=1;
        for(i;i<len1;i++)
        {
            int x = argv[1][i] - '0';
            if(insert(x,&head1,&tail1)==FAILURE)
            {
                printf("error converting first number ");
                return 0;
            }
        }
        if(sign2==-1)
        j=1;
        for(j;j<len2;j++)
        {
            int x = argv[3][j] - '0';
            if(insert(x,&head2,&tail2)==FAILURE)
            {
                printf("error converting second number ");
                return 0;
            }
        }
        leading_zero(&head1,&head2);

        if(argv[2][0]=='+')
        {
            if(sign1==-1 && sign2 ==-1)
            {
                addition(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else if(sign1==-1)
            {
                subtraction(&head2,&head1,&res_head,&tail2,&tail1,&res_tail);
            }
            else if(sign2==-1)
            {
                subtraction(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            }
            else
            addition(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);

            print(res_head);
        }
        else if(argv[2][0]=='-')
        {
           if(sign1==-1 && sign2 ==-1)
            {
                subtraction(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else if(sign1==-1)
            {
                addition(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else if(sign2==-1)
            {
                addition(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            }
            else
            subtraction(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            print(res_head);
        }
        else if(argv[2][0]=='X' || argv[2][0]=='x')
        {
            if(sign1==-1 && sign2 ==-1)
            {
                multiplication(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            }
            else if(sign1==-1)
            {
                multiplication(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else if(sign2==-1)
            {
                multiplication(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else
            multiplication(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            print(res_head);
        }
        else if(argv[2][0] == '/')
        {
            if(sign1==-1 && sign2 ==-1)
            {
                division(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            }
            else if(sign1==-1)
            {
                division(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else if(sign2==-1)
            {
                division(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
                negative_sign(&res_head,&res_tail);
            }
            else
            division(&head1,&head2,&res_head,&tail1,&tail2,&res_tail);
            print(res_head);
        }
    }
    
}