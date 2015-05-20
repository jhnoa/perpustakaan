#ifndef T_MURID_H
#define T_MURID_H

#include "lib.h"

const int TMSIZE = 46;

class t_murid
{
	string email;
	public:
		t_murid();
		~t_murid();
	protected:
		void tambahmurid();
		int isemail();
};

#endif
