#include <stdio.h>
#include "calc3.h"
#include "y.tab.h"

static int lbl;

int ex(nodeType *p) {
    int lbl1, lbl2;

    if (!p) return 0;
    switch(p->type) {
    case typeCon:       
        printf("\tpushl\t$%d\n", p->con.value); 
        break;
    case typeId:        
        printf("\tpushl\t%c\n", p->id.i + 'a'); 
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[0]);
	    printf("\tpopl\t%%ecx\n");
	    printf("\ttest\t%%cx, %%cx\n");
            printf("\tje\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[1]);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2) {
                /* if else */
		printf("\tpopl\t%%ecx\n");
                printf("\tjecxz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
		printf("\tpopl\t%%ecx\n");
                printf("\tjecxz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("L%03d:\n", lbl1);
            }
            break;
        case PRINT:     
            ex(p->opr.op[0]);
            printf("\tpush\t$FINT\n");
            printf("\tcall\tprintf\n");
            break;
        case '=':       
            ex(p->opr.op[1]);
            printf("\tpopl\t%c\n", p->opr.op[0]->id.i + 'a');
            break;
        case UMINUS:
            ex(p->opr.op[0]);
            printf("\tneg\n");
            break;
	case FACT:
  	    ex(p->opr.op[0]);
	    printf("\tfact\n");
	    break;
	case LNTWO:
	    ex(p->opr.op[0]);
	    printf("\lntwo\n");
	    break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
	    printf("\tpopl\t%%ebx\n");
	    printf("\tpopl\t%%eax\n");
            switch(p->opr.oper) {
	    case GCD:   printf("\tgcd\n"); break;
            case '+':   printf("\tadd\t %%ebx, %%eax\n"); break;
            case '-':   printf("\tsub\t %%ebx, %%eax\n"); break; 
            case '*':   printf("\tmul\t %%ebx\n"); break;
            case '/':   
		printf("\tcltd\n");
		printf("\tdiv %%ebx\n");
		 break;
            case '<':
		printf("\tmovl\t$0, %%ecx\n");
		printf("\t\t%%eax, %%ebx\n"); 
		printf("\tcmpl\t%%eax, %%ebx\n"); 
		printf("\tsetg\t%%cl\n"); 
	    	printf("\tpushl\t\%%ecx\n");
		return 0;
            case '>':  
		printf("\tmovl\t$0, %%ecx\n");
		printf("\tcmpl\t%%eax, %%ebx\n"); 
		printf("\tsetl\t%%cl\n"); 
	    	printf("\tpushl\t\%%ecx\n");
		return 0;
            case GE:
		printf("\tmovl\t$0, %%ecx\n");
		printf("\tcmpl\t%%eax, %%ebx\n"); 
		printf("\tsetle\t%%cl\n"); 
	    	printf("\tpushl\t\%%ecx\n");
		return 0;
            case LE: 
		printf("\tmovl\t$0, %%ecx\n");
		printf("\tcmpl\t%%eax, %%ebx\n"); 
		printf("\tsetge\t%%cl\n"); 
	    	printf("\tpushl\t\%%ecx\n");
		return 0;
            case NE:    
		printf("\tmovl\t$0, %%ecx\n");
		printf("\tcmpl\t%%eax, %%ebx\n"); 
		printf("\tsetne\t%%cl\n"); 
	    	printf("\tpushl\t\%%ecx\n");
		return 0;
            case EQ:    
		printf("\tmovl\t$0, %%ecx\n");
		printf("\tcmpl\t%%eax, %%ebx\n"); 
		printf("\tsete\t%%cl\n"); 
	    	printf("\tpushl\t\%%ecx\n");
		return 0;
            }
	    printf("\tpushl\t\%%eax\n");
        }
    }
    return 0;
}
