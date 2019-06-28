#include <errno.h>
#include "samptbl.h"
#include "korg_syro_volcasample.h"

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


int
samptbl_convert(bstr_t **out)
{
	int		err;
	int		i;
	sample_t	*sa;
	SyroData	sd;
	barr_t		*syrodatas;

	err = 0;
	syrodatas = NULL;

	syrodatas = barr_init(sizeof(SyroData));
	if(syrodatas == NULL) {
		err = ENOMEM;
		goto end_label;
	}

	for(i = 0; i < SAMPTBL_SIZ; ++i) {
		sa = &samples[i];

		memset(&sd, 0, sizeof(SyroData));

		if(sa->sa_action == SAMPACT_NONE) {
			continue;
		} else
		if(sa->sa_action == SAMPACT_DEL) {
			sd.DataType = DataType_Sample_Erase;
			sd.Number = i;
			barr_add(syrodatas, &sd);
		}
	}

	if(barr_cnt(syrodatas) == 0) {
		err = ENOENT;
		goto end_label;
	}

	


	
end_label:

	if(syrodatas != NULL)
		barr_uninit(&syrodatas);
	

	return 0;
}


