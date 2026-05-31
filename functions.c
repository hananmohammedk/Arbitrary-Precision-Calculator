#include"apc.h"

int insert(int data, dll**head ,dll**tail)
{
    dll *new = malloc(sizeof(dll));
    new->next =NULL;
    new->prev = NULL;
    
    if(*head == NULL)
    {
        new->data = data;
        *head=new;
        *tail = new;
        return SUCCESS;
    }
    
        new->data =data;
        new->prev = (*tail);
        (*tail)->next=new;
        *tail=new;
    
    return SUCCESS;
}

int validate(char* num1, char * opr, char* num2)
{
	int i=0;
	int sign1=1,sign2=1;

	if(num1[i]=='-')
	{
		i++;
		sign1 =-1;
	}

	while(num1[i])
	{
		if(!isdigit(num1[i]))
		{
			printf("First number is not valid\n");
			return FAILURE;
		}
		i++;
	}
	i=0;

	if(num2[i]=='-')
	{
		i++;
		sign2=-1;
	}
	while(num2[i])
	{
		if(!isdigit(num2[i]))
		{
			printf("Second number is not valid\n");
			return FAILURE;
		}
		i++;
	}
	if(opr[1] != '\0')
	{
		printf("Invalid operator\n");
		return FAILURE;
	}

	if((opr[0] != '+') && (opr[0] != '-') && (opr[0] != '/') && (opr[0] != 'X') && (opr[0] != 'x'))
	{
		printf("Invalid operator\n");
		return FAILURE;
	}
	if((sign1==-1) && (sign2==-1))
	return 3;
	if(sign1 == -1)
	return 5;
	if(sign2 == -1)
	return 2;
	return 0;
}

int addition(dll**head1,dll**head2,dll**res_head,dll**tail1,dll**tail2,dll**res_tail)
{
	if(*head1==NULL && *head2 == NULL)
	return FAILURE;

	dll *temp1 = *tail1;
	dll *temp2 = *tail2;
	int carry=0;


	while((temp1!=NULL) && (temp2 !=NULL))
	{
		int num= (temp1->data + temp2->data + carry);
		if(num>9)
		{
			num= num%10;
			carry=1;
		}
		else
		{
			carry=0;
		}
		insert_res(num,res_head,res_tail);
		temp1=temp1->prev;
		temp2=temp2->prev;
	}

	if(temp1 != NULL)
	{
		while(temp1!=NULL)
		{
			int num=carry + temp1->data;
			if(num>9)
			{
				num= num%10;
				carry=1;
			}
			else
			{
				carry=0;
			}
			insert_res(num,res_head,res_tail);
			temp1=temp1->prev;
		}
	}
	else if(temp2 != NULL)
	{
		while(temp2!=NULL)
		{
			int num=carry + temp2->data;
			if(num>9)
			{
				num= num%10;
				carry=1;
			}
			else
			{
				carry=0;
			}
			insert_res(num,res_head,res_tail);
			temp2=temp2->prev;
		}
	}
	
	if(carry == 1)
	insert_res(carry,res_head,res_tail);
	return SUCCESS;
}

