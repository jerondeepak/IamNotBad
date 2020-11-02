char* seperatedirectry(const char *src, int start, int end ){
	int len = end - start;
	char *dest = (char*)malloc(sizeof(char) * (len+1));
	for (int i=start;i<end &&(*(src+i)!='\0'); i++){
		*dest= *(src+i);
		dest++;
	}
	*dest='\0';
	return dest-len;
}
