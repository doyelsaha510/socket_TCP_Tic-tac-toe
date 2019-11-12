#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkwin()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


/*******************************************************************
FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 ********************************************************************/


void board()
{
    
    printf("\n\n\tTic Tac Toe\n\n");

    printf("CLIENT (X)  -  SERVER (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

int main()
{
	int csid;
	char str[100];
	int cid;
	int msgbyte;
	int a,b,s;
	int i, choice;
	char mark;


	csid=socket(AF_INET,SOCK_STREAM,0);
	if(csid==-1)
	{
		printf("IN SOCKET CREATION IN CLIENT SIDE FAILURE\n");
		exit(0);
	}
	printf("IN SOCKET CREATION IN CLIENT SIDE SUCCESSFUL\n");
	
	struct sockaddr_in csadd;
	csadd.sin_family=AF_INET;
	csadd.sin_port=htons(6999);
	csadd.sin_addr.s_addr=inet_addr("10.0.2.15");
	int c=connect(csid,(struct sockaddr*)&csadd,sizeof(csadd));
	if(c==0)
	{
		printf("CONNECTION ESTABLISHMENT SUCCESSFUL\n");
	}
	if(c==(-1))
	{
		printf("CONNECTION ESTABLISHMENT UNSUCCESSFUL\n");
		exit(0);
	}

	i = checkwin();
	while(i!=1)
	{		
		board();
		printf("CLIENT Please Enter Your Choice\n");
		scanf("%d",&choice);
		if(!(choice>=1 && choice<=9))
		{

		    printf("Invalid move \n");
		    printf("please enter a valid choice between 1-9\n");
		    scanf("%d",&choice);
		}
		
		mark='X';
		if (choice == 1 && square[1] == '1')
		    square[1] = mark;
		    
		else if (choice == 2 && square[2] == '2')
		    square[2] = mark;
		    
		else if (choice == 3 && square[3] == '3')
		    square[3] = mark;
		    
		else if (choice == 4 && square[4] == '4')
		    square[4] = mark;
		    
		else if (choice == 5 && square[5] == '5')
		    square[5] = mark;
		    
		else if (choice == 6 && square[6] == '6')
		    square[6] = mark;
		    
		else if (choice == 7 && square[7] == '7')
		    square[7] = mark;
		    
		else if (choice == 8 && square[8] == '8')
		    square[8] = mark;
		    
		else if (choice == 9 && square[9] == '9')
		    square[9] = mark;
		    
		
		msgbyte=send(csid,&choice,sizeof(choice),0);
		//board();

	
		msgbyte=recv(csid,&choice,sizeof(choice),0);

		if(choice==10)
		{
			printf("You win");
			close(csid);
			break;
		}
		mark='O';
		if (choice == 1 && square[1] == '1')
        	    square[1] = mark;
            
        	else if (choice == 2 && square[2] == '2')
        	    square[2] = mark;
            
        	else if (choice == 3 && square[3] == '3')
        	    square[3] = mark;
            
        	else if (choice == 4 && square[4] == '4')
        	    square[4] = mark;
            
        	else if (choice == 5 && square[5] == '5')
        	    square[5] = mark;
            
        	else if (choice == 6 && square[6] == '6')
        	    square[6] = mark;
            
        	else if (choice == 7 && square[7] == '7')
        	    square[7] = mark;
        	    
        	else if (choice == 8 && square[8] == '8')
        	    square[8] = mark;
            
        	else if(choice == 9 && square[9] == '9')
        	    square[9] = mark;
            


		board();
		i = checkwin();
		printf("\n%d\n",i);
		if(i==1)
		{	board();
			int flag=11;
			printf("server win");
			msgbyte=send(csid,&flag,sizeof(flag),0);
			close(csid);
			break;
		}
		
	
	}
	close(csid);
	return 0;
}
