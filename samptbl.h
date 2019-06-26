#ifndef SAMPTBL_H
#define SAMPTBL_H

#include "bstr.h"

#define SAMPACT_NONE	0	
#define SAMPACT_UPD	1	
#define SAMPACT_DEL	2	

typedef struct sample {
	int		sa_action;
	int		sa_idx;
	bstr_t		*sa_data;
} sample_t;

#define SAMPTBL_SIZ	100

#define SAMPTBL_MODE_INCR	0
#define SAMPTBL_MODE_RELOAD	1

int samptbl_init(int);
void samptbl_uninit(void);

int samptbl_add(int, const char *);
int samptbl_del(int);

int samptbl_convert(bstr_t **);


#endif

