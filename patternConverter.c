#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int rleToTxt(char *src);

int main(int argc, char *argv[])
{
	if(argc < 2){
		printf("Usage: convertPattern file1 file2 ...\n");
	}
	for(int i = 1; i < argc; i++){
		rleToTxt(argv[i]);
	}
	return 0;
}
int rleToTxt(char *src)
{
	FILE *rle = nullptr;
	if((rle = fopen(src, "r")) == nullptr){
		fprintf(stderr, "Could not open \"%s\".\n", src);
		return 0;
	}
	char buff[512];
	while(fgets(buff, 512, rle)){
		if(buff[0] != '#') break;
	}
	char *newName = strdup(src);
	newName[strlen(newName) - 3] = 't';
	newName[strlen(newName) - 2] = 'x';
	newName[strlen(newName) - 1] = 't';
	FILE *newFile = fopen(newName, "w");
	if(newFile == nullptr){
		fprintf(stderr, "Could not create output file.\n");
		fclose(rle);
		free(newName);
		return 0;
	}
	int ch = 0;
	int num = 0;
	while((ch = fgetc(rle)) != EOF){
		if(isdigit(ch)){
			num = num * 10 + ch - '0';
		} else {
			if(ch == '$'){
				int lines = (num == 0 ? 1 : num);
				for(int i = 0; i < lines; i++){
					fputc('\n', newFile);
				}
				num = 0;
			} else if(ch == '\n'){
				continue;
			} else if(ch == '!'){
				break;
			} else {
				int count = (num == 0 ? 1 : num);
				for(int i = 0; i < count; i++){
					fputc(ch, newFile);
				}
				num = 0;
			}
		}
	}
	fclose(rle);
	fclose(newFile);
	free(newName);
	return 1;
}
