/*
 * Copyright (C) 2018 ETH Zurich and University of Bologna
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Authors:
 */
#ifndef  __CPU_ISS_PULP_NN_HPP
#define __CPU_ISS_PULP_NN_HPP

#include "iss.hpp"

 #define PV_OP_RS_EXEC_NN(insn_name,lib_name)                                           \
 static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_int4_t_to_int32_t, REG_GET(0), REG_GET(1)));    \
   return insn->next;                                                                         \
 }                                                                                            \
                                                                                              \
 static inline iss_insn_t *pv_##insn_name##_sc_n_exec(iss_t *iss, iss_insn_t *insn)             \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_int4_t_to_int32_t, REG_GET(0), REG_GET(1))); \
   return insn->next;                                                                         \
 }                                                                                           \
                                                                                              \
 static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_int2_t_to_int32_t, REG_GET(0), REG_GET(1)));    \
   return insn->next;                                                                         \
 }                                                                                            \
                                                                                              \
 static inline iss_insn_t *pv_##insn_name##_sc_c_exec(iss_t *iss, iss_insn_t *insn)             \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_int2_t_to_int32_t, REG_GET(0), REG_GET(1))); \
   return insn->next;                                                                         \
 }


 #define PV_OP_RU_EXEC_NN(insn_name,lib_name)                                           \
 static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_uint4_t_to_uint32_t, REG_GET(0), REG_GET(1)));    \
   return insn->next;                                                                         \
 }                                                                                            \
                                                                                              \
 static inline iss_insn_t *pv_##insn_name##_sc_n_exec(iss_t *iss, iss_insn_t *insn)             \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_uint4_t_to_uint32_t, REG_GET(0), REG_GET(1))); \
   return insn->next;                                                                         \
 }                                                                                           \
                                                                                               \
 static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_uint2_t_to_uint32_t, REG_GET(0), REG_GET(1)));    \
   return insn->next;                                                                         \
 }                                                                                            \
                                                                                              \
 static inline iss_insn_t *pv_##insn_name##_sc_c_exec(iss_t *iss, iss_insn_t *insn)             \
 {                                                                                            \
   REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_uint2_t_to_uint32_t, REG_GET(0), REG_GET(1))); \
   return insn->next;                                                                         \
 }


 PV_OP_RS_EXEC_NN(add,ADD)
 PV_OP_RS_EXEC_NN(sub,SUB)
 PV_OP_RS_EXEC_NN(avg,AVG)
 PV_OP_RU_EXEC_NN(avgu,AVGU)
 PV_OP_RS_EXEC_NN(max,MAX)
 PV_OP_RU_EXEC_NN(maxu,MAXU)
 PV_OP_RS_EXEC_NN(min,MIN)
 PV_OP_RU_EXEC_NN(minu,MINU)

 PV_OP_RU_EXEC_NN(srl,SRL)

 PV_OP_RS_EXEC_NN(sra,SRA)

 PV_OP_RU_EXEC_NN(sll,SLL)

 PV_OP_RS_EXEC_NN(or,OR)

 PV_OP_RS_EXEC_NN(xor,XOR)

 PV_OP_RS_EXEC_NN(and,AND)

 #define PV_OP1_RS_EXEC_NN(insn_name,lib_name)                          \
 static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)      \
 {                                                                                  \
   REG_SET(0, LIB_CALL1(lib_VEC_##lib_name##_int4_t_to_int32_t, REG_GET(0)));    \
   return insn->next;                                                               \
 }                                                                                  \
                                                                                    \
 static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)      \
 {                                                                                  \
   REG_SET(0, LIB_CALL1(lib_VEC_##lib_name##_int2_t_to_int32_t, REG_GET(0)));    \
   return insn->next;                                                               \
 }



 PV_OP1_RS_EXEC_NN(abs,ABS)


  #define PV_OP_RS_EXEC_NN_2(insn_name,lib_name)                                           \
  static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_4, REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_n_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_4, REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_2, REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_c_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_2, REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }

  #define PV_OP_RU_EXEC_NN_2(insn_name,lib_name)                                           \
  static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_4, REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_n_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_4, REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }\
                                                                                                 \
  static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_2, REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_c_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL2(lib_VEC_##lib_name##_SC_2, REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }

  PV_OP_RS_EXEC_NN_2(dotsp,DOTSP)

  PV_OP_RU_EXEC_NN_2(dotup,DOTUP)

  PV_OP_RS_EXEC_NN_2(dotusp,DOTUSP)


  #define PV_OP_RRS_EXEC_NN_2(insn_name,lib_name)                                           \
  static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_4, REG_GET(2), REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_n_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_SC_4, REG_GET(2), REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }                                                                                            \
  static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_2, REG_GET(2), REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_c_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_SC_2, REG_GET(2), REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }

  PV_OP_RRS_EXEC_NN_2(sdotsp,SDOTSP)
  PV_OP_RRS_EXEC_NN_2(sdotusp,SDOTUSP)

  #define PV_OP_RRU_EXEC_NN_2(insn_name,lib_name)                                           \
  static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_4, REG_GET(2), REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_n_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_SC_4, REG_GET(2), REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  } \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_2, REG_GET(2), REG_GET(0), REG_GET(1)));    \
    return insn->next;                                                                         \
  }                                                                                            \
                                                                                               \
  static inline iss_insn_t *pv_##insn_name##_c_sc_exec(iss_t *iss, iss_insn_t *insn)             \
  {                                                                                            \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_SC_2, REG_GET(2), REG_GET(0), REG_GET(1))); \
    return insn->next;                                                                         \
  }

PV_OP_RRU_EXEC_NN_2(sdotup,SDOTUP)

/* mac&load */
  #define PV_OP_RRRU3_EXEC_NN(insn_name,lib_name)                                                                         \
  static inline void pv_##insn_name##_h_resume(iss_t *iss)                                       \
  {                                                                                                                     \
  }                                                                                                                     \
  static inline void pv_##insn_name##_b_resume(iss_t *iss)                                       \
  {                                                                                                                     \
  }                                                                                                                     \
  static inline void pv_##insn_name##_n_resume(iss_t *iss)                                       \
  {                                                                                                                     \
  }                                                                                                                     \
  static inline void pv_##insn_name##_c_resume(iss_t *iss)                                       \
  {                                                                                                                     \
  }                                                                                                                     \
  static inline iss_insn_t *pv_##insn_name##_h_exec(iss_t *iss, iss_insn_t *insn)                                       \
  {                                                                                                                     \
    iss_uim_t *ctl_imm = (iss_uim_t *)insn->uim;                                                                         \
                                                                                                                        \
    int ac_addr = ctl_imm[0];                                                                                           \
    int wt_addr = (ctl_imm[1] | (ctl_imm[2] << 1)) + 0x2;                                                               \
    bool ac_update = ctl_imm[3];                                                                                        \
    bool wt_update = ctl_imm[4];                                                                                        \
                                                                                                                        \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_16, REG_GET(1), SPR_GET(ac_addr), SPR_GET(wt_addr)));                     \
                                                                                                                        \
    iss_reg_t addr = REG_GET(0);                                                                                       \
    if(ac_update)                                                                                                       \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[ac_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", ac_addr, SPR_GET(ac_addr));   \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_h_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else if (wt_update)                                                                                                 \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[wt_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", wt_addr, SPR_GET(wt_addr)); \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_h_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else                                                                                                                \
    {                                                                                                                   \
    }                                                                                                                   \
    return insn->next;                                                                                                  \
  }                                                                                                                     \
  static inline iss_insn_t *pv_##insn_name##_b_exec(iss_t *iss, iss_insn_t *insn)                                       \
  {                                                                                                                     \
    iss_uim_t *ctl_imm = (iss_uim_t *)insn->uim;                                                                         \
                                                                                                                        \
    int ac_addr = ctl_imm[0];                                                                                           \
    int wt_addr = (ctl_imm[1] | (ctl_imm[2] << 1)) + 0x2;                                                               \
    bool ac_update = ctl_imm[3];                                                                                        \
    bool wt_update = ctl_imm[4];                                                                                        \
                                                                                                                        \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_8, REG_GET(1), SPR_GET(ac_addr), SPR_GET(wt_addr)));                     \
                                                                                                                        \
    iss_reg_t addr = REG_GET(0);                                                                                       \
    if(ac_update)                                                                                                       \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[ac_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", ac_addr, SPR_GET(ac_addr));   \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_b_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else if (wt_update)                                                                                                 \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[wt_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", wt_addr, SPR_GET(wt_addr)); \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_b_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else                                                                                                                \
    {                                                                                                                   \
    }                                                                                                                   \
    return insn->next;                                                                                                  \
  }                                                                                                                     \
  static inline iss_insn_t *pv_##insn_name##_n_exec(iss_t *iss, iss_insn_t *insn)                                       \
  {                                                                                                                     \
    iss_uim_t *ctl_imm = (iss_uim_t *)insn->uim;                                                                         \
                                                                                                                        \
    int ac_addr = ctl_imm[0];                                                                                           \
    int wt_addr = (ctl_imm[1] | (ctl_imm[2] << 1)) + 0x2;                                                               \
    bool ac_update = ctl_imm[3];                                                                                        \
    bool wt_update = ctl_imm[4];                                                                                        \
                                                                                                                        \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_4, REG_GET(1), SPR_GET(ac_addr), SPR_GET(wt_addr)));                     \
                                                                                                                        \
    iss_reg_t addr = REG_GET(0);                                                                                       \
    if(ac_update)                                                                                                       \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[ac_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", ac_addr, SPR_GET(ac_addr));   \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_n_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else if (wt_update)                                                                                                 \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[wt_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", wt_addr, SPR_GET(wt_addr)); \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_n_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else                                                                                                                \
    {                                                                                                                   \
    }                                                                                                                   \
    return insn->next;                                                                                                  \
  }                                                                                                                     \
  static inline iss_insn_t *pv_##insn_name##_c_exec(iss_t *iss, iss_insn_t *insn)                                       \
  {                                                                                                                     \
    iss_uim_t *ctl_imm = (iss_uim_t *)insn->uim;                                                                         \
                                                                                                                        \
    int ac_addr = ctl_imm[0];                                                                                           \
    int wt_addr = (ctl_imm[1] | (ctl_imm[2] << 1)) + 0x2;                                                               \
    bool ac_update = ctl_imm[3];                                                                                        \
    bool wt_update = ctl_imm[4];                                                                                        \
                                                                                                                        \
    REG_SET(0, LIB_CALL3(lib_VEC_##lib_name##_2, REG_GET(1), SPR_GET(ac_addr), SPR_GET(wt_addr)));                     \
                                                                                                                        \
    iss_reg_t addr = REG_GET(0);                                                                                       \
    if(ac_update)                                                                                                       \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[ac_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", ac_addr, SPR_GET(ac_addr));   \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_c_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else if (wt_update)                                                                                                 \
    {                                                                                                                   \
      if (!iss->data_req(addr, (uint8_t *)&iss->cpu.pulp_nn.spr_ml[wt_addr], 4, false))                             \
      {                                                                                                                 \
        iss_csr_msg(iss, "Loaded new value (spr_loc: 0x%x, value: 0x%x)\n", wt_addr, SPR_GET(wt_addr)); \
      }                                                                                                                 \
      else                                                                                                              \
      {                                                                                                                 \
        iss->cpu.state.stall_callback = pv_##insn_name##_c_resume;                                                      \
        iss->cpu.pulp_nn.ml_insn = insn;                                                                               \
        iss_exec_insn_stall(iss);                                                                                       \
      }                                                                                                                 \
    }                                                                                                                   \
    else                                                                                                                \
    {                                                                                                                   \
    }                                                                                                                   \
    return insn->next;                                                                                                  \
  }                                                                                                                     \

  PV_OP_RRRU3_EXEC_NN(mlsdotup,SDOTUP)
  PV_OP_RRRU3_EXEC_NN(mlsdotusp,SDOTUSP)
  PV_OP_RRRU3_EXEC_NN(mlsdotsp,SDOTSP)

/* end mac&load */


static inline void qnt_step_resume(iss_t *iss)
{
}

static inline iss_insn_t *qnt_step(iss_t *iss, iss_insn_t *insn, iss_reg_t input, iss_addr_t addr, int reg)
{
  iss_addr_t qnt_addr = addr;// + 4 * iss->cpu.pulp_nn.qnt_step;
  uint8_t *data = (uint8_t *)&iss->cpu.pulp_nn.qnt_regs[iss->cpu.pulp_nn.qnt_step];
  iss->cpu.pulp_nn.addr_reg = qnt_addr;
  //int16_t data;
  if(iss->cpu.pulp_nn.qnt_step==0)
  {
    iss->cpu.pulp_nn.qnt_step++;
    return insn;
  }
  if(iss->cpu.pulp_nn.qnt_step==1)
  {
    //printf("here1\n" );
    //iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false);
    if (!iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false))
    {
      //printf("qnt_add: %X\n",iss->cpu.pulp_nn.addr_reg );
      //printf("data: %d\n", *((int16_t*)data) );
      if (input <= *((int16_t*)data))
      {
        //printf("here21\n" );
        iss->cpu.pulp_nn.qnt_reg_out = 0x1;
        iss->cpu.pulp_nn.addr_reg = iss->cpu.pulp_nn.addr_reg - 4 * 2;
      }
      else
      {
        //printf("here22\n" );
        iss->cpu.pulp_nn.qnt_reg_out = 0x0;
        iss->cpu.pulp_nn.addr_reg = iss->cpu.pulp_nn.addr_reg + 4 * 2;
      }
      //printf("here3\n" );
      iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out <<1;
      //printf("out: %X\n", iss->cpu.pulp_nn.qnt_reg_out);

      iss->cpu.pulp_nn.qnt_step++;
      return insn;
    }
    else
    {
      iss->cpu.state.stall_callback = qnt_step_resume;
      iss->cpu.state.stall_reg = reg;
      iss_exec_insn_stall(iss);
    }
  }

  if (iss->cpu.pulp_nn.qnt_step==2)
  {
    //printf("qnt2,here1\n");
    if(!iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false))
    {
      //printf("qnt_add: %X\n",iss->cpu.pulp_nn.addr_reg );
      //printf("data: %d\n", *((int16_t*)data) );
      if(input > *((int16_t*) data))
      {
        //printf("qnt2,here21\n");
        iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out | 0x1;
        iss->cpu.pulp_nn.addr_reg = iss->cpu.pulp_nn.addr_reg + 2 * 2;
      }
      else
      {
        //printf("qnt2,here22\n");
        iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out | 0x0;
        iss->cpu.pulp_nn.addr_reg = iss->cpu.pulp_nn.addr_reg - 2 * 2;
      }
      //printf("qnt2,here3\n");
      iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out <<1;
      //printf("out: %X\n", iss->cpu.pulp_nn.qnt_reg_out);
      iss->cpu.pulp_nn.qnt_step++;
      return insn;
    }
    else
    {
      iss->cpu.state.stall_callback = qnt_step_resume;
      iss->cpu.state.stall_reg = reg;
      iss_exec_insn_stall(iss);
    }

  }


  if (iss->cpu.pulp_nn.qnt_step==3)
  {
    //printf("qnt3,here1\n");
    if(!iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false))
    //iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false);
    {
      //printf("qnt_add: %X\n",iss->cpu.pulp_nn.addr_reg );
      //printf("data: %d\n", *((int16_t*)data) );
      if(input > *((int16_t*) data))
      {
        //printf("qnt3,here21\n");
        iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out | 0x1;
        iss->cpu.pulp_nn.addr_reg = iss->cpu.pulp_nn.addr_reg + 1 * 2;
      }
      else
      {
        //printf("qnt3,here22\n");
        iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out | 0x0;
        iss->cpu.pulp_nn.addr_reg = iss->cpu.pulp_nn.addr_reg - 1 * 2;
      }
      //printf("qnt3,here3\n");
      iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out <<1;
      //printf("out: %X\n", iss->cpu.pulp_nn.qnt_reg_out);
      iss->cpu.pulp_nn.qnt_step++;
      return insn;
    }
    else
    {
      iss->cpu.state.stall_callback = qnt_step_resume;
      iss->cpu.state.stall_reg = reg;
      iss_exec_insn_stall(iss);
    }
  }

  if(iss->cpu.pulp_nn.qnt_step==4)
  {
    //printf("qnt4,here1\n");
    if(!iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false))
    //iss->data_req(iss->cpu.pulp_nn.addr_reg, data, 2, false);
    {
      //printf("qnt_add: %X\n",iss->cpu.pulp_nn.addr_reg );
      //printf("data: %d\n", *((int16_t*)data) );
      if(input > *((int16_t*) data))
      {
        //printf("qnt4,here21\n");
        iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out | 0x1;
      }
      else
      {
        //printf("qnt4,here22\n");
        iss->cpu.pulp_nn.qnt_reg_out = iss->cpu.pulp_nn.qnt_reg_out | 0x0;
      }
      //printf("qnt4,here3\n");
      iss->cpu.pulp_nn.qnt_step = 0;
      //printf("out: %X\n", iss->cpu.pulp_nn.qnt_reg_out);
      iss->cpu.pulp_nn.qnt_reg_out = (iss->cpu.pulp_nn.qnt_reg_out & 0x08) ? (iss->cpu.pulp_nn.qnt_reg_out | 0xFFFFFFF0) : (iss->cpu.pulp_nn.qnt_reg_out & 0x0000000F);
      //printf("out: %X\n", iss->cpu.pulp_nn.qnt_reg_out);
      REG_SET(0, iss->cpu.pulp_nn.qnt_reg_out);
      iss->cpu.state.insn_cycles = 2;
      return insn-> next;
    }
    else
    {
      iss->cpu.state.stall_callback = qnt_step_resume;
      iss->cpu.state.stall_reg = reg;
      iss_exec_insn_stall(iss);
    }
  }

}



  // if (!iss->data_req(qnt_addr, data, 4, false))
  // {
  //   if (iss->cpu.pulp_nn.qnt_step == 3)
  //     REG_SET(0, lib_VEC_QNT_4(&iss->cpu.state, input, (uint16_t *)iss->cpu.pulp_nn.qnt_regs));
  // }
  // else
  // {
  //   iss->cpu.state.stall_callback = qnt_step_resume;
  //   iss->cpu.state.stall_reg = reg;
  //   iss_exec_insn_stall(iss);
  // }

  // iss->cpu.pulp_nn.qnt_step++;
  // if (iss->cpu.pulp_nn.qnt_step == 4)
  // {
  //   iss->cpu.pulp_nn.qnt_step = 0;
  //   // Add 1 more cycle to model the fact that the first comparison is done the cycle after the first
  //   // load so the nstruction should take at best 5 cycles
  //   iss->cpu.state.insn_cycles = 2;
  //   return insn->next;
  // }
  // else
  // {
  //   return insn;
  // }
//}

static inline iss_insn_t *pv_qnt_n_exec(iss_t *iss, iss_insn_t *insn)
{
  return qnt_step(iss, insn, REG_GET(0), REG_GET(1), REG_OUT(0));
}

static inline void iss_pulp_nn_init(iss_t *iss)
{
  iss->cpu.pulp_nn.qnt_step = 0;
}



#endif
