#include <errno.h>
#include "samptbl.h"

static sample_t	samples[SAMPTBL_SIZ];

static int samptbl_inited = 0;


int
samptbl_init(int mode)
{
	int	i;

	memset(samples, 0, sizeof(sample_t) * SAMPTBL_SIZ);

	for(i = 0; i < SAMPTBL_SIZ; ++i) {

		if(mode == SAMPTBL_MODE_RELOAD)
			samples[i].sa_action = SAMPACT_DEL;
		else
			samples[i].sa_action = SAMPACT_NONE;

	}

	++samptbl_inited;

	return 0;
}


void
samptbl_uninit(void)
{
	int	i;

	if(!samptbl_inited)
		return;

	for(i = 0; i < SAMPTBL_SIZ; ++i) {
		buninit(&samples[i].sa_data);
	}

	memset(samples, 0, sizeof(sample_t) * SAMPTBL_SIZ);
}


int
samptbl_del(int idx)
{
	if(idx < 0 || idx >= SAMPTBL_SIZ)
		return EINVAL;

	if(!samptbl_inited)
		return ENOEXEC;

	samples[idx].sa_action = SAMPACT_DEL;

	return 0;
}
