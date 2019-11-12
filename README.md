# socket_TCP_Tic-tac-toe
Socket programming is a way of connecting two nodes on a network to communicate with each other. One socket(node) listens on a particular port at an IP, while other socket reaches out to the other to form a connection. Server forms the listener socket while client reaches out to the server.
Protocol:TCP
Variables:socket_id,bind_id,choice of client and server
Methods:socket(),bind(),listen(),accept(),connect(),send(),recv(),checkwin()[To check the who won client or server],board()[to set the game environment].
Structure:sockaddr_in for setting the ip family,address,portno.
