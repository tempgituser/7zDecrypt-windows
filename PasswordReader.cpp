#include"PasswordReader.h"

char ** dic;
int totalnumber;

void initDict(){
	dic = (char **)malloc(sizeof(char*)*MAX_PASSWORD_NUMBER);
	memset(dic, '\0', sizeof(char*)*MAX_PASSWORD_NUMBER);
	for(int i = 0; i < MAX_PASSWORD_NUMBER; i++){
		dic[i] = (char * )malloc(sizeof(char)*MAX_PASSWORD_LENGTH);
		memset(dic[i], '\0', sizeof(char)*MAX_PASSWORD_LENGTH);
	}
	cout<<"init dic."<<endl;
}
int read(){

	if(dic == NULL){initDict();}


	FILE* settingFile;
	char* inputFile = "T:\\pass.txt";
	if (fopen_s(&settingFile, inputFile, "rt") != 0){
		wcout << inputFile << " dict not exist" << endl;
		return -1;
	}

	if (feof(settingFile)){
		wcout << "dict is empty in " << inputFile << "." << endl;
		return -1;
	}

	char* passwordline = (char*)malloc(sizeof(char)*MAX_PASSWORD_LENGTH);
	memset(passwordline, '\0', sizeof(char)*MAX_PASSWORD_LENGTH);
	totalnumber = 0;

	while (1){
		fgets(passwordline, MAX_PASSWORD_LENGTH, settingFile);
		if(feof(settingFile)){
			break;
		}
		if(strlen(passwordline) < 1 || passwordline[0] == 10){
			continue;
		}
		
		//wcout<<passwordline;
		strcpy(dic[totalnumber], passwordline);
		totalnumber++;

		
	}




	return 0;
}