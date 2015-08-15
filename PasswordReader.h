#include<iostream>
using namespace std;


const int MAX_PASSWORD_LENGTH = 1024;
const int MAX_PASSWORD_NUMBER = 1024;
extern char ** dic/*[MAX_PASSWORD_NUMBER][MAX_PASSWORD_LENGTH]*/;
extern int totalnumber;
int read();
