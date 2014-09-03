/* j/1/div.c
**
** This file is in the public domain.
*/
#include "all.h"
#include "../pit.h"

/* functions
*/
  u2_weak                                                         //  transfer
  u2_cqa_div(u2_atom a,                                     //  retain
                   u2_atom b)                                     //  retain
  {
    if ( 0 == b ) {
      return u2_cm_bail(c3__exit);
    }
    else {
      if ( u2_so(u2_co_is_cat(a)) && u2_so(u2_co_is_cat(b)) ) {
        return a / b;
      }
      else {
        mpz_t a_mp, b_mp;

        u2_cr_mp(a_mp, a);
        u2_cr_mp(b_mp, b);

        mpz_tdiv_q(a_mp, a_mp, b_mp);
        mpz_clear(b_mp);

        return u2_ci_mp(a_mp);
      }
    }
  }
  u2_weak                                                         //  transfer
  u2_cwa_div(u2_noun cor)                                    //  retain
  {
    u2_noun a, b;

    if ( (u2_no == u2_cr_mean(cor, u2_cv_sam_2, &a, u2_cv_sam_3, &b, 0)) ||
         (u2_no == u2ud(a)) ||
         (u2_no == u2ud(b)) )
    {
      return u2_cm_bail(c3__exit);
    } else {
      return u2_cqa_div(a, b);
    }
  }
