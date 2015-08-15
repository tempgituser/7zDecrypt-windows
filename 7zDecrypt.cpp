#pragma once
//#include<iostream>
#include"PasswordReader.h"
//using namespace std;

extern char** dic;
extern int totalnumber;

int zl(char* command, char* password = NULL){
	int errno = -10;

	if(password != NULL){
		strcat(command, " -p");

		if(password[0] != '\"' && password[strlen(password)-1] != '\"'){
			strcat(command, "\"");
			strcat(command, password);
			//strcat(command, "\"");//seems no need.
		}else{
			strcat(command, password);
		}


	}

	//cout << "=============================================" << endl;
	//cout << command << endl;
	errno = system(command);
	if(errno == 0){
		cout << endl << password <<  "errno:" << errno << " OK!" << endl;
	}else{
		//cout << endl << password << "errno:" << errno << endl;		
	}
	//cout << "=============================================" << endl;

	return errno;
}

int zt(char* command, char* password = NULL){
	int errno = -10;

	if(password != NULL){
		strcat(command, " -p");

		if(password[0] != '\"' && password[strlen(password)-1] != '\"'){
			strcat(command, "\"");
			strcat(command, password);
			//strcat(command, "\"");//seems no need.
		}else{
			strcat(command, password);
		}


	}

	//cout << "=============================================" << endl;
	//cout << command << endl;
	errno = system(command);
	if(errno == 0){
		cout << endl << password <<  "errno:" << errno << " OK!" << endl;
	}else{
		//cout << endl << password << "errno:" << errno << endl;		
	}
	//cout << "=============================================" << endl;

	return errno;
}

int zlDecrypt(char* path){

	cout<<"totalnumber:"<<totalnumber<<endl;

	char* command = (char*)malloc(MAX_PASSWORD_LENGTH*sizeof(char));
	memset(command, '\0', MAX_PASSWORD_LENGTH*sizeof(char));
	strcpy(command, "7z l ");
	strcat(command, path);


	char* commandPath = (char*)malloc(MAX_PASSWORD_LENGTH*sizeof(char));
	char* password = (char*)malloc(MAX_PASSWORD_LENGTH+3);
	for(int i = 0; i < totalnumber; i++){
		strcpy(commandPath, command);
		strcpy(password, dic[i]);
		if(zl(commandPath, password) == 0){
			return 0;
		}
	}

	free(commandPath);
	free(command);

	return -1;
}

int main(int argc, char** argv)
{
	cout<<"7z"<<endl;

//system("7z");//remember this bug!!!


	if(read() == 0){
		cout<<"read dict success."<<endl;
	}

	for(int i = 1; i < argc; i++){
		//cout<<argv[i]<<endl;
	}

	int errno = 0;

	int res = zlDecrypt("T:\\test\\allen.7z");
	
	cout<<res<<endl;

/*
	errno = zl("T:\\test\\all.7z", "a");
	errno = zl("T:\\test\\only.7z");
	errno = zl("T:\\test\\no.7z");*/
/*
	errno = zt("T:\\test\\all.7z", "a");
	errno = zt("T:\\test\\only.7z", "a");
	errno = zt("T:\\test\\no.7z", "a");*/



for(int i=0;i<totalnumber;i++){free((void *)dic[i]);}
free((void *)dic);
	return 0;
}