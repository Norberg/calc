#include <stdio.h>
#include "calc3.h"
#include "y.tab.h"

static int lbl;

int ex(nodeType *p) {
    int lbl1, lbl2;

    if (!p) return 0;
    switch(p->type) {
    case typeCon:       
        printf("\tpush(%d);\n", p->con.value); 
        break;
    case typeId:        
        printf("\tpush(%c);\n", p->id.i + 'a'); 
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0]);
	    printf("\tif(!pop())\n");
            printf("\t\tgoto\tL%03d;\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
            printf("\tgoto\tL%03d;\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2) {
                /* if else */
	        printf("\tif (!pop())\n");
                printf("\t\tgoto L%03d;\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("\tgoto\tL%03d;\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
		printf("\tif (!pop())\n");
                printf("\tgoto\tL%03d;\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("L%03d:\n", lbl1);
            }
            break;
        case PRINT:     
            ex(p->opr.op[0]);
            printf("\tprint();\n");
            break;
        case '=':       
            ex(p->opr.op[1]);
            printf("\t%c = pop();\n", p->opr.op[0]->id.i + 'a');
            break;
        case UMINUS:
            ex(p->opr.op[0]);
            printf("\tneg();\n");
            break;
	case FACT:
  	    ex(p->opr.op[0]);
	    printf("\tfact();\n");
	    break;
	case LNTWO:
	    ex(p->opr.op[0]);
	    printf("\tlntwo();\n");
	    break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            if (p->opr.oper == 59) {
		/* Broken operator, dont exist, why do we even get this?*/
		return 0;
	    }
            switch(p->opr.oper) {
	    case GCD:  
		printf("\tgcd();\n");
		break;
            case '+':   printf("\tadd();\n"); break;
            case '-':   printf("\tsub();\n"); break; 
            case '*':   printf("\tmul();\n"); break;
            case '/':   printf("\tdiv();\n"); break;
            case '<':
		printf("\tLESS();\n"); 
		return 0;
            case '>':  
		printf("\tGREATER();\n"); 
		return 0;
            case GE:
		printf("\tGE();\n"); 
		return 0;
            case LE: 
		printf("\tLE();\n"); 
		return 0;
            case NE:    
		printf("\tNE();\n"); 
		return 0;
            case EQ:    
		printf("\tEQ();\n"); 
		return 0;
             default:
		printf("/*unknown operator: %d*/\n", p->opr.oper);
		return 0;
            }
        }
    }
    return 0;
}
