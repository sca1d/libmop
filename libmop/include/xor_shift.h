#pragma once
#include "deflate/define.h"

#ifndef INC_MOP_XOR_SHIFT_H
#define INC_MOP_XOR_SHIFT_H

#define XS_SRAND		init_xorShift
#define XS_RAND			xorShift
#define XS_RAND_MAX		0x7FFF

/**
* @def
* @brief �ő�l�ƍŏ��l�����߂ė����𔭐������܂��B
* @param LO �ŏ��l
* @param HI �ő�l
*/
#define XSR_RAND(LO, HI)	(XS_RAND() * (HI - LO + 1.0) / (1.0 + XS_RAND_MAX))
/**
* @def
* @brief �ő�l�����߂ė����𔭐������܂��B
* @param HI �ő�l
*/
#define XSM_RAND(HI)		(XS_RAND() * (HI + 1.0) / (1.0 + XS_RAND_MAX))

DLL_EXPORT unsigned int xorShift(void);
DLL_EXPORT double xorShiftDouble(void);
DLL_EXPORT void init_xorShift(unsigned int s);

#endif
