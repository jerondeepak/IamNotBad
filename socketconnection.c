int  socketconnect (){

	int  valread;
	WSADATA wsa;
	
	if (WSAStartup(MAKEWORD(2,2),&wsa)!=0){
		printf("Failed ,Error Code");
		start();
		return -1;
	}

	struct sockaddr_in serv_addr;
	if ((sock = socket(AF_INET, SOCK_STREAM, 0))<0){
		printf("can't create socker object");
		start();
		return -1;
	}

	serv_addr.sin_addr.s_addr = inet_addr(IP);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(PORT);


	if (connect(sock , (struct sockaddr *) &serv_addr, sizeof(serv_addr))<0){
		close(sock);
		sleep(2);
		start();
		return -1;
	}
	else{
		k.late=0;
	}
	//valread = read(sock , buffer , 1024);
	//printf ("%s", valread);
	if (k.late==1)
		start();
	else
		return 0;
}
