/*
 * Copyright (c) 2003 Matteo Frigo
 * Copyright (c) 2003 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* $Id: solve.c,v 1.6 2003-05-15 23:09:07 athena Exp $ */

#include "dft.h"

/* use the apply() operation for DFT problems */
void X(dft_solve)(const plan *ego_, const problem *p_)
{
     const plan_dft *ego = (const plan_dft *) ego_;
     const problem_dft *p = (const problem_dft *) p_;
     ego->apply(ego_, 
		UNTAINT(p->ri), UNTAINT(p->ii), 
		UNTAINT(p->ro), UNTAINT(p->io));
}

void X(dftw_solve)(const plan *ego_, const problem *p_)
{
     const plan_dftw *ego = (const plan_dftw *) ego_;
     const problem_dftw *p = (const problem_dftw *) p_;
     ego->apply(ego_, UNTAINT(p->rio), UNTAINT(p->iio));
}
