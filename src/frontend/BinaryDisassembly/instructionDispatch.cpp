#include "rose.h"
#include <stdint.h>
SgAsmx86Instruction* createx86Instruction(uint64_t address, const std::string& mnemonic) {
  SgAsmx86Instruction* insn = new SgAsmx86Instruction(address, mnemonic, x86_unknown_instruction);
  switch (mnemonic.size()) {
    case 2:
      switch (mnemonic[0]) {
        case 'b': { // 'b'
          if (mnemonic[1] == 't') { // 'bt'
            insn->set_kind(x86_bt);
          }
        break;}
        case 'i': { // 'i'
          if (mnemonic[1] == 'n') { // 'in'
            insn->set_kind(x86_in);
          }
        break;}
        case 'j': { // 'j'
          switch (mnemonic[1]) {
            case 'a': { // 'ja'
              insn->set_kind(x86_ja);
            break;}
            case 'b': { // 'jb'
              insn->set_kind(x86_jb);
            break;}
            case 'c': { // 'jc'
              insn->set_kind(x86_jb);
            break;}
            case 'e': { // 'je'
              insn->set_kind(x86_je);
            break;}
            case 'g': { // 'jg'
              insn->set_kind(x86_jg);
            break;}
            case 'l': { // 'jl'
              insn->set_kind(x86_jl);
            break;}
            case 'o': { // 'jo'
              insn->set_kind(x86_jo);
            break;}
            case 'p': { // 'jp'
              insn->set_kind(x86_jpe);
            break;}
            case 's': { // 'js'
              insn->set_kind(x86_js);
            break;}
            case 'z': { // 'jz'
              insn->set_kind(x86_je);
            break;}
            default: break;
          }
        break;}
        case 'o': { // 'o'
          if (mnemonic[1] == 'r') { // 'or'
            insn->set_kind(x86_or);
          }
        break;}
        default: break;
      }
    break;
    case 3:
      switch (mnemonic[0]) {
        case 'a': { // 'a'
          switch (mnemonic[1]) {
            case 'a': { // 'aa'
              switch (mnemonic[2]) {
                case 'a': { // 'aaa'
                  insn->set_kind(x86_aaa);
                break;}
                case 'd': { // 'aad'
                  insn->set_kind(x86_aad);
                break;}
                case 'm': { // 'aam'
                  insn->set_kind(x86_aam);
                break;}
                case 's': { // 'aas'
                  insn->set_kind(x86_aas);
                break;}
                default: break;
              }
            break;}
            case 'd': { // 'ad'
              switch (mnemonic[2]) {
                case 'c': { // 'adc'
                  insn->set_kind(x86_adc);
                break;}
                case 'd': { // 'add'
                  insn->set_kind(x86_add);
                break;}
                default: break;
              }
            break;}
            case 'n': { // 'an'
              if (mnemonic[2] == 'd') { // 'and'
                insn->set_kind(x86_and);
              }
            break;}
            default: break;
          }
        break;}
        case 'b': { // 'b'
          switch (mnemonic[1]) {
            case 's': { // 'bs'
              switch (mnemonic[2]) {
                case 'f': { // 'bsf'
                  insn->set_kind(x86_bsf);
                break;}
                case 'r': { // 'bsr'
                  insn->set_kind(x86_bsr);
                break;}
                default: break;
              }
            break;}
            case 't': { // 'bt'
              switch (mnemonic[2]) {
                case 'c': { // 'btc'
                  insn->set_kind(x86_btc);
                break;}
                case 'l': { // 'btl'
                  insn->set_kind(x86_bt);
                break;}
                case 'r': { // 'btr'
                  insn->set_kind(x86_btr);
                break;}
                case 's': { // 'bts'
                  insn->set_kind(x86_bts);
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 'c': { // 'c'
          switch (mnemonic[1]) {
            case 'b': { // 'cb'
              if (mnemonic[2] == 'w') { // 'cbw'
                insn->set_kind(x86_cbw);
              }
            break;}
            case 'd': { // 'cd'
              if (mnemonic[2] == 'q') { // 'cdq'
                insn->set_kind(x86_cdq);
              }
            break;}
            case 'l': { // 'cl'
              switch (mnemonic[2]) {
                case 'c': { // 'clc'
                  insn->set_kind(x86_clc);
                break;}
                case 'd': { // 'cld'
                  insn->set_kind(x86_cld);
                break;}
                case 'i': { // 'cli'
                  insn->set_kind(x86_cli);
                break;}
                default: break;
              }
            break;}
            case 'm': { // 'cm'
              switch (mnemonic[2]) {
                case 'c': { // 'cmc'
                  insn->set_kind(x86_cmc);
                break;}
                case 'p': { // 'cmp'
                  insn->set_kind(x86_cmp);
                break;}
                default: break;
              }
            break;}
            case 'q': { // 'cq'
              if (mnemonic[2] == 'o') { // 'cqo'
                insn->set_kind(x86_cqo);
              }
            break;}
            case 'w': { // 'cw'
              if (mnemonic[2] == 'd') { // 'cwd'
                insn->set_kind(x86_cwd);
              }
            break;}
            default: break;
          }
        break;}
        case 'd': { // 'd'
          switch (mnemonic[1]) {
            case 'a': { // 'da'
              switch (mnemonic[2]) {
                case 'a': { // 'daa'
                  insn->set_kind(x86_daa);
                break;}
                case 's': { // 'das'
                  insn->set_kind(x86_das);
                break;}
                default: break;
              }
            break;}
            case 'e': { // 'de'
              if (mnemonic[2] == 'c') { // 'dec'
                insn->set_kind(x86_dec);
              }
            break;}
            case 'i': { // 'di'
              if (mnemonic[2] == 'v') { // 'div'
                insn->set_kind(x86_div);
              }
            break;}
            default: break;
          }
        break;}
        case 'e': { // 'e'
          if (mnemonic[1] == 's') { // 'es'
            if (mnemonic[2] == 'c') { // 'esc'
              insn->set_kind(x86_esc);
            }
          }
        break;}
        case 'f': { // 'f'
          switch (mnemonic[1]) {
            case 'l': { // 'fl'
              if (mnemonic[2] == 'd') { // 'fld'
                insn->set_kind(x86_fld);
              }
            break;}
            case 's': { // 'fs'
              if (mnemonic[2] == 't') { // 'fst'
                insn->set_kind(x86_fst);
              }
            break;}
            default: break;
          }
        break;}
        case 'h': { // 'h'
          if (mnemonic[1] == 'l') { // 'hl'
            if (mnemonic[2] == 't') { // 'hlt'
              insn->set_kind(x86_hlt);
            }
          }
        break;}
        case 'i': { // 'i'
          if (mnemonic[1] == 'n') { // 'in'
            switch (mnemonic[2]) {
              case 'b': { // 'inb'
                insn->set_kind(x86_in);
              break;}
              case 'c': { // 'inc'
                insn->set_kind(x86_inc);
              break;}
              case 'd': { // 'ind'
                insn->set_kind(x86_in);
              break;}
              case 'l': { // 'inl'
                insn->set_kind(x86_in);
              break;}
              case 't': { // 'int'
                insn->set_kind(x86_int);
              break;}
              case 'w': { // 'inw'
                insn->set_kind(x86_in);
              break;}
              default: break;
            }
          }
        break;}
        case 'j': { // 'j'
          switch (mnemonic[1]) {
            case 'a': { // 'ja'
              if (mnemonic[2] == 'e') { // 'jae'
                insn->set_kind(x86_jae);
              }
            break;}
            case 'b': { // 'jb'
              if (mnemonic[2] == 'e') { // 'jbe'
                insn->set_kind(x86_jbe);
              }
            break;}
            case 'g': { // 'jg'
              if (mnemonic[2] == 'e') { // 'jge'
                insn->set_kind(x86_jge);
              }
            break;}
            case 'l': { // 'jl'
              if (mnemonic[2] == 'e') { // 'jle'
                insn->set_kind(x86_jle);
              }
            break;}
            case 'm': { // 'jm'
              if (mnemonic[2] == 'p') { // 'jmp'
                insn->set_kind(x86_jmp);
              }
            break;}
            case 'n': { // 'jn'
              switch (mnemonic[2]) {
                case 'a': { // 'jna'
                  insn->set_kind(x86_jbe);
                break;}
                case 'b': { // 'jnb'
                  insn->set_kind(x86_jae);
                break;}
                case 'c': { // 'jnc'
                  insn->set_kind(x86_jae);
                break;}
                case 'e': { // 'jne'
                  insn->set_kind(x86_jne);
                break;}
                case 'g': { // 'jng'
                  insn->set_kind(x86_jle);
                break;}
                case 'l': { // 'jnl'
                  insn->set_kind(x86_jge);
                break;}
                case 'o': { // 'jno'
                  insn->set_kind(x86_jno);
                break;}
                case 'p': { // 'jnp'
                  insn->set_kind(x86_jpo);
                break;}
                case 's': { // 'jns'
                  insn->set_kind(x86_jns);
                break;}
                case 'z': { // 'jnz'
                  insn->set_kind(x86_jne);
                break;}
                default: break;
              }
            break;}
            case 'p': { // 'jp'
              switch (mnemonic[2]) {
                case 'e': { // 'jpe'
                  insn->set_kind(x86_jpe);
                break;}
                case 'o': { // 'jpo'
                  insn->set_kind(x86_jpo);
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 'l': { // 'l'
          switch (mnemonic[1]) {
            case 'd': { // 'ld'
              if (mnemonic[2] == 's') { // 'lds'
                insn->set_kind(x86_lds);
              }
            break;}
            case 'e': { // 'le'
              switch (mnemonic[2]) {
                case 'a': { // 'lea'
                  insn->set_kind(x86_lea);
                break;}
                case 's': { // 'les'
                  insn->set_kind(x86_les);
                break;}
                default: break;
              }
            break;}
            case 'f': { // 'lf'
              if (mnemonic[2] == 's') { // 'lfs'
                insn->set_kind(x86_lfs);
              }
            break;}
            case 'g': { // 'lg'
              if (mnemonic[2] == 's') { // 'lgs'
                insn->set_kind(x86_lgs);
              }
            break;}
            case 's': { // 'ls'
              if (mnemonic[2] == 's') { // 'lss'
                insn->set_kind(x86_lss);
              }
            break;}
            default: break;
          }
        break;}
        case 'm': { // 'm'
          switch (mnemonic[1]) {
            case 'o': { // 'mo'
              if (mnemonic[2] == 'v') { // 'mov'
                insn->set_kind(x86_mov);
              }
            break;}
            case 'u': { // 'mu'
              if (mnemonic[2] == 'l') { // 'mul'
                insn->set_kind(x86_mul);
              }
            break;}
            default: break;
          }
        break;}
        case 'n': { // 'n'
          switch (mnemonic[1]) {
            case 'e': { // 'ne'
              if (mnemonic[2] == 'g') { // 'neg'
                insn->set_kind(x86_neg);
              }
            break;}
            case 'o': { // 'no'
              switch (mnemonic[2]) {
                case 'p': { // 'nop'
                  insn->set_kind(x86_nop);
                break;}
                case 't': { // 'not'
                  insn->set_kind(x86_not);
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 'o': { // 'o'
          if (mnemonic[1] == 'u') { // 'ou'
            if (mnemonic[2] == 't') { // 'out'
              insn->set_kind(x86_out);
            }
          }
        break;}
        case 'p': { // 'p'
          if (mnemonic[1] == 'o') { // 'po'
            if (mnemonic[2] == 'p') { // 'pop'
              insn->set_kind(x86_pop);
            }
          }
        break;}
        case 'r': { // 'r'
          switch (mnemonic[1]) {
            case 'c': { // 'rc'
              switch (mnemonic[2]) {
                case 'l': { // 'rcl'
                  insn->set_kind(x86_rcl);
                break;}
                case 'r': { // 'rcr'
                  insn->set_kind(x86_rcr);
                break;}
                default: break;
              }
            break;}
            case 'e': { // 're'
              if (mnemonic[2] == 't') { // 'ret'
                insn->set_kind(x86_ret);
              }
            break;}
            case 'o': { // 'ro'
              switch (mnemonic[2]) {
                case 'l': { // 'rol'
                  insn->set_kind(x86_rol);
                break;}
                case 'r': { // 'ror'
                  insn->set_kind(x86_ror);
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 's': { // 's'
          switch (mnemonic[1]) {
            case 'a': { // 'sa'
              switch (mnemonic[2]) {
                case 'l': { // 'sal'
                  insn->set_kind(x86_shl);
                break;}
                case 'r': { // 'sar'
                  insn->set_kind(x86_sar);
                break;}
                default: break;
              }
            break;}
            case 'b': { // 'sb'
              if (mnemonic[2] == 'b') { // 'sbb'
                insn->set_kind(x86_sbb);
              }
            break;}
            case 'h': { // 'sh'
              switch (mnemonic[2]) {
                case 'l': { // 'shl'
                  insn->set_kind(x86_shl);
                break;}
                case 'r': { // 'shr'
                  insn->set_kind(x86_shr);
                break;}
                default: break;
              }
            break;}
            case 't': { // 'st'
              switch (mnemonic[2]) {
                case 'c': { // 'stc'
                  insn->set_kind(x86_stc);
                break;}
                case 'd': { // 'std'
                  insn->set_kind(x86_std);
                break;}
                case 'i': { // 'sti'
                  insn->set_kind(x86_sti);
                break;}
                default: break;
              }
            break;}
            case 'u': { // 'su'
              if (mnemonic[2] == 'b') { // 'sub'
                insn->set_kind(x86_sub);
              }
            break;}
            default: break;
          }
        break;}
        case 'u': { // 'u'
          if (mnemonic[1] == 'd') { // 'ud'
            if (mnemonic[2] == '2') { // 'ud2'
              insn->set_kind(x86_ud2);
            }
          }
        break;}
        case 'x': { // 'x'
          if (mnemonic[1] == 'o') { // 'xo'
            if (mnemonic[2] == 'r') { // 'xor'
              insn->set_kind(x86_xor);
            }
          }
        break;}
        default: break;
      }
    break;
    case 4:
      switch (mnemonic[0]) {
        case 'a': { // 'a'
          if (mnemonic[1] == 'r') { // 'ar'
            if (mnemonic[2] == 'p') { // 'arp'
              if (mnemonic[3] == 'l') { // 'arpl'
                insn->set_kind(x86_arpl);
              }
            }
          }
        break;}
        case 'b': { // 'b'
          if (mnemonic[1] == 't') { // 'bt'
            switch (mnemonic[2]) {
              case 'c': { // 'btc'
                if (mnemonic[3] == 'l') { // 'btcl'
                  insn->set_kind(x86_btc);
                }
              break;}
              case 'r': { // 'btr'
                if (mnemonic[3] == 'l') { // 'btrl'
                  insn->set_kind(x86_btr);
                }
              break;}
              case 's': { // 'bts'
                if (mnemonic[3] == 'l') { // 'btsl'
                  insn->set_kind(x86_bts);
                }
              break;}
              default: break;
            }
          }
        break;}
        case 'c': { // 'c'
          switch (mnemonic[1]) {
            case 'a': { // 'ca'
              if (mnemonic[2] == 'l') { // 'cal'
                if (mnemonic[3] == 'l') { // 'call'
                  insn->set_kind(x86_call);
                }
              }
            break;}
            case 'd': { // 'cd'
              if (mnemonic[2] == 'q') { // 'cdq'
                if (mnemonic[3] == 'e') { // 'cdqe'
                  insn->set_kind(x86_cdqe);
                }
              }
            break;}
            case 'w': { // 'cw'
              if (mnemonic[2] == 'd') { // 'cwd'
                if (mnemonic[3] == 'e') { // 'cwde'
                  insn->set_kind(x86_cwde);
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'e': { // 'e'
          if (mnemonic[1] == 'm') { // 'em'
            if (mnemonic[2] == 'm') { // 'emm'
              if (mnemonic[3] == 's') { // 'emms'
                insn->set_kind(x86_emms);
              }
            }
          }
        break;}
        case 'f': { // 'f'
          switch (mnemonic[1]) {
            case 'a': { // 'fa'
              switch (mnemonic[2]) {
                case 'b': { // 'fab'
                  if (mnemonic[3] == 's') { // 'fabs'
                    insn->set_kind(x86_fabs);
                  }
                break;}
                case 'd': { // 'fad'
                  if (mnemonic[3] == 'd') { // 'fadd'
                    insn->set_kind(x86_fadd);
                  }
                break;}
                default: break;
              }
            break;}
            case 'c': { // 'fc'
              switch (mnemonic[2]) {
                case 'h': { // 'fch'
                  if (mnemonic[3] == 's') { // 'fchs'
                    insn->set_kind(x86_fchs);
                  }
                break;}
                case 'o': { // 'fco'
                  switch (mnemonic[3]) {
                    case 'm': { // 'fcom'
                      insn->set_kind(x86_fcom);
                    break;}
                    case 's': { // 'fcos'
                      insn->set_kind(x86_fcos);
                    break;}
                    default: break;
                  }
                break;}
                default: break;
              }
            break;}
            case 'd': { // 'fd'
              if (mnemonic[2] == 'i') { // 'fdi'
                if (mnemonic[3] == 'v') { // 'fdiv'
                  insn->set_kind(x86_fdiv);
                }
              }
            break;}
            case 'i': { // 'fi'
              switch (mnemonic[2]) {
                case 'l': { // 'fil'
                  if (mnemonic[3] == 'd') { // 'fild'
                    insn->set_kind(x86_fild);
                  }
                break;}
                case 's': { // 'fis'
                  if (mnemonic[3] == 't') { // 'fist'
                    insn->set_kind(x86_fist);
                  }
                break;}
                default: break;
              }
            break;}
            case 'l': { // 'fl'
              if (mnemonic[2] == 'd') { // 'fld'
                switch (mnemonic[3]) {
                  case '1': { // 'fld1'
                    insn->set_kind(x86_fld1);
                  break;}
                  case 'l': { // 'fldl'
                    insn->set_kind(x86_fld);
                  break;}
                  case 's': { // 'flds'
                    insn->set_kind(x86_fld);
                  break;}
                  case 't': { // 'fldt'
                    insn->set_kind(x86_fld);
                  break;}
                  case 'z': { // 'fldz'
                    insn->set_kind(x86_fldz);
                  break;}
                  default: break;
                }
              }
            break;}
            case 'm': { // 'fm'
              if (mnemonic[2] == 'u') { // 'fmu'
                if (mnemonic[3] == 'l') { // 'fmul'
                  insn->set_kind(x86_fmul);
                }
              }
            break;}
            case 'n': { // 'fn'
              if (mnemonic[2] == 'o') { // 'fno'
                if (mnemonic[3] == 'p') { // 'fnop'
                  insn->set_kind(x86_fnop);
                }
              }
            break;}
            case 's': { // 'fs'
              switch (mnemonic[2]) {
                case 'i': { // 'fsi'
                  if (mnemonic[3] == 'n') { // 'fsin'
                    insn->set_kind(x86_fsin);
                  }
                break;}
                case 't': { // 'fst'
                  switch (mnemonic[3]) {
                    case 'l': { // 'fstl'
                      insn->set_kind(x86_fst);
                    break;}
                    case 'p': { // 'fstp'
                      insn->set_kind(x86_fstp);
                    break;}
                    case 's': { // 'fsts'
                      insn->set_kind(x86_fst);
                    break;}
                    default: break;
                  }
                break;}
                case 'u': { // 'fsu'
                  if (mnemonic[3] == 'b') { // 'fsub'
                    insn->set_kind(x86_fsub);
                  }
                break;}
                default: break;
              }
            break;}
            case 't': { // 'ft'
              if (mnemonic[2] == 's') { // 'fts'
                if (mnemonic[3] == 't') { // 'ftst'
                  insn->set_kind(x86_ftst);
                }
              }
            break;}
            case 'x': { // 'fx'
              if (mnemonic[2] == 'c') { // 'fxc'
                if (mnemonic[3] == 'h') { // 'fxch'
                  insn->set_kind(x86_fxch);
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'i': { // 'i'
          switch (mnemonic[1]) {
            case 'd': { // 'id'
              if (mnemonic[2] == 'i') { // 'idi'
                if (mnemonic[3] == 'v') { // 'idiv'
                  insn->set_kind(x86_idiv);
                }
              }
            break;}
            case 'm': { // 'im'
              if (mnemonic[2] == 'u') { // 'imu'
                if (mnemonic[3] == 'l') { // 'imul'
                  insn->set_kind(x86_imul);
                }
              }
            break;}
            case 'n': { // 'in'
              switch (mnemonic[2]) {
                case 's': { // 'ins'
                  switch (mnemonic[3]) {
                    case 'b': { // 'insb'
                      insn->set_kind(x86_insb);
                    break;}
                    case 'd': { // 'insd'
                      insn->set_kind(x86_insd);
                    break;}
                    case 'w': { // 'insw'
                      insn->set_kind(x86_insw);
                    break;}
                    default: break;
                  }
                break;}
                case 't': { // 'int'
                  if (mnemonic[3] == 'o') { // 'into'
                    insn->set_kind(x86_into);
                  }
                break;}
                default: break;
              }
            break;}
            case 'r': { // 'ir'
              if (mnemonic[2] == 'e') { // 'ire'
                if (mnemonic[3] == 't') { // 'iret'
                  insn->set_kind(x86_iret);
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'j': { // 'j'
          switch (mnemonic[1]) {
            case 'c': { // 'jc'
              if (mnemonic[2] == 'x') { // 'jcx'
                if (mnemonic[3] == 'z') { // 'jcxz'
                  insn->set_kind(x86_jcxz);
                }
              }
            break;}
            case 'n': { // 'jn'
              switch (mnemonic[2]) {
                case 'a': { // 'jna'
                  if (mnemonic[3] == 'e') { // 'jnae'
                    insn->set_kind(x86_jb);
                  }
                break;}
                case 'b': { // 'jnb'
                  if (mnemonic[3] == 'e') { // 'jnbe'
                    insn->set_kind(x86_ja);
                  }
                break;}
                case 'g': { // 'jng'
                  if (mnemonic[3] == 'e') { // 'jnge'
                    insn->set_kind(x86_jl);
                  }
                break;}
                case 'l': { // 'jnl'
                  if (mnemonic[3] == 'e') { // 'jnle'
                    insn->set_kind(x86_jg);
                  }
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 'l': { // 'l'
          switch (mnemonic[1]) {
            case 'a': { // 'la'
              if (mnemonic[2] == 'h') { // 'lah'
                if (mnemonic[3] == 'f') { // 'lahf'
                  insn->set_kind(x86_lahf);
                }
              }
            break;}
            case 'o': { // 'lo'
              switch (mnemonic[2]) {
                case 'c': { // 'loc'
                  if (mnemonic[3] == 'k') { // 'lock'
                    insn->set_kind(x86_lock);
                  }
                break;}
                case 'o': { // 'loo'
                  if (mnemonic[3] == 'p') { // 'loop'
                    insn->set_kind(x86_loop);
                  }
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 'p': { // 'p'
          switch (mnemonic[1]) {
            case 'a': { // 'pa'
              if (mnemonic[2] == 'n') { // 'pan'
                if (mnemonic[3] == 'd') { // 'pand'
                  insn->set_kind(x86_pand);
                }
              }
            break;}
            case 'o': { // 'po'
              if (mnemonic[2] == 'p') { // 'pop'
                switch (mnemonic[3]) {
                  case 'a': { // 'popa'
                    insn->set_kind(x86_popa);
                  break;}
                  case 'f': { // 'popf'
                    insn->set_kind(x86_popf);
                  break;}
                  default: break;
                }
              }
            break;}
            case 'u': { // 'pu'
              if (mnemonic[2] == 's') { // 'pus'
                if (mnemonic[3] == 'h') { // 'push'
                  insn->set_kind(x86_push);
                }
              }
            break;}
            case 'x': { // 'px'
              if (mnemonic[2] == 'o') { // 'pxo'
                if (mnemonic[3] == 'r') { // 'pxor'
                  insn->set_kind(x86_pxor);
                }
              }
            break;}
            default: break;
          }
        break;}
        case 's': { // 's'
          switch (mnemonic[1]) {
            case 'a': { // 'sa'
              if (mnemonic[2] == 'h') { // 'sah'
                if (mnemonic[3] == 'f') { // 'sahf'
                  insn->set_kind(x86_sahf);
                }
              }
            break;}
            case 'e': { // 'se'
              if (mnemonic[2] == 't') { // 'set'
                switch (mnemonic[3]) {
                  case 'a': { // 'seta'
                    insn->set_kind(x86_seta);
                  break;}
                  case 'b': { // 'setb'
                    insn->set_kind(x86_setb);
                  break;}
                  case 'c': { // 'setc'
                    insn->set_kind(x86_setb);
                  break;}
                  case 'e': { // 'sete'
                    insn->set_kind(x86_sete);
                  break;}
                  case 'g': { // 'setg'
                    insn->set_kind(x86_setg);
                  break;}
                  case 'l': { // 'setl'
                    insn->set_kind(x86_setl);
                  break;}
                  case 'o': { // 'seto'
                    insn->set_kind(x86_seto);
                  break;}
                  case 'p': { // 'setp'
                    insn->set_kind(x86_setpe);
                  break;}
                  case 's': { // 'sets'
                    insn->set_kind(x86_sets);
                  break;}
                  case 'z': { // 'setz'
                    insn->set_kind(x86_sete);
                  break;}
                  default: break;
                }
              }
            break;}
            case 'h': { // 'sh'
              switch (mnemonic[2]) {
                case 'l': { // 'shl'
                  if (mnemonic[3] == 'd') { // 'shld'
                    insn->set_kind(x86_shld);
                  }
                break;}
                case 'r': { // 'shr'
                  if (mnemonic[3] == 'd') { // 'shrd'
                    insn->set_kind(x86_shrd);
                  }
                break;}
                default: break;
              }
            break;}
            case 'l': { // 'sl'
              if (mnemonic[2] == 'd') { // 'sld'
                if (mnemonic[3] == 't') { // 'sldt'
                  insn->set_kind(x86_sldt);
                }
              }
            break;}
            default: break;
          }
        break;}
        case 't': { // 't'
          if (mnemonic[1] == 'e') { // 'te'
            if (mnemonic[2] == 's') { // 'tes'
              if (mnemonic[3] == 't') { // 'test'
                insn->set_kind(x86_test);
              }
            }
          }
        break;}
        case 'v': { // 'v'
          if (mnemonic[1] == 'e') { // 've'
            if (mnemonic[2] == 'r') { // 'ver'
              switch (mnemonic[3]) {
                case 'r': { // 'verr'
                  insn->set_kind(x86_verr);
                break;}
                case 'w': { // 'verw'
                  insn->set_kind(x86_verw);
                break;}
                default: break;
              }
            }
          }
        break;}
        case 'w': { // 'w'
          if (mnemonic[1] == 'a') { // 'wa'
            if (mnemonic[2] == 'i') { // 'wai'
              if (mnemonic[3] == 't') { // 'wait'
                insn->set_kind(x86_wait);
              }
            }
          }
        break;}
        case 'x': { // 'x'
          switch (mnemonic[1]) {
            case 'a': { // 'xa'
              if (mnemonic[2] == 'd') { // 'xad'
                if (mnemonic[3] == 'd') { // 'xadd'
                  insn->set_kind(x86_xadd);
                }
              }
            break;}
            case 'c': { // 'xc'
              if (mnemonic[2] == 'h') { // 'xch'
                if (mnemonic[3] == 'g') { // 'xchg'
                  insn->set_kind(x86_xchg);
                }
              }
            break;}
            case 'l': { // 'xl'
              if (mnemonic[2] == 'a') { // 'xla'
                if (mnemonic[3] == 't') { // 'xlat'
                  insn->set_kind(x86_xlatb);
                }
              }
            break;}
            default: break;
          }
        break;}
        default: break;
      }
    break;
    case 5:
      switch (mnemonic[0]) {
        case 'a': { // 'a'
          switch (mnemonic[1]) {
            case 'd': { // 'ad'
              if (mnemonic[2] == 'd') { // 'add'
                if (mnemonic[3] == 's') { // 'adds'
                  switch (mnemonic[4]) {
                    case 'd': { // 'addsd'
                      insn->set_kind(x86_addsd);
                    break;}
                    case 's': { // 'addss'
                      insn->set_kind(x86_addss);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'n': { // 'an'
              if (mnemonic[2] == 'd') { // 'and'
                if (mnemonic[3] == 'p') { // 'andp'
                  if (mnemonic[4] == 'd') { // 'andpd'
                    insn->set_kind(x86_andpd);
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'b': { // 'b'
          switch (mnemonic[1]) {
            case 'o': { // 'bo'
              if (mnemonic[2] == 'u') { // 'bou'
                if (mnemonic[3] == 'n') { // 'boun'
                  if (mnemonic[4] == 'd') { // 'bound'
                    insn->set_kind(x86_bound);
                  }
                }
              }
            break;}
            case 's': { // 'bs'
              if (mnemonic[2] == 'w') { // 'bsw'
                if (mnemonic[3] == 'a') { // 'bswa'
                  if (mnemonic[4] == 'p') { // 'bswap'
                    insn->set_kind(x86_bswap);
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'c': { // 'c'
          switch (mnemonic[1]) {
            case 'm': { // 'cm'
              switch (mnemonic[2]) {
                case 'o': { // 'cmo'
                  if (mnemonic[3] == 'v') { // 'cmov'
                    switch (mnemonic[4]) {
                      case 'a': { // 'cmova'
                        insn->set_kind(x86_cmova);
                      break;}
                      case 'b': { // 'cmovb'
                        insn->set_kind(x86_cmovb);
                      break;}
                      case 'c': { // 'cmovc'
                        insn->set_kind(x86_cmovb);
                      break;}
                      case 'e': { // 'cmove'
                        insn->set_kind(x86_cmove);
                      break;}
                      case 'g': { // 'cmovg'
                        insn->set_kind(x86_cmovg);
                      break;}
                      case 'l': { // 'cmovl'
                        insn->set_kind(x86_cmovl);
                      break;}
                      case 'o': { // 'cmovo'
                        insn->set_kind(x86_cmovo);
                      break;}
                      case 'p': { // 'cmovp'
                        insn->set_kind(x86_cmovpe);
                      break;}
                      case 's': { // 'cmovs'
                        insn->set_kind(x86_cmovs);
                      break;}
                      case 'z': { // 'cmovz'
                        insn->set_kind(x86_cmove);
                      break;}
                      default: break;
                    }
                  }
                break;}
                case 'p': { // 'cmp'
                  if (mnemonic[3] == 's') { // 'cmps'
                    switch (mnemonic[4]) {
                      case 'b': { // 'cmpsb'
                        insn->set_kind(x86_cmpsb);
                      break;}
                      case 'd': { // 'cmpsd'
                        insn->set_kind(x86_cmpsd);
                      break;}
                      case 'q': { // 'cmpsq'
                        insn->set_kind(x86_cmpsq);
                      break;}
                      case 'w': { // 'cmpsw'
                        insn->set_kind(x86_cmpsw);
                      break;}
                      default: break;
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'p': { // 'cp'
              if (mnemonic[2] == 'u') { // 'cpu'
                if (mnemonic[3] == 'i') { // 'cpui'
                  if (mnemonic[4] == 'd') { // 'cpuid'
                    insn->set_kind(x86_cpuid);
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'd': { // 'd'
          if (mnemonic[1] == 'i') { // 'di'
            if (mnemonic[2] == 'v') { // 'div'
              if (mnemonic[3] == 's') { // 'divs'
                if (mnemonic[4] == 'd') { // 'divsd'
                  insn->set_kind(x86_divsd);
                }
              }
            }
          }
        break;}
        case 'e': { // 'e'
          if (mnemonic[1] == 'n') { // 'en'
            if (mnemonic[2] == 't') { // 'ent'
              if (mnemonic[3] == 'e') { // 'ente'
                if (mnemonic[4] == 'r') { // 'enter'
                  insn->set_kind(x86_enter);
                }
              }
            }
          }
        break;}
        case 'f': { // 'f'
          switch (mnemonic[1]) {
            case '2': { // 'f2'
              if (mnemonic[2] == 'x') { // 'f2x'
                if (mnemonic[3] == 'm') { // 'f2xm'
                  if (mnemonic[4] == '1') { // 'f2xm1'
                    insn->set_kind(x86_f2xm1);
                  }
                }
              }
            break;}
            case 'a': { // 'fa'
              if (mnemonic[2] == 'd') { // 'fad'
                if (mnemonic[3] == 'd') { // 'fadd'
                  switch (mnemonic[4]) {
                    case 'l': { // 'faddl'
                      insn->set_kind(x86_fadd);
                    break;}
                    case 'p': { // 'faddp'
                      insn->set_kind(x86_faddp);
                    break;}
                    case 's': { // 'fadds'
                      insn->set_kind(x86_fadd);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'c': { // 'fc'
              if (mnemonic[2] == 'o') { // 'fco'
                if (mnemonic[3] == 'm') { // 'fcom'
                  switch (mnemonic[4]) {
                    case 'l': { // 'fcoml'
                      insn->set_kind(x86_fcom);
                    break;}
                    case 'p': { // 'fcomp'
                      insn->set_kind(x86_fcomp);
                    break;}
                    case 's': { // 'fcoms'
                      insn->set_kind(x86_fcom);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'd': { // 'fd'
              if (mnemonic[2] == 'i') { // 'fdi'
                if (mnemonic[3] == 'v') { // 'fdiv'
                  switch (mnemonic[4]) {
                    case 'l': { // 'fdivl'
                      insn->set_kind(x86_fdiv);
                    break;}
                    case 'p': { // 'fdivp'
                      insn->set_kind(x86_fdivp);
                    break;}
                    case 'r': { // 'fdivr'
                      insn->set_kind(x86_fdivr);
                    break;}
                    case 's': { // 'fdivs'
                      insn->set_kind(x86_fdiv);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'f': { // 'ff'
              if (mnemonic[2] == 'r') { // 'ffr'
                if (mnemonic[3] == 'e') { // 'ffre'
                  if (mnemonic[4] == 'e') { // 'ffree'
                    insn->set_kind(x86_ffree);
                  }
                }
              }
            break;}
            case 'i': { // 'fi'
              switch (mnemonic[2]) {
                case 'a': { // 'fia'
                  if (mnemonic[3] == 'd') { // 'fiad'
                    if (mnemonic[4] == 'd') { // 'fiadd'
                      insn->set_kind(x86_fiadd);
                    }
                  }
                break;}
                case 'd': { // 'fid'
                  if (mnemonic[3] == 'i') { // 'fidi'
                    if (mnemonic[4] == 'v') { // 'fidiv'
                      insn->set_kind(x86_fidiv);
                    }
                  }
                break;}
                case 'l': { // 'fil'
                  if (mnemonic[3] == 'd') { // 'fild'
                    if (mnemonic[4] == 'l') { // 'fildl'
                      insn->set_kind(x86_fild);
                    }
                  }
                break;}
                case 'm': { // 'fim'
                  if (mnemonic[3] == 'u') { // 'fimu'
                    if (mnemonic[4] == 'l') { // 'fimul'
                      insn->set_kind(x86_fimul);
                    }
                  }
                break;}
                case 's': { // 'fis'
                  if (mnemonic[3] == 't') { // 'fist'
                    switch (mnemonic[4]) {
                      case 'l': { // 'fistl'
                        insn->set_kind(x86_fist);
                      break;}
                      case 'p': { // 'fistp'
                        insn->set_kind(x86_fistp);
                      break;}
                      default: break;
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'l': { // 'fl'
              if (mnemonic[2] == 'd') { // 'fld'
                switch (mnemonic[3]) {
                  case 'c': { // 'fldc'
                    if (mnemonic[4] == 'w') { // 'fldcw'
                      insn->set_kind(x86_fldcw);
                    }
                  break;}
                  case 'p': { // 'fldp'
                    if (mnemonic[4] == 'i') { // 'fldpi'
                      insn->set_kind(x86_fldpi);
                    }
                  break;}
                  default: break;
                }
              }
            break;}
            case 'm': { // 'fm'
              if (mnemonic[2] == 'u') { // 'fmu'
                if (mnemonic[3] == 'l') { // 'fmul'
                  switch (mnemonic[4]) {
                    case 'l': { // 'fmull'
                      insn->set_kind(x86_fmul);
                    break;}
                    case 'p': { // 'fmulp'
                      insn->set_kind(x86_fmulp);
                    break;}
                    case 's': { // 'fmuls'
                      insn->set_kind(x86_fmul);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'p': { // 'fp'
              switch (mnemonic[2]) {
                case 'r': { // 'fpr'
                  if (mnemonic[3] == 'e') { // 'fpre'
                    if (mnemonic[4] == 'm') { // 'fprem'
                      insn->set_kind(x86_fprem);
                    }
                  }
                break;}
                case 't': { // 'fpt'
                  if (mnemonic[3] == 'a') { // 'fpta'
                    if (mnemonic[4] == 'n') { // 'fptan'
                      insn->set_kind(x86_fptan);
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 's': { // 'fs'
              switch (mnemonic[2]) {
                case 'a': { // 'fsa'
                  if (mnemonic[3] == 'v') { // 'fsav'
                    if (mnemonic[4] == 'e') { // 'fsave'
                      insn->set_kind(x86_fsave);
                    }
                  }
                break;}
                case 'q': { // 'fsq'
                  if (mnemonic[3] == 'r') { // 'fsqr'
                    if (mnemonic[4] == 't') { // 'fsqrt'
                      insn->set_kind(x86_fsqrt);
                    }
                  }
                break;}
                case 't': { // 'fst'
                  if (mnemonic[3] == 'p') { // 'fstp'
                    switch (mnemonic[4]) {
                      case 'l': { // 'fstpl'
                        insn->set_kind(x86_fstp);
                      break;}
                      case 's': { // 'fstps'
                        insn->set_kind(x86_fstp);
                      break;}
                      case 't': { // 'fstpt'
                        insn->set_kind(x86_fstp);
                      break;}
                      default: break;
                    }
                  }
                break;}
                case 'u': { // 'fsu'
                  if (mnemonic[3] == 'b') { // 'fsub'
                    switch (mnemonic[4]) {
                      case 'l': { // 'fsubl'
                        insn->set_kind(x86_fsub);
                      break;}
                      case 'p': { // 'fsubp'
                        insn->set_kind(x86_fsubp);
                      break;}
                      case 'r': { // 'fsubr'
                        insn->set_kind(x86_fsubr);
                      break;}
                      case 's': { // 'fsubs'
                        insn->set_kind(x86_fsub);
                      break;}
                      default: break;
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'u': { // 'fu'
              if (mnemonic[2] == 'c') { // 'fuc'
                if (mnemonic[3] == 'o') { // 'fuco'
                  if (mnemonic[4] == 'm') { // 'fucom'
                    insn->set_kind(x86_fucom);
                  }
                }
              }
            break;}
            case 'w': { // 'fw'
              if (mnemonic[2] == 'a') { // 'fwa'
                if (mnemonic[3] == 'i') { // 'fwai'
                  if (mnemonic[4] == 't') { // 'fwait'
                    insn->set_kind(x86_fwait);
                  }
                }
              }
            break;}
            case 'y': { // 'fy'
              if (mnemonic[2] == 'l') { // 'fyl'
                if (mnemonic[3] == '2') { // 'fyl2'
                  if (mnemonic[4] == 'x') { // 'fyl2x'
                    insn->set_kind(x86_fyl2x);
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'i': { // 'i'
          if (mnemonic[1] == 'r') { // 'ir'
            if (mnemonic[2] == 'e') { // 'ire'
              if (mnemonic[3] == 't') { // 'iret'
                switch (mnemonic[4]) {
                  case 'd': { // 'iretd'
                    insn->set_kind(x86_iret);
                  break;}
                  case 'l': { // 'iretl'
                    insn->set_kind(x86_iret);
                  break;}
                  case 'q': { // 'iretq'
                    insn->set_kind(x86_iret);
                  break;}
                  default: break;
                }
              }
            }
          }
        break;}
        case 'j': { // 'j'
          switch (mnemonic[1]) {
            case 'e': { // 'je'
              if (mnemonic[2] == 'c') { // 'jec'
                if (mnemonic[3] == 'x') { // 'jecx'
                  if (mnemonic[4] == 'z') { // 'jecxz'
                    insn->set_kind(x86_jecxz);
                  }
                }
              }
            break;}
            case 'r': { // 'jr'
              if (mnemonic[2] == 'c') { // 'jrc'
                if (mnemonic[3] == 'x') { // 'jrcx'
                  if (mnemonic[4] == 'z') { // 'jrcxz'
                    insn->set_kind(x86_jrcxz);
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'l': { // 'l'
          switch (mnemonic[1]) {
            case 'e': { // 'le'
              if (mnemonic[2] == 'a') { // 'lea'
                if (mnemonic[3] == 'v') { // 'leav'
                  if (mnemonic[4] == 'e') { // 'leave'
                    insn->set_kind(x86_leave);
                  }
                }
              }
            break;}
            case 'o': { // 'lo'
              switch (mnemonic[2]) {
                case 'd': { // 'lod'
                  if (mnemonic[3] == 's') { // 'lods'
                    switch (mnemonic[4]) {
                      case 'b': { // 'lodsb'
                        insn->set_kind(x86_lodsb);
                      break;}
                      case 'd': { // 'lodsd'
                        insn->set_kind(x86_lodsd);
                      break;}
                      case 'q': { // 'lodsq'
                        insn->set_kind(x86_lodsq);
                      break;}
                      case 'w': { // 'lodsw'
                        insn->set_kind(x86_lodsw);
                      break;}
                      default: break;
                    }
                  }
                break;}
                case 'o': { // 'loo'
                  if (mnemonic[3] == 'p') { // 'loop'
                    switch (mnemonic[4]) {
                      case 'e': { // 'loope'
                        insn->set_kind(x86_loopz);
                      break;}
                      case 'l': { // 'loopl'
                        insn->set_kind(x86_loop);
                      break;}
                      case 'z': { // 'loopz'
                        insn->set_kind(x86_loopz);
                      break;}
                      default: break;
                    }
                  }
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 'm': { // 'm'
          if (mnemonic[1] == 'o') { // 'mo'
            if (mnemonic[2] == 'v') { // 'mov'
              switch (mnemonic[3]) {
                case 's': { // 'movs'
                  switch (mnemonic[4]) {
                    case 'b': { // 'movsb'
                      insn->set_kind(x86_movsb);
                    break;}
                    case 'd': { // 'movsd'
                      insn->set_kind(x86_movsd);
                    break;}
                    case 'q': { // 'movsq'
                      insn->set_kind(x86_movsq);
                    break;}
                    case 's': { // 'movss'
                      insn->set_kind(x86_movss);
                    break;}
                    case 'w': { // 'movsw'
                      insn->set_kind(x86_movsw);
                    break;}
                    case 'x': { // 'movsx'
                      insn->set_kind(x86_movsx);
                    break;}
                    default: break;
                  }
                break;}
                case 'z': { // 'movz'
                  if (mnemonic[4] == 'x') { // 'movzx'
                    insn->set_kind(x86_movzx);
                  }
                break;}
                default: break;
              }
            }
          }
        break;}
        case 'o': { // 'o'
          if (mnemonic[1] == 'u') { // 'ou'
            if (mnemonic[2] == 't') { // 'out'
              if (mnemonic[3] == 's') { // 'outs'
                switch (mnemonic[4]) {
                  case 'b': { // 'outsb'
                    insn->set_kind(x86_outsb);
                  break;}
                  case 'd': { // 'outsd'
                    insn->set_kind(x86_outsd);
                  break;}
                  case 'w': { // 'outsw'
                    insn->set_kind(x86_outsw);
                  break;}
                  default: break;
                }
              }
            }
          }
        break;}
        case 'p': { // 'p'
          switch (mnemonic[1]) {
            case 'a': { // 'pa'
              switch (mnemonic[2]) {
                case 'd': { // 'pad'
                  if (mnemonic[3] == 'd') { // 'padd'
                    switch (mnemonic[4]) {
                      case 'b': { // 'paddb'
                        insn->set_kind(x86_padd);
                      break;}
                      case 'd': { // 'paddd'
                        insn->set_kind(x86_padd);
                      break;}
                      case 'q': { // 'paddq'
                        insn->set_kind(x86_padd);
                      break;}
                      case 'w': { // 'paddw'
                        insn->set_kind(x86_padd);
                      break;}
                      default: break;
                    }
                  }
                break;}
                case 'n': { // 'pan'
                  if (mnemonic[3] == 'd') { // 'pand'
                    if (mnemonic[4] == 'n') { // 'pandn'
                      insn->set_kind(x86_pandn);
                    }
                  }
                break;}
                case 'u': { // 'pau'
                  if (mnemonic[3] == 's') { // 'paus'
                    if (mnemonic[4] == 'e') { // 'pause'
                      insn->set_kind(x86_pause);
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'o': { // 'po'
              if (mnemonic[2] == 'p') { // 'pop'
                switch (mnemonic[3]) {
                  case 'a': { // 'popa'
                    if (mnemonic[4] == 'd') { // 'popad'
                      insn->set_kind(x86_popad);
                    }
                  break;}
                  case 'f': { // 'popf'
                    switch (mnemonic[4]) {
                      case 'd': { // 'popfd'
                        insn->set_kind(x86_popfd);
                      break;}
                      case 'q': { // 'popfq'
                        insn->set_kind(x86_popfq);
                      break;}
                      default: break;
                    }
                  break;}
                  default: break;
                }
              }
            break;}
            case 's': { // 'ps'
              switch (mnemonic[2]) {
                case 'l': { // 'psl'
                  if (mnemonic[3] == 'l') { // 'psll'
                    switch (mnemonic[4]) {
                      case 'd': { // 'pslld'
                        insn->set_kind(x86_psll);
                      break;}
                      case 'q': { // 'psllq'
                        insn->set_kind(x86_psll);
                      break;}
                      case 'w': { // 'psllw'
                        insn->set_kind(x86_psll);
                      break;}
                      default: break;
                    }
                  }
                break;}
                case 'r': { // 'psr'
                  if (mnemonic[3] == 'l') { // 'psrl'
                    switch (mnemonic[4]) {
                      case 'd': { // 'psrld'
                        insn->set_kind(x86_psrl);
                      break;}
                      case 'q': { // 'psrlq'
                        insn->set_kind(x86_psrl);
                      break;}
                      case 'w': { // 'psrlw'
                        insn->set_kind(x86_psrl);
                      break;}
                      default: break;
                    }
                  }
                break;}
                case 'u': { // 'psu'
                  if (mnemonic[3] == 'b') { // 'psub'
                    switch (mnemonic[4]) {
                      case 'b': { // 'psubb'
                        insn->set_kind(x86_psub);
                      break;}
                      case 'd': { // 'psubd'
                        insn->set_kind(x86_psub);
                      break;}
                      case 'w': { // 'psubw'
                        insn->set_kind(x86_psub);
                      break;}
                      default: break;
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'u': { // 'pu'
              if (mnemonic[2] == 's') { // 'pus'
                if (mnemonic[3] == 'h') { // 'push'
                  switch (mnemonic[4]) {
                    case 'a': { // 'pusha'
                      insn->set_kind(x86_pusha);
                    break;}
                    case 'f': { // 'pushf'
                      insn->set_kind(x86_pushf);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'r': { // 'r'
          if (mnemonic[1] == 'd') { // 'rd'
            if (mnemonic[2] == 't') { // 'rdt'
              if (mnemonic[3] == 's') { // 'rdts'
                if (mnemonic[4] == 'c') { // 'rdtsc'
                  insn->set_kind(x86_rdtsc);
                }
              }
            }
          }
        break;}
        case 's': { // 's'
          switch (mnemonic[1]) {
            case 'c': { // 'sc'
              if (mnemonic[2] == 'a') { // 'sca'
                if (mnemonic[3] == 's') { // 'scas'
                  switch (mnemonic[4]) {
                    case 'b': { // 'scasb'
                      insn->set_kind(x86_scasb);
                    break;}
                    case 'd': { // 'scasd'
                      insn->set_kind(x86_scasd);
                    break;}
                    case 'q': { // 'scasq'
                      insn->set_kind(x86_scasq);
                    break;}
                    case 'w': { // 'scasw'
                      insn->set_kind(x86_scasw);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'e': { // 'se'
              if (mnemonic[2] == 't') { // 'set'
                switch (mnemonic[3]) {
                  case 'a': { // 'seta'
                    if (mnemonic[4] == 'e') { // 'setae'
                      insn->set_kind(x86_setb);
                    }
                  break;}
                  case 'b': { // 'setb'
                    if (mnemonic[4] == 'e') { // 'setbe'
                      insn->set_kind(x86_setbe);
                    }
                  break;}
                  case 'g': { // 'setg'
                    if (mnemonic[4] == 'e') { // 'setge'
                      insn->set_kind(x86_setge);
                    }
                  break;}
                  case 'l': { // 'setl'
                    if (mnemonic[4] == 'e') { // 'setle'
                      insn->set_kind(x86_setle);
                    }
                  break;}
                  case 'n': { // 'setn'
                    switch (mnemonic[4]) {
                      case 'a': { // 'setna'
                        insn->set_kind(x86_setbe);
                      break;}
                      case 'b': { // 'setnb'
                        insn->set_kind(x86_setae);
                      break;}
                      case 'c': { // 'setnc'
                        insn->set_kind(x86_setae);
                      break;}
                      case 'e': { // 'setne'
                        insn->set_kind(x86_setne);
                      break;}
                      case 'g': { // 'setng'
                        insn->set_kind(x86_setle);
                      break;}
                      case 'l': { // 'setnl'
                        insn->set_kind(x86_setge);
                      break;}
                      case 'o': { // 'setno'
                        insn->set_kind(x86_setno);
                      break;}
                      case 'p': { // 'setnp'
                        insn->set_kind(x86_setpo);
                      break;}
                      case 's': { // 'setns'
                        insn->set_kind(x86_setns);
                      break;}
                      case 'z': { // 'setnz'
                        insn->set_kind(x86_setne);
                      break;}
                      default: break;
                    }
                  break;}
                  case 'p': { // 'setp'
                    switch (mnemonic[4]) {
                      case 'e': { // 'setpe'
                        insn->set_kind(x86_setpe);
                      break;}
                      case 'o': { // 'setpo'
                        insn->set_kind(x86_setpo);
                      break;}
                      default: break;
                    }
                  break;}
                  default: break;
                }
              }
            break;}
            case 'l': { // 'sl'
              if (mnemonic[2] == 'd') { // 'sld'
                if (mnemonic[3] == 't') { // 'sldt'
                  if (mnemonic[4] == 'l') { // 'sldtl'
                    insn->set_kind(x86_sldt);
                  }
                }
              }
            break;}
            case 't': { // 'st'
              if (mnemonic[2] == 'o') { // 'sto'
                if (mnemonic[3] == 's') { // 'stos'
                  switch (mnemonic[4]) {
                    case 'b': { // 'stosb'
                      insn->set_kind(x86_stosb);
                    break;}
                    case 'd': { // 'stosd'
                      insn->set_kind(x86_stosd);
                    break;}
                    case 'q': { // 'stosq'
                      insn->set_kind(x86_stosq);
                    break;}
                    case 'w': { // 'stosw'
                      insn->set_kind(x86_stosw);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'u': { // 'su'
              if (mnemonic[2] == 'b') { // 'sub'
                if (mnemonic[3] == 's') { // 'subs'
                  switch (mnemonic[4]) {
                    case 'd': { // 'subsd'
                      insn->set_kind(x86_subsd);
                    break;}
                    case 's': { // 'subss'
                      insn->set_kind(x86_subss);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'x': { // 'x'
          switch (mnemonic[1]) {
            case 'a': { // 'xa'
              if (mnemonic[2] == 'd') { // 'xad'
                if (mnemonic[3] == 'd') { // 'xadd'
                  if (mnemonic[4] == 'l') { // 'xaddl'
                    insn->set_kind(x86_xadd);
                  }
                }
              }
            break;}
            case 'l': { // 'xl'
              if (mnemonic[2] == 'a') { // 'xla'
                if (mnemonic[3] == 't') { // 'xlat'
                  if (mnemonic[4] == 'b') { // 'xlatb'
                    insn->set_kind(x86_xlatb);
                  }
                }
              }
            break;}
            case 'o': { // 'xo'
              if (mnemonic[2] == 'r') { // 'xor'
                if (mnemonic[3] == 'p') { // 'xorp'
                  switch (mnemonic[4]) {
                    case 'd': { // 'xorpd'
                      insn->set_kind(x86_xorpd);
                    break;}
                    case 's': { // 'xorps'
                      insn->set_kind(x86_xorps);
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        default: break;
      }
    break;
    case 6:
      switch (mnemonic[0]) {
        case 'a': { // 'a'
          if (mnemonic[1] == 'n') { // 'an'
            if (mnemonic[2] == 'd') { // 'and'
              if (mnemonic[3] == 'n') { // 'andn'
                if (mnemonic[4] == 'p') { // 'andnp'
                  switch (mnemonic[5]) {
                    case 'd': { // 'andnpd'
                      insn->set_kind(x86_andnpd);
                    break;}
                    case 's': { // 'andnps'
                      insn->set_kind(x86_andnpd);
                    break;}
                    default: break;
                  }
                }
              }
            }
          }
        break;}
        case 'b': { // 'b'
          if (mnemonic[1] == 'o') { // 'bo'
            if (mnemonic[2] == 'u') { // 'bou'
              if (mnemonic[3] == 'n') { // 'boun'
                if (mnemonic[4] == 'd') { // 'bound'
                  if (mnemonic[5] == 'l') { // 'boundl'
                    insn->set_kind(x86_bound);
                  }
                }
              }
            }
          }
        break;}
        case 'c': { // 'c'
          if (mnemonic[1] == 'm') { // 'cm'
            if (mnemonic[2] == 'o') { // 'cmo'
              if (mnemonic[3] == 'v') { // 'cmov'
                switch (mnemonic[4]) {
                  case 'a': { // 'cmova'
                    if (mnemonic[5] == 'e') { // 'cmovae'
                      insn->set_kind(x86_cmovae);
                    }
                  break;}
                  case 'b': { // 'cmovb'
                    if (mnemonic[5] == 'e') { // 'cmovbe'
                      insn->set_kind(x86_cmovbe);
                    }
                  break;}
                  case 'g': { // 'cmovg'
                    if (mnemonic[5] == 'e') { // 'cmovge'
                      insn->set_kind(x86_cmovge);
                    }
                  break;}
                  case 'l': { // 'cmovl'
                    if (mnemonic[5] == 'e') { // 'cmovle'
                      insn->set_kind(x86_cmovle);
                    }
                  break;}
                  case 'n': { // 'cmovn'
                    switch (mnemonic[5]) {
                      case 'a': { // 'cmovna'
                        insn->set_kind(x86_cmovbe);
                      break;}
                      case 'b': { // 'cmovnb'
                        insn->set_kind(x86_cmovae);
                      break;}
                      case 'c': { // 'cmovnc'
                        insn->set_kind(x86_cmovae);
                      break;}
                      case 'e': { // 'cmovne'
                        insn->set_kind(x86_cmovne);
                      break;}
                      case 'g': { // 'cmovng'
                        insn->set_kind(x86_cmovle);
                      break;}
                      case 'l': { // 'cmovnl'
                        insn->set_kind(x86_cmovge);
                      break;}
                      case 'o': { // 'cmovno'
                        insn->set_kind(x86_cmovno);
                      break;}
                      case 'p': { // 'cmovnp'
                        insn->set_kind(x86_cmovpo);
                      break;}
                      case 's': { // 'cmovns'
                        insn->set_kind(x86_cmovns);
                      break;}
                      case 'z': { // 'cmovnz'
                        insn->set_kind(x86_cmovne);
                      break;}
                      default: break;
                    }
                  break;}
                  case 'p': { // 'cmovp'
                    switch (mnemonic[5]) {
                      case 'e': { // 'cmovpe'
                        insn->set_kind(x86_cmovpe);
                      break;}
                      case 'o': { // 'cmovpo'
                        insn->set_kind(x86_cmovpo);
                      break;}
                      default: break;
                    }
                  break;}
                  default: break;
                }
              }
            }
          }
        break;}
        case 'd': { // 'd'
          if (mnemonic[1] == 'a') { // 'da'
            if (mnemonic[2] == 't') { // 'dat'
              if (mnemonic[3] == 'a') { // 'data'
                if (mnemonic[4] == '1') { // 'data1'
                  if (mnemonic[5] == '6') { // 'data16'
                    insn->set_kind(x86_data16);
                  }
                }
              }
            }
          }
        break;}
        case 'e': { // 'e'
          if (mnemonic[1] == 'n') { // 'en'
            if (mnemonic[2] == 't') { // 'ent'
              if (mnemonic[3] == 'e') { // 'ente'
                if (mnemonic[4] == 'r') { // 'enter'
                  if (mnemonic[5] == 'l') { // 'enterl'
                    insn->set_kind(x86_enter);
                  }
                }
              }
            }
          }
        break;}
        case 'f': { // 'f'
          switch (mnemonic[1]) {
            case 'c': { // 'fc'
              if (mnemonic[2] == 'o') { // 'fco'
                if (mnemonic[3] == 'm') { // 'fcom'
                  if (mnemonic[4] == 'p') { // 'fcomp'
                    switch (mnemonic[5]) {
                      case 'l': { // 'fcompl'
                        insn->set_kind(x86_fcomp);
                      break;}
                      case 'p': { // 'fcompp'
                        insn->set_kind(x86_fcompp);
                      break;}
                      case 's': { // 'fcomps'
                        insn->set_kind(x86_fcomp);
                      break;}
                      default: break;
                    }
                  }
                }
              }
            break;}
            case 'd': { // 'fd'
              if (mnemonic[2] == 'i') { // 'fdi'
                if (mnemonic[3] == 'v') { // 'fdiv'
                  if (mnemonic[4] == 'r') { // 'fdivr'
                    switch (mnemonic[5]) {
                      case 'l': { // 'fdivrl'
                        insn->set_kind(x86_fdivr);
                      break;}
                      case 'p': { // 'fdivrp'
                        insn->set_kind(x86_fdivrp);
                      break;}
                      case 's': { // 'fdivrs'
                        insn->set_kind(x86_fdivr);
                      break;}
                      default: break;
                    }
                  }
                }
              }
            break;}
            case 'i': { // 'fi'
              switch (mnemonic[2]) {
                case 'a': { // 'fia'
                  if (mnemonic[3] == 'd') { // 'fiad'
                    if (mnemonic[4] == 'd') { // 'fiadd'
                      if (mnemonic[5] == 'l') { // 'fiaddl'
                        insn->set_kind(x86_fiadd);
                      }
                    }
                  }
                break;}
                case 'd': { // 'fid'
                  if (mnemonic[3] == 'i') { // 'fidi'
                    if (mnemonic[4] == 'v') { // 'fidiv'
                      if (mnemonic[5] == 'l') { // 'fidivl'
                        insn->set_kind(x86_fidiv);
                      }
                    }
                  }
                break;}
                case 'm': { // 'fim'
                  if (mnemonic[3] == 'u') { // 'fimu'
                    if (mnemonic[4] == 'l') { // 'fimul'
                      if (mnemonic[5] == 'l') { // 'fimull'
                        insn->set_kind(x86_fimul);
                      }
                    }
                  }
                break;}
                case 's': { // 'fis'
                  if (mnemonic[3] == 't') { // 'fist'
                    if (mnemonic[4] == 'p') { // 'fistp'
                      if (mnemonic[5] == 'l') { // 'fistpl'
                        insn->set_kind(x86_fistp);
                      }
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'l': { // 'fl'
              if (mnemonic[2] == 'd') { // 'fld'
                if (mnemonic[3] == 'l') { // 'fldl'
                  switch (mnemonic[4]) {
                    case '2': { // 'fldl2'
                      switch (mnemonic[5]) {
                        case 'e': { // 'fldl2e'
                          insn->set_kind(x86_fldl2e);
                        break;}
                        case 't': { // 'fldl2t'
                          insn->set_kind(x86_fldl2t);
                        break;}
                        default: break;
                      }
                    break;}
                    case 'g': { // 'fldlg'
                      if (mnemonic[5] == '2') { // 'fldlg2'
                        insn->set_kind(x86_fldlg2);
                      }
                    break;}
                    case 'n': { // 'fldln'
                      if (mnemonic[5] == '2') { // 'fldln2'
                        insn->set_kind(x86_fldln2);
                      }
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'n': { // 'fn'
              if (mnemonic[2] == 's') { // 'fns'
                if (mnemonic[3] == 't') { // 'fnst'
                  switch (mnemonic[4]) {
                    case 'c': { // 'fnstc'
                      if (mnemonic[5] == 'w') { // 'fnstcw'
                        insn->set_kind(x86_fnstcw);
                      }
                    break;}
                    case 's': { // 'fnsts'
                      if (mnemonic[5] == 'w') { // 'fnstsw'
                        insn->set_kind(x86_fnstsw);
                      }
                    break;}
                    default: break;
                  }
                }
              }
            break;}
            case 'p': { // 'fp'
              if (mnemonic[2] == 'a') { // 'fpa'
                if (mnemonic[3] == 't') { // 'fpat'
                  if (mnemonic[4] == 'a') { // 'fpata'
                    if (mnemonic[5] == 'n') { // 'fpatan'
                      insn->set_kind(x86_fpatan);
                    }
                  }
                }
              }
            break;}
            case 's': { // 'fs'
              switch (mnemonic[2]) {
                case 'c': { // 'fsc'
                  if (mnemonic[3] == 'a') { // 'fsca'
                    if (mnemonic[4] == 'l') { // 'fscal'
                      if (mnemonic[5] == 'e') { // 'fscale'
                        insn->set_kind(x86_fscale);
                      }
                    }
                  }
                break;}
                case 'u': { // 'fsu'
                  if (mnemonic[3] == 'b') { // 'fsub'
                    if (mnemonic[4] == 'r') { // 'fsubr'
                      switch (mnemonic[5]) {
                        case 'l': { // 'fsubrl'
                          insn->set_kind(x86_fsubr);
                        break;}
                        case 'p': { // 'fsubrp'
                          insn->set_kind(x86_fsubrp);
                        break;}
                        case 's': { // 'fsubrs'
                          insn->set_kind(x86_fsubr);
                        break;}
                        default: break;
                      }
                    }
                  }
                break;}
                default: break;
              }
            break;}
            case 'u': { // 'fu'
              if (mnemonic[2] == 'c') { // 'fuc'
                if (mnemonic[3] == 'o') { // 'fuco'
                  if (mnemonic[4] == 'm') { // 'fucom'
                    switch (mnemonic[5]) {
                      case 'i': { // 'fucomi'
                        insn->set_kind(x86_fucom);
                      break;}
                      case 'p': { // 'fucomp'
                        insn->set_kind(x86_fucomp);
                      break;}
                      default: break;
                    }
                  }
                }
              }
            break;}
            case 'x': { // 'fx'
              if (mnemonic[2] == 's') { // 'fxs'
                if (mnemonic[3] == 'a') { // 'fxsa'
                  if (mnemonic[4] == 'v') { // 'fxsav'
                    if (mnemonic[5] == 'e') { // 'fxsave'
                      insn->set_kind(x86_fxsave);
                    }
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 'l': { // 'l'
          if (mnemonic[1] == 'o') { // 'lo'
            if (mnemonic[2] == 'o') { // 'loo'
              if (mnemonic[3] == 'p') { // 'loop'
                if (mnemonic[4] == 'n') { // 'loopn'
                  switch (mnemonic[5]) {
                    case 'e': { // 'loopne'
                      insn->set_kind(x86_loopnz);
                    break;}
                    case 'z': { // 'loopnz'
                      insn->set_kind(x86_loopnz);
                    break;}
                    default: break;
                  }
                }
              }
            }
          }
        break;}
        case 'm': { // 'm'
          if (mnemonic[1] == 'o') { // 'mo'
            if (mnemonic[2] == 'v') { // 'mov'
              switch (mnemonic[3]) {
                case 'a': { // 'mova'
                  if (mnemonic[4] == 'p') { // 'movap'
                    if (mnemonic[5] == 's') { // 'movaps'
                      insn->set_kind(x86_movaps);
                    }
                  }
                break;}
                case 'd': { // 'movd'
                  if (mnemonic[4] == 'q') { // 'movdq'
                    if (mnemonic[5] == 'u') { // 'movdqu'
                      insn->set_kind(x86_movdqu);
                    }
                  }
                break;}
                case 'l': { // 'movl'
                  if (mnemonic[4] == 'p') { // 'movlp'
                    if (mnemonic[5] == 'd') { // 'movlpd'
                      insn->set_kind(x86_movlpd);
                    }
                  }
                break;}
                case 'n': { // 'movn'
                  if (mnemonic[4] == 't') { // 'movnt'
                    if (mnemonic[5] == 'q') { // 'movntq'
                      insn->set_kind(x86_movntq);
                    }
                  }
                break;}
                default: break;
              }
            }
          }
        break;}
        case 'p': { // 'p'
          if (mnemonic[1] == 'u') { // 'pu'
            if (mnemonic[2] == 's') { // 'pus'
              if (mnemonic[3] == 'h') { // 'push'
                switch (mnemonic[4]) {
                  case 'a': { // 'pusha'
                    if (mnemonic[5] == 'd') { // 'pushad'
                      insn->set_kind(x86_pushad);
                    }
                  break;}
                  case 'f': { // 'pushf'
                    switch (mnemonic[5]) {
                      case 'd': { // 'pushfd'
                        insn->set_kind(x86_pushfd);
                      break;}
                      case 'q': { // 'pushfq'
                        insn->set_kind(x86_pushfq);
                      break;}
                      default: break;
                    }
                  break;}
                  default: break;
                }
              }
            }
          }
        break;}
        case 's': { // 's'
          if (mnemonic[1] == 'e') { // 'se'
            if (mnemonic[2] == 't') { // 'set'
              if (mnemonic[3] == 'n') { // 'setn'
                switch (mnemonic[4]) {
                  case 'b': { // 'setnb'
                    if (mnemonic[5] == 'e') { // 'setnbe'
                      insn->set_kind(x86_seta);
                    }
                  break;}
                  case 'g': { // 'setng'
                    if (mnemonic[5] == 'e') { // 'setnge'
                      insn->set_kind(x86_setl);
                    }
                  break;}
                  case 'l': { // 'setnl'
                    if (mnemonic[5] == 'e') { // 'setnle'
                      insn->set_kind(x86_setg);
                    }
                  break;}
                  default: break;
                }
              }
            }
          }
        break;}
        default: break;
      }
    break;
    case 7:
      switch (mnemonic[0]) {
        case 'c': { // 'c'
          if (mnemonic[1] == 'm') { // 'cm'
            switch (mnemonic[2]) {
              case 'o': { // 'cmo'
                if (mnemonic[3] == 'v') { // 'cmov'
                  if (mnemonic[4] == 'n') { // 'cmovn'
                    switch (mnemonic[5]) {
                      case 'a': { // 'cmovna'
                        if (mnemonic[6] == 'e') { // 'cmovnae'
                          insn->set_kind(x86_cmovb);
                        }
                      break;}
                      case 'b': { // 'cmovnb'
                        if (mnemonic[6] == 'e') { // 'cmovnbe'
                          insn->set_kind(x86_cmova);
                        }
                      break;}
                      case 'g': { // 'cmovng'
                        if (mnemonic[6] == 'e') { // 'cmovnge'
                          insn->set_kind(x86_cmovl);
                        }
                      break;}
                      case 'l': { // 'cmovnl'
                        if (mnemonic[6] == 'e') { // 'cmovnle'
                          insn->set_kind(x86_cmovg);
                        }
                      break;}
                      default: break;
                    }
                  }
                }
              break;}
              case 'p': { // 'cmp'
                if (mnemonic[3] == 'x') { // 'cmpx'
                  if (mnemonic[4] == 'c') { // 'cmpxc'
                    if (mnemonic[5] == 'h') { // 'cmpxch'
                      if (mnemonic[6] == 'g') { // 'cmpxchg'
                        insn->set_kind(x86_cmpxchg);
                      }
                    }
                  }
                }
              break;}
              default: break;
            }
          }
        break;}
        case 'f': { // 'f'
          if (mnemonic[1] == 'u') { // 'fu'
            if (mnemonic[2] == 'c') { // 'fuc'
              if (mnemonic[3] == 'o') { // 'fuco'
                if (mnemonic[4] == 'm') { // 'fucom'
                  if (mnemonic[5] == 'p') { // 'fucomp'
                    if (mnemonic[6] == 'p') { // 'fucompp'
                      insn->set_kind(x86_fucompp);
                    }
                  }
                }
              }
            }
          }
        break;}
        case 'l': { // 'l'
          if (mnemonic[1] == 'd') { // 'ld'
            if (mnemonic[2] == 'm') { // 'ldm'
              if (mnemonic[3] == 'x') { // 'ldmx'
                if (mnemonic[4] == 'c') { // 'ldmxc'
                  if (mnemonic[5] == 's') { // 'ldmxcs'
                    if (mnemonic[6] == 'r') { // 'ldmxcsr'
                      insn->set_kind(x86_ldmxcsr);
                    }
                  }
                }
              }
            }
          }
        break;}
        case 'p': { // 'p'
          switch (mnemonic[1]) {
            case 'a': { // 'pa'
              if (mnemonic[2] == 'd') { // 'pad'
                if (mnemonic[3] == 'd') { // 'padd'
                  if (mnemonic[4] == 'u') { // 'paddu'
                    if (mnemonic[5] == 's') { // 'paddus'
                      switch (mnemonic[6]) {
                        case 'b': { // 'paddusb'
                          insn->set_kind(x86_paddus);
                        break;}
                        case 'w': { // 'paddusw'
                          insn->set_kind(x86_paddus);
                        break;}
                        default: break;
                      }
                    }
                  }
                }
              }
            break;}
            case 'c': { // 'pc'
              if (mnemonic[2] == 'm') { // 'pcm'
                if (mnemonic[3] == 'p') { // 'pcmp'
                  if (mnemonic[4] == 'e') { // 'pcmpe'
                    if (mnemonic[5] == 'q') { // 'pcmpeq'
                      switch (mnemonic[6]) {
                        case 'b': { // 'pcmpeqb'
                          insn->set_kind(x86_pcmpeq);
                        break;}
                        case 'd': { // 'pcmpeqd'
                          insn->set_kind(x86_pcmpeq);
                        break;}
                        case 'w': { // 'pcmpeqw'
                          insn->set_kind(x86_pcmpeq);
                        break;}
                        default: break;
                      }
                    }
                  }
                }
              }
            break;}
            case 's': { // 'ps'
              if (mnemonic[2] == 'u') { // 'psu'
                if (mnemonic[3] == 'b') { // 'psub'
                  if (mnemonic[4] == 'u') { // 'psubu'
                    if (mnemonic[5] == 's') { // 'psubus'
                      switch (mnemonic[6]) {
                        case 'b': { // 'psubusb'
                          insn->set_kind(x86_psubus);
                        break;}
                        case 'w': { // 'psubusw'
                          insn->set_kind(x86_psubus);
                        break;}
                        default: break;
                      }
                    }
                  }
                }
              }
            break;}
            default: break;
          }
        break;}
        case 's': { // 's'
          if (mnemonic[1] == 't') { // 'st'
            if (mnemonic[2] == 'm') { // 'stm'
              if (mnemonic[3] == 'x') { // 'stmx'
                if (mnemonic[4] == 'c') { // 'stmxc'
                  if (mnemonic[5] == 's') { // 'stmxcs'
                    if (mnemonic[6] == 'r') { // 'stmxcsr'
                      insn->set_kind(x86_stmxcsr);
                    }
                  }
                }
              }
            }
          }
        break;}
        case 'u': { // 'u'
          if (mnemonic[1] == 'c') { // 'uc'
            if (mnemonic[2] == 'o') { // 'uco'
              if (mnemonic[3] == 'm') { // 'ucom'
                if (mnemonic[4] == 'i') { // 'ucomi'
                  if (mnemonic[5] == 's') { // 'ucomis'
                    switch (mnemonic[6]) {
                      case 'd': { // 'ucomisd'
                        insn->set_kind(x86_ucomisd);
                      break;}
                      case 's': { // 'ucomiss'
                        insn->set_kind(x86_ucomiss);
                      break;}
                      default: break;
                    }
                  }
                }
              }
            }
          }
        break;}
        default: break;
      }
    break;
    case 9:
      if (mnemonic[0] == 'c') { // 'c'
        if (mnemonic[1] == 'm') { // 'cm'
          if (mnemonic[2] == 'p') { // 'cmp'
            if (mnemonic[3] == 'x') { // 'cmpx'
              if (mnemonic[4] == 'c') { // 'cmpxc'
                if (mnemonic[5] == 'h') { // 'cmpxch'
                  if (mnemonic[6] == 'g') { // 'cmpxchg'
                    if (mnemonic[7] == '8') { // 'cmpxchg8'
                      if (mnemonic[8] == 'b') { // 'cmpxchg8b'
                        insn->set_kind(x86_cmpxchg8b);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    break;
    default: break;
  }
  return insn;
}
SgAsmArmInstruction* createArmInstruction(uint64_t address, const std::string& mnemonic) {
  SgAsmArmInstruction* insn = new SgAsmArmInstruction(address, mnemonic, arm_unknown_instruction);
  switch (mnemonic.size()) {
    case 1:
      if (mnemonic[0] == 'b') { // 'b'
        insn->set_kind(arm_b);
      }
    break;
    case 2:
      if (mnemonic[0] == 'b') { // 'b'
        switch (mnemonic[1]) {
          case 'l': { // 'bl'
            insn->set_kind(arm_bl);
          break;}
          case 'x': { // 'bx'
            insn->set_kind(arm_bx);
          break;}
          default: break;
        }
      }
    break;
    case 3:
      switch (mnemonic[0]) {
        case 'a': { // 'a'
          switch (mnemonic[1]) {
            case 'd': { // 'ad'
              switch (mnemonic[2]) {
                case 'c': { // 'adc'
                  insn->set_kind(arm_adc);
                break;}
                case 'd': { // 'add'
                  insn->set_kind(arm_add);
                break;}
                default: break;
              }
            break;}
            case 'n': { // 'an'
              if (mnemonic[2] == 'd') { // 'and'
                insn->set_kind(arm_and);
              }
            break;}
            default: break;
          }
        break;}
        case 'b': { // 'b'
          if (mnemonic[1] == 'i') { // 'bi'
            if (mnemonic[2] == 'c') { // 'bic'
              insn->set_kind(arm_bic);
            }
          }
        break;}
        case 'c': { // 'c'
          if (mnemonic[1] == 'm') { // 'cm'
            switch (mnemonic[2]) {
              case 'n': { // 'cmn'
                insn->set_kind(arm_cmn);
              break;}
              case 'p': { // 'cmp'
                insn->set_kind(arm_cmp);
              break;}
              default: break;
            }
          }
        break;}
        case 'e': { // 'e'
          if (mnemonic[1] == 'o') { // 'eo'
            if (mnemonic[2] == 'r') { // 'eor'
              insn->set_kind(arm_eor);
            }
          }
        break;}
        case 'l': { // 'l'
          if (mnemonic[1] == 'd') { // 'ld'
            switch (mnemonic[2]) {
              case 'm': { // 'ldm'
                insn->set_kind(arm_ldm);
              break;}
              case 'r': { // 'ldr'
                insn->set_kind(arm_ldr);
              break;}
              default: break;
            }
          }
        break;}
        case 'm': { // 'm'
          switch (mnemonic[1]) {
            case 'l': { // 'ml'
              if (mnemonic[2] == 'a') { // 'mla'
                insn->set_kind(arm_mla);
              }
            break;}
            case 'o': { // 'mo'
              if (mnemonic[2] == 'v') { // 'mov'
                insn->set_kind(arm_mov);
              }
            break;}
            case 'r': { // 'mr'
              if (mnemonic[2] == 's') { // 'mrs'
                insn->set_kind(arm_mrs);
              }
            break;}
            case 's': { // 'ms'
              if (mnemonic[2] == 'r') { // 'msr'
                insn->set_kind(arm_msr);
              }
            break;}
            case 'u': { // 'mu'
              if (mnemonic[2] == 'l') { // 'mul'
                insn->set_kind(arm_mul);
              }
            break;}
            case 'v': { // 'mv'
              if (mnemonic[2] == 'n') { // 'mvn'
                insn->set_kind(arm_mvn);
              }
            break;}
            default: break;
          }
        break;}
        case 'o': { // 'o'
          if (mnemonic[1] == 'r') { // 'or'
            if (mnemonic[2] == 'r') { // 'orr'
              insn->set_kind(arm_orr);
            }
          }
        break;}
        case 'r': { // 'r'
          if (mnemonic[1] == 's') { // 'rs'
            switch (mnemonic[2]) {
              case 'b': { // 'rsb'
                insn->set_kind(arm_rsb);
              break;}
              case 'c': { // 'rsc'
                insn->set_kind(arm_rsc);
              break;}
              default: break;
            }
          }
        break;}
        case 's': { // 's'
          switch (mnemonic[1]) {
            case 'b': { // 'sb'
              if (mnemonic[2] == 'c') { // 'sbc'
                insn->set_kind(arm_sbc);
              }
            break;}
            case 't': { // 'st'
              switch (mnemonic[2]) {
                case 'm': { // 'stm'
                  insn->set_kind(arm_stm);
                break;}
                case 'r': { // 'str'
                  insn->set_kind(arm_str);
                break;}
                default: break;
              }
            break;}
            case 'u': { // 'su'
              if (mnemonic[2] == 'b') { // 'sub'
                insn->set_kind(arm_sub);
              }
            break;}
            case 'w': { // 'sw'
              switch (mnemonic[2]) {
                case 'i': { // 'swi'
                  insn->set_kind(arm_swi);
                break;}
                case 'p': { // 'swp'
                  insn->set_kind(arm_swp);
                break;}
                default: break;
              }
            break;}
            default: break;
          }
        break;}
        case 't': { // 't'
          switch (mnemonic[1]) {
            case 'e': { // 'te'
              if (mnemonic[2] == 'q') { // 'teq'
                insn->set_kind(arm_teq);
              }
            break;}
            case 's': { // 'ts'
              if (mnemonic[2] == 't') { // 'tst'
                insn->set_kind(arm_tst);
              }
            break;}
            default: break;
          }
        break;}
        default: break;
      }
    break;
    case 5:
      switch (mnemonic[0]) {
        case 's': { // 's'
          if (mnemonic[1] == 'm') { // 'sm'
            switch (mnemonic[2]) {
              case 'l': { // 'sml'
                if (mnemonic[3] == 'a') { // 'smla'
                  if (mnemonic[4] == 'l') { // 'smlal'
                    insn->set_kind(arm_smlal);
                  }
                }
              break;}
              case 'u': { // 'smu'
                if (mnemonic[3] == 'l') { // 'smul'
                  if (mnemonic[4] == 'l') { // 'smull'
                    insn->set_kind(arm_smull);
                  }
                }
              break;}
              default: break;
            }
          }
        break;}
        case 'u': { // 'u'
          if (mnemonic[1] == 'm') { // 'um'
            switch (mnemonic[2]) {
              case 'l': { // 'uml'
                if (mnemonic[3] == 'a') { // 'umla'
                  if (mnemonic[4] == 'l') { // 'umlal'
                    insn->set_kind(arm_umlal);
                  }
                }
              break;}
              case 'u': { // 'umu'
                if (mnemonic[3] == 'l') { // 'umul'
                  if (mnemonic[4] == 'l') { // 'umull'
                    insn->set_kind(arm_umull);
                  }
                }
              break;}
              default: break;
            }
          }
        break;}
        default: break;
      }
    break;
    default: break;
  }
  return insn;
}
