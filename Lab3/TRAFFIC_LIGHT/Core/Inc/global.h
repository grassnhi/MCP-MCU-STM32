/*
 * global.h
 *
 *  Created on: Oct 22, 2023
 *      Author: PC
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT				0
#define MODE1				1
#define MODE2				2
#define MODE3				3
#define MODE4				4

#define AUTO_RED1_GREEN2	11
#define AUTO_RED1_AMBER2	12
#define AUTO_GREEN1_RED2	13
#define	AUTO_AMBER1_RED2	14

#define AUTO_RED			21
#define ADJ_RED				22

#define AUTO_AMBER			31
#define ADJ_AMBER			32

#define AUTO_GREEN			41
#define ADJ_GREEN			42

extern int status;

extern int RED;
extern int AMBER;
extern int GREEN;

#endif /* INC_GLOBAL_H_ */
