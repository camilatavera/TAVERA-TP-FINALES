/*
 * parser.h
 *
 *  Created on: Jun 26, 2021
 *      Author: caami
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);



#endif /* PARSER_H_ */
