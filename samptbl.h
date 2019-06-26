#ifndef SAMPTBL_H
#define SAMPTBL_H

#include "bstr.h"

#define SAMPACT_NONE	0	
#define SAMPACT_UPD	1	
#define SAMPACT_DEL	2	

typedef struct sample {
	int		*sa_action;
	int		*sa_idx;
	bstr_t		*sa_data;
} sample_t;

#define SAMPTBL_SIZ	100


int samptbl_init(int);
int samptbl_add(int, const char *);
int samptbl_del(int);
int samptbl_uninit();



#endif