int subtraction(dll**head1, dll**head2, dll**res_head, dll**tail1, dll**tail2, dll**res_tail)
{
    // CLEAR OLD RESULT
    while (*res_head)
    {
        dll *tmp = *res_head;
        *res_head = (*res_head)->next;
        free(tmp);
    }
    *res_head = NULL;
    *res_tail = NULL;

    int out = compare(head1, head2);
    int flag = 0;
    
    // If equal, result is 0
    if(out == 0)
    {
        insert_res(0, res_head, res_tail);
        return SUCCESS;
    }
    
    // If head1 < head2, swap them and mark negative
    if(out == 2)
    {
        dll *swap = *head1;
        *head1 = *head2;
        *head2 = swap;

        swap = *tail1;
        *tail1 = *tail2;
        *tail2 = swap;
        flag = 1;
    }

    dll *temp1 = *tail1;
    dll *temp2 = *tail2;
    int bor = 0;
    int res;

    // Subtract from LSB to MSB
    while(temp1 != NULL && temp2 != NULL)
    {
        if(temp1->data < (temp2->data + bor))
        {
            res = (temp1->data + 10) - temp2->data - bor;
            bor = 1;
        }
        else
        {
            res = temp1->data - temp2->data - bor;
            bor = 0;
        }
        insert_res(res, res_head, res_tail);
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    
    // Handle remaining digits in temp1
    while(temp1 != NULL)
    {
        if(temp1->data < bor)
        {
            res = (temp1->data + 10) - bor;
            bor = 1;
        }
        else
        {
            res = temp1->data - bor;
            bor = 0;
        }
        insert_res(res, res_head, res_tail);
        temp1 = temp1->prev;
    }
    
    if(flag)
    {
        dll *temp = *res_head;
        while(temp != NULL)
        {
            if(temp->data != 0)
            {
                temp->data = temp->data * (-1);
                break;
            }
            temp = temp->next;
        }
    }
    
    // Remove leading zeros
    while(*res_head != NULL && (*res_head)->next != NULL)
    {
        if((*res_head)->data != 0) break;
        
        dll *temp = *res_head;
        *res_head = temp->next;
        (*res_head)->prev = NULL;
        free(temp);
    }
    
    return SUCCESS;
}

int multiplication(dll** head1, dll** head2, dll** res_head, dll** tail1, dll** tail2, dll** res_tail)
{
	int out = compare(head1,head2);
	if(out==2)
	{
		dll *swap = *head1;
		*head1 = *head2;
		*head2 = swap;

		swap = *tail1;
		*tail1= *tail2;
		*tail2= swap;
	}

	dll *temp2 = *tail2;
	int count = 0;
	dll *res2_head = NULL;
	dll *res2_tail = NULL;


	insert(0,&res2_head,&res2_tail);
	
	dll *res1_head = NULL;
	dll *res1_tail = NULL;

	while(temp2 != NULL)
	{
		dll *sum_head = NULL;
        dll *sum_tail = NULL;

		dll *temp1 = *tail1;
		int carry = 0;
		

		//adding zeros at the end
		for(int i=0;i<count;i++)
		{
			insert_res(0,&res1_head,&res1_tail);
		}

		while(temp1 != NULL)
		{
			int mul = (temp1->data * temp2->data) + carry;
			carry = mul / 10;
			mul = mul % 10;
			insert_res(mul,&res1_head,&res1_tail);
			temp1 = temp1->prev;
		}
		
		if(carry > 0)
		{
			insert_res(carry,&res1_head,&res1_tail);
		}
	
		addition(&res2_head,&res1_head,&sum_head,&res2_tail,&res1_tail,&sum_tail);
	
			dll *old_res2h = res2_head;
			while(old_res2h)
			{
				dll *temp = old_res2h;
				old_res2h = old_res2h->next;
				free(temp);
			}

			res2_head = sum_head;
			res2_tail = sum_tail;
			while(res1_head != NULL)
			{
				dll *temp = res1_head;
				res1_head = res1_head->next;
				free(temp);
			}
			res1_head= NULL;
			res1_tail = NULL;
	

		temp2 = temp2->prev;
		count++;
	}
	
	leading_zero(&res2_head,&res2_head);
	*res_head= res2_head;
	*res_tail= res2_tail;

	return SUCCESS;
}

int division(dll** head1, dll** head2, dll** res_head, dll** tail1, dll** tail2, dll** res_tail)
{
	if((*head2)->next == NULL )
	{
		if((*head2)->data == 0)
		{
			printf("Error : division by zero\n");
			return SUCCESS;
		}
	}
	if(compare(head1,head2) == 2)
	{
		insert(0,res_head,res_tail);
		return SUCCESS;
	}
	if( compare(head1,head2) == 0)
	{
		insert(1,res_head,res_tail);
		return SUCCESS;
	}
	dll *temp1 = *head1;
	dll *temp1_tail = *tail1;

	dll* one_h = NULL;
	dll *one_t = NULL;

	dll*count_h = NULL;
	dll*count_t = NULL;

	dll*res_counth = NULL;
	dll*res_countt = NULL;
	dll*sub_head = NULL;
	dll*sub_tail = NULL;

	insert(1,&one_h,&one_t);
	insert(0,&count_h,&count_t);

	while(compare(&temp1,head2) != 2)
	{
		subtraction(&temp1,head2,&sub_head,&temp1_tail,tail2,&sub_tail);
		while(temp1)
		{
			dll *tmp = temp1;
			temp1 = (temp1)->next;
			free(tmp);
		}
		temp1 = sub_head;
		temp1_tail = sub_tail;

		sub_head=NULL;
		sub_tail=NULL;

		addition(&count_h,&one_h,&res_counth,&count_t,&one_t,&res_countt);
		while(count_h)
		{
			dll *temp = count_h;
			count_h = count_h->next;
			free(temp);
		}
		count_h=res_counth;
		count_t=res_countt;

		res_counth = NULL;
		res_countt = NULL;
	}
	*res_head = count_h;
	*res_tail = count_t;
	
	return SUCCESS;

}



int compare(dll** head1, dll** head2)
{
	int count1=0,count2=0;
	dll *temp1 = *head1;
	dll *temp2 = *head2;

	while(temp1 != NULL)
	{
		count1++;
		temp1 = temp1->next;
	}
	while(temp2 != NULL)
	{
		count2++;
		temp2 = temp2->next;
	}

	if(count1>count2)
	return 1;
	else if(count1<count2)
	return 2;
	else
	{
		temp1 = *head1;
		temp2 = *head2;
		while(temp1 != NULL && temp2 != NULL)
		{
			if(temp1->data > temp2->data)
			return 1;

			else if(temp2->data > temp1->data)
			return 2;

			temp1= temp1->next;
			temp2= temp2->next;
		}
	}
	return 0;
}




int leading_zero(dll **head1, dll** head2)
{
	while((*head1)->next!=NULL)
	{
		dll *temp = *head1;
		if(temp->data!=0)
		break;
		*head1=temp->next;
		(*head1)->prev = NULL;
		free(temp);
	}
	while((*head2)->next!=NULL)
	{
		dll *temp = *head2;
		if(temp->data!=0)
		break;
		*head2=temp->next;
		(*head2)->prev = NULL;
		free(temp);
	}
}

int insert_res(int num,dll** res_head,dll** res_tail)
{
	dll*new = malloc(sizeof(dll));
    new->next =NULL;
    new->prev = NULL;

    if(*res_head == NULL)
    {
        new->data = num;
        *res_head=new;
        *res_tail = new;
        return SUCCESS;
    }
    
        new->data =num;
        new->next =(*res_head);
        (*res_head)->prev=new;
        *res_head=new;
    
    return SUCCESS;
}

void print(dll *head)
{
    	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
		
	    while (head)		
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	
	    }
		printf("\n");
    }
}
int negative_sign(dll **res_head, dll** res_tail)
{
    dll *temp = *res_head;
    while(temp != NULL)
    {
    	if(temp->data != 0)
        {
            temp->data = temp->data * (-1);
            break;
        }
        temp = temp->next;
    }
	return SUCCESS;
}
