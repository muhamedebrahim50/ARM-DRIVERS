/*
 * dataTypes.h
 *
 * Created: 8/18/2021 9:54:15 PM
 *  Author: Ehab Abdo
 */ 


#ifndef DATATYPES_H_
#define DATATYPES_H_

typedef unsigned char 		 u8;
typedef signed char 		 s8;
typedef unsigned short int 	 u16;
typedef signed short int 	 s16;
typedef unsigned long int	 u32;
typedef signed long int		 s32;
typedef float				 f32;
typedef double				 f64;
typedef long double			 f128;

#define STD_TYPE_OK		1
#define STD_TYPE_NOK	0
#define STD_TYPES_OK	1
#define STD_TYPES_NOK	0

#define	Enable			1
#define Disable			0


#define NULL                   ((void*)0)
typedef enum{FALSE,TRUE}BOOL;





#endif /* DATATYPES_H_ */
