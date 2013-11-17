//
//  json_parser.c
//  Pong
//
//  Created by Steven Gleed on 02/09/2013.
//  Copyright (c) 2013 Steven Gleed. All rights reserved.
//

#include <stdio.h>
#include "json_parser.h"

//json_type get_json_type(const json_object *o) {
//	return json_type_boolean;
//}

char* read_file(char* filename)
{
	FILE* file = fopen(filename,"r");
	if(file == NULL)
		return NULL;
	
	fseek(file, 0, SEEK_END);
	long int size = ftell(file);
	rewind(file);
	
	char* content = calloc(size + 1, 1);
	
	fread(content,1,size,file);
	
	return content;
}