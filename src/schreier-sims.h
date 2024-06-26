/*******************************************************************************
**
*A  schreier-sims.h        A rudimentary Schreier-Sims        Julius Jonusas
**                                                            James Mitchell
**                                                            Wilf A. Wilson
**                                                            Michael Young
**
**  Copyright (C) 2014-15 - Julius Jonusas, James Mitchell, Wilf A. Wilson,
**  Michael Young
**
**  This file is free software, see the digraphs/LICENSE.
**
*******************************************************************************/

#ifndef DIGRAPHS_SRC_SCHREIER_SIMS_H_
#define DIGRAPHS_SRC_SCHREIER_SIMS_H_

// C headers
#include <stdbool.h>  // for bool
#include <stdint.h>   // for uint16_t

// Digraphs headers
#include "perms.h"  // for Perm, PermColl

extern uint16_t PERM_DEGREE;

struct schreier_sims_struct {
  uint16_t   degree;
  PermColl** strong_gens;  // strong generators
  Perm*      transversal;
  Perm*      inversal;
  bool*      orb_lookup;
  uint16_t*  orbits;
  uint16_t*  size_orbits;
  uint16_t*  base;
  Perm       tmp_perm;
  uint16_t   size_base;
};

typedef struct schreier_sims_struct SchreierSims;

SchreierSims* new_schreier_sims(void);
void          free_schreier_sims(SchreierSims* ss);

// Store the stabiliser of pt in the group generated by src, in dst, use ss to
// hold the stabiliser chain.
void point_stabilizer(SchreierSims*  ss,
                      PermColl*      src,
                      PermColl*      dst,
                      uint16_t const pt);

#endif  // DIGRAPHS_SRC_SCHREIER_SIMS_H_
