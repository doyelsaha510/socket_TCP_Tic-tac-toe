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
	int ssid;
	int a,b,s;
	int msgbyte;
	char str[100];
	int cid;

	int i, choice;
	char mark;		


	ssid=socket(AF_INET,SOCK_STREAM,0);
	if(ssid==-1)
	{
		printf("IN SOCKET CREATION IN SERVER SIDE FAILURE\n");
		exit(0);
	}
	printf("N SOCKET CREATION IN SERVER SIDE SUCCESSFUL\n");
	int sid;
	struct sockaddr_in ssadd;
	ssadd.sin_family=AF_INET;
	ssadd.sin_port=htons(6999);
	ssadd.sin_addr.s_addr=inet_addr("10.0.2.15");
	sid=bind(ssid,(struct sockaddr*)&ssadd,sizeof(ssadd));
	if(sid==-1)
	{
		printf("\nBINDING FAILURE AT SERVER SIDE");
		exit(0);
	}
	printf("\nBINDING SUCCESSFUL AT SERVER SIDE");

	listen(ssid,5);

	struct sockaddr_in fadd;
	int len=sizeof(fadd);
	int fd1=accept(ssid,(struct sockaddr*)&fadd,&len);
	if(fd1==(-1))
	{
		printf("\nFAILURE AT SERVER SIDE IN ACCEPT");
		exit(0);
	}
	i= checkwin();
	while(i!=1)
	{
		msgbyte=recv(fd1,&choice,sizeof(choice),0);
		if(choice==11)
		{
			printf("You win");
			close(ssid);
			break;
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
		    
		else if(choice == 9 && square[9] == '9')
		    square[9] = mark;
		    
		
		i = checkwin();
		printf("\n%d\n",i);
		if(i==1)
		{	board();
			int flag=10;
			printf("client win");
			msgbyte=send(fd1,&flag,sizeof(flag),0);
			close(ssid);
			break;
		}
	

		board();
		printf("SERVER Please Enter Your Choice\n");
		scanf("%d",&choice);
		if(!(choice>=1 && choice<=9))
		{

		    printf("Invalid move \n");
		    printf("please enter a valid choice between 1-9\n");
		    scanf("%d",&choice);
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
		    
		else if (choice == 9 && square[9] == '9')
		    square[9] = mark;
		    
		
		msgbyte=send(fd1,&choice,sizeof(choice),0);
		
	}	
	close(ssid);
	return 0;
}
