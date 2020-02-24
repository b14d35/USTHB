#include "../Headers/indentation.h"

int indent_depth(char *str){
	int i,t=0;
	for(i=0;i<strlen(str);i++){
		if(str[i] == '\t') t+=IND;
		else t++;
	}
	return t;
}

int what_ind(int taille){
	if(taille>level){
		if(taille-IND == level){
			return 1;
		}else{
			return -1;
		}
	}else if(taille == level){
		return 0;
	}else{
		if(taille%IND == 0){
			return -2;
		}else{
			return -1;
		}
	}
}
