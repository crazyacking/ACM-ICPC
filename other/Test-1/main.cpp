#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>

int breakTie(int[], unsigned int[], int, int);
int lruRefBit(unsigned int[], int);
int optim(unsigned int[], int);
int lruStack(unsigned int[], int);
int fifo(unsigned int[], int);
int lfu(unsigned int[], int);
int lruref8bit(unsigned int[], int);
int compare(char[]);
void serverOptions();
unsigned int time1=0,time2=0;
int pr1=0, pr2=0;

struct reference_dat
{
    unsigned int ref_bit;
    unsigned int data;
};
struct reference_bit
{
    unsigned int ref_bit;
    unsigned int data;
};
int count_page=0;
//TODO dynamically maintain all array sizes
int main(int argc, char** argv)
{

    int fr_no=5, s=0;
    char rep_policy[20] = "FIFO";
    char logpath[1024] = "input.txt";

    for (s=1; s<argc; s++)
    {
        if (strcmp(argv[s], "-f")==0)
        {
            fr_no = atoi(argv[++s]);
        }
        else if (strcmp(argv[s], "-r")==0)
        {
            strcpy(rep_policy, argv[++s]);
        }
        else if (strcmp(argv[s], "-i")==0)
        {
            strcpy(logpath, argv[++s]);
        }
        else if (strcmp(argv[s], "-h")==0)
        {
            printf("help mode");
            serverOptions();
        }
        else
        {
            printf("\n\nNo Options Passed, ...\n");
        }
    }

    int i, j=0,nf=0;
    if(fr_no>0)
    {
        nf=fr_no;
    }
    else
    {
        printf("Enter proper frame value\n");
        exit(0);
    }
    unsigned int input[16] = {0,1,2,3,0,1,2,3,0,1,2,3,4,5,6,7}; //{1,2,3,4,1,2,5,1,2,3,4,5};
    count_page=0;
    //{ 1, 2, 3, 1, 1, 2, 4, 1, 3, 2, 1, 3 };// //TODO load the array size from file inputs

    //Reading from file
    FILE *f;
    char res[1024];
    f = fopen(logpath,"r");

    if (f == NULL)
    {
        perror ("Error opening file..Exiting...\n");
        exit(0);
    }
    else
    {
        fgets(res,1024,f);
        //puts(res);
        char* str=NULL;
        char delim[] = " ";
        str=strtok(res,delim);
        while(str!=NULL)
        {
            input[i]=atoi(str);
            i++;
            count_page++;
            str = strtok(NULL," ");
        }
    }
    printf("%d %s %s\n", fr_no, rep_policy, logpath);
    if (strcmp(rep_policy,"LRU-REF8")==0)
    {
        printf("Executing LRU-Ref8\n");
        pr1=lruRefBit(input, nf);
        pr2 = optim(input, nf);
        compare(rep_policy);
        return 0;
    }
    /*else if(==2){
     optim(input,nf);
     return 0;
     }*/
    else if (strcmp(rep_policy,"LRU-STACK")==0)
    {
        printf("Executing LRU-STACK\n");
        pr1= lruStack(input, nf);
        pr2 = optim(input, nf);
        compare(rep_policy);
        return 0;
    }
    else if (strcmp(rep_policy,"LFU")==0)
    {
        printf("Executing LFU\n");
        pr1=lfu(input, nf);
        pr2 = optim(input, nf);
        compare(rep_policy);
        return 0;
    }
    else if (strcmp(rep_policy,"LRU-CLOCK")==0)
    {
        pr1 = lruref8bit(input,nf);
        pr2 = optim(input, nf);
        compare(rep_policy);
    }
    else
    {
        pr1 = fifo(input, nf);
        pr2 = optim(input, nf);
        compare(rep_policy);
        return 0;
    }
}

int compare(char rep[])
{

    printf("No. of page replacements in %s : %d\n ",rep,pr1);
    printf("No. of page replacements in optimal : %d\n ",pr2);
    printf("Improvement of optimal over %s : %f\n",rep,((double)(pr1-pr2)/pr2));

    printf("Time by optimal :\t%u\n",time1);
    printf("Time by %s :\t%u\n",rep,time2);
    printf("Improvement in time=%f\n",(double)(time2-time1)/time2);
    return 0;
}

int lruref8bit(unsigned int input[], int nf)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int start_t = (int)tv.tv_usec;

    int page_rep_clk=0, tmp_c=0;
    int clk_hnd=0;
    int i=0, j=0;
    struct reference_bit ref[nf];
    for (i=0; i<nf; i++)
    {
        ref[i].ref_bit=0;
        ref[i].data=-1;
    }
    for (i=0; i<count_page; i++)
    {
        tmp_c=0;

        for (j=0; j<nf; j++)
        {
            if (ref[j].data==-1)
            {
                ref[j].ref_bit=0;
                ref[j].data=input[i];
                break;
                //printf("\nnum array %d\n num %d",b[num],num);
            }
            else
            {
                if (ref[j].data==input[i])
                {
                    ref[j].ref_bit=1;
                    printf("equal %d  bit=%d\n", ref[j].data, ref[j].ref_bit);
                    break;
                }
                else
                {
                    tmp_c++;
                }
            }
        }

        if (tmp_c==nf)
        {
            //printf("pf===%d		input=%d\n",page_fault,input[i]);
            page_rep_clk++;
            int k=0;
            for (k=0; k<nf; k++)
            {
                if (ref[clk_hnd].ref_bit==0)
                {
                    ref[clk_hnd].data=input[i];
                    clk_hnd++;
                    if (clk_hnd>=nf)
                        clk_hnd=0;
                    break;
                }
                else
                {
                    printf("clock2 ===%d\n", clk_hnd);
                    ref[clk_hnd].ref_bit=0;
                    clk_hnd++;
                    if (clk_hnd>=nf)
                        clk_hnd=0;
                }
            }
        }
    }

    struct timeval tv1;
    gettimeofday(&tv1, NULL);
    int end_t = (int)tv1.tv_usec;
    time1=end_t-start_t;
    return page_rep_clk;

}

//lru ref 8 bit
int lruRefBit(unsigned int input[], int nf)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int start_t = (int)tv.tv_usec;
    int i, dup_flg=0, count=0, j=0, count_dup=0;
    int size_tot = (sizeof(input)/sizeof(input[0]));
    unsigned int dist[size_tot];
    struct reference_dat ref[size_tot];
    //size_dist = (int*) malloc(*sizeof(int));

    for (i=0; i<count_page; i++)
    {
        //Distinct values
        dup_flg=0;
        for (j=0; j<i-count_dup; j++)
        {
            if (input[i]==dist[j])
            {
                dup_flg=1;
                count_dup++;
                break;
            }
        }
        if (dup_flg==0)
        {
            dist[count]=input[i];
            count++;
        }
    }

    for (i=0; i<count; i++)
    {
        ref[i].ref_bit=0;
        ref[i].data=dist[i];
    }

    //LRU ref
    int a1[nf];
    for (i=0; i<nf; i++)
        a1[i]=-1;
    int page_rep_ref=0, tmp_c=0, flagmn=0, z=0;

    for (i=0; i<count_page; i++)
    {
        tmp_c=0;
        for (j=0; j<nf; j++)
        {
            if (a1[j]==-1)
            {
                for (z=0; z<count; z++)
                {
                    if (input[i]==ref[z].data)
                    {
                        ref[z].ref_bit=ref[z].ref_bit>>1;
                        ref[z].ref_bit=ref[z].ref_bit+128;
                    }
                    else
                    {
                        ref[z].ref_bit=ref[z].ref_bit>>1;
                    }
                }
                a1[j]=input[i];
                break;
                //printf("\nnum array %d\n num %d",b[num],num);
            }
            else
            {
                if (a1[j]==input[i])
                {
                    for (z=0; z<count; z++)
                    {
                        if (input[i]==ref[z].data)
                        {
                            ref[z].ref_bit=ref[z].ref_bit>>1;
                            ref[z].ref_bit=ref[z].ref_bit+128;
                        }
                        else
                        {
                            ref[z].ref_bit=ref[z].ref_bit>>1;
                        }
                    }
                    break;
                }
                else
                {
                    tmp_c++;
                }
            }
        }

        if (tmp_c==nf)
        {
            page_rep_ref++;

            int k=0, l=0, count1, min=0, min_value=0, tie=0, flag=0;
            unsigned int sort_res[100];
            for (k=0; k<nf; k++)
            {
                for (z=0; z<count; z++)
                {
                    if (a1[k]==ref[z].data)
                    {
                        flag=1;
                        if (z==0)
                        {
                            min=ref[z].ref_bit;
                            sort_res[k]=min;
                        }
                        else if (min>ref[z].ref_bit)
                        {
                            min=ref[z].ref_bit;
                            sort_res[k]=min;
                        }
                    }
                }
            }
            //printf("min==%d		sort==%d\n",min,sort_res[k-1]);
            //FIFO for breaking tie
            if (flag==1)
            {
                for (z=0; z<nf; z++)
                {
                    if (min==sort_res[z])
                    {
                        tie++;
                        if (tie>1)
                            break;
                    }
                }
            }
            if (tie>1)
            {
                int val = breakTie(a1, input, i, nf);
                tie=0;
                for (k=0; k<nf; k++)
                {
                    if (val==a1[k])
                    {
                        for (z=0; z<count; z++)
                        {
                            if (a1[k]==ref[z].data)
                            {
                                ref[z].ref_bit=ref[z].ref_bit>>1;
                                ref[z].ref_bit=ref[z].ref_bit+128;
                            }
                            else
                            {
                                ref[z].ref_bit=ref[z].ref_bit>>1;
                            }
                        }
                        a1[k]=input[i];
                        break;
                    }
                }
            }
            else if (flag==1)
            {
                for (z=0; z<count; z++)
                {
                    if (ref[z].ref_bit==min)
                    {
                        min_value = ref[z].data;
                    }
                    if (ref[z].data==input[i])
                    {
                        ref[z].ref_bit=ref[z].ref_bit>>1;
                        ref[z].ref_bit=ref[z].ref_bit+128;
                        printf("swap %d  bit=%d\n", ref[z].data, ref[z].ref_bit);
                    }
                    else
                    {
                        ref[z].ref_bit=ref[z].ref_bit>>1;
                        printf("no swap %d  bit=%d\n", ref[z].data,
                               ref[z].ref_bit);
                    }
                }
                for (k=0; k<nf; k++)
                {
                    if (a1[k]==min_value)
                    {
                        printf("swaped = %d with %d\n", a1[k], input[i]);
                        a1[k]=input[i];
                    }
                }

            }
        }
    }

    unsigned int end_t=(int)tv.tv_usec;
    time1=end_t-start_t;
    return page_rep_ref;
}

int optim(unsigned int input[], int nf)
{
    struct timeval tv1;
    gettimeofday(&tv1, NULL);
    unsigned int start_t = (int)tv1.tv_usec;
    unsigned int b[32000];
    int i=0;
    for (i=0; i<32000; i++)
    {
        b[i]=0;
    }
    int a1[nf];
    for (i=0; i<nf; i++)
        a1[i]=-1;
    int tmp_c=0, pg_rep_opt=0, j=0;
    for (i=0; i<count_page; i++)
    {
        tmp_c=0;
        for (j=0; j<nf; j++)
        {
            if (a1[j]==-1)
            {
                a1[j]=input[i];

                break;
                //printf("\nnum array %d\n num %d",b[num],num);
            }
            else
            {
                if (a1[j]==input[i])
                {
                    break;
                }
                else
                {
                    tmp_c++;
                }
            }
        }
        if (tmp_c==nf)
        {
            //printf("input [%d] == %d\n",i,input[i]);
            pg_rep_opt++;
            int k=0, count=0, count1=0, flagmn=0, min=0, min_value=0, tie=0;
            int l=i;
            for (k=0; k<nf; k++)
            {
                b[a1[k]]=0;
                for (l=i; l<count_page; l++)  //TODO array sizes dynamic
                {
                    if (a1[k]==input[l])
                    {
                        b[a1[k]]++;
                        //printf("%d $$$ %d $$$%d\n",b[a1[k]],a1[k],l);
                    }
                }
            }

            for (k=0; k<nf-1; k++)
            {
                count=a1[k];
                count1=a1[k+1];
                flagmn = 1;
                if (b[count]<b[count1])
                {
                    min=b[count];
                    min_value=count;
                }
                else
                {
                    min = b[count1];
                    min_value=count1;
                }
                //HERE count will have the number with minimum count
            }

            //FIFO for breaking tie
            for (k=0; k<nf; k++)
            {
                count=a1[k];
                if (b[count]==min)
                {
                    tie++;
                    if (tie>1)
                        break;
                }
            }
            if (tie>1)
            {
                int val = breakTie(a1, input, i, nf);
                tie=0;
                for (k=0; k<nf; k++)
                {
                    if (val==a1[k])
                    {

                        a1[k]=input[i];
                    }
                }
            }
            else if (flagmn==1)
            {
                for (k=0; k<nf; k++)
                {
                    if (min_value==a1[k])
                    {

                        a1[k]=input[i];
                    }
                }
            }
            tie=0;
        }
    }

    struct timeval tv3;
    gettimeofday(&tv3, NULL);
    unsigned int end_t=(int)tv3.tv_usec;
    time2=end_t-start_t;
    return pg_rep_opt;

}

//LRU STACK
int lruStack(unsigned int input[], int nf)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int start_t = (int)tv.tv_usec;

    int i=0, a1[nf];
    for (i=0; i<nf; i++)
        a1[i]=-1;
    //LRU
    int j=0;
    int page_rep_lrus=0, tmp_c=0;

    for (i=0; i<count_page; i++)
    {
        tmp_c=0;
        int z;

        for (j=0; j<nf; j++)
        {
            if (a1[j]==-1)
            {
                a1[j]=input[i];

                break;
                //printf("\nnum array %d\n num %d",b[num],num);
            }
            else
            {
                if (a1[j]==input[i])
                {

                    for (z=j; z<nf-1; z++)
                    {
                        a1[z]=a1[z+1];
                    }
                    a1[z]=input[i];
                }
                else
                {

                    tmp_c++;
                }
            }
        }

        if (tmp_c==nf)
        {
            page_rep_lrus++;

            for (z=0; z<nf-1; z++)
            {
                a1[z]=a1[z+1];
            }
            a1[z]=input[i];
        }
    }


    struct timeval tv4;
    gettimeofday(&tv4, NULL);
    unsigned int end_t=(int)tv4.tv_usec;
    time1=end_t-start_t;
    return page_rep_lrus;
}

int fifo(unsigned int input[], int nf)
{
    struct timeval tv5;
    gettimeofday(&tv5, NULL);
    unsigned int start_t = (int)tv5.tv_usec;

    int ptr_top = 0, i=0, a1[nf], j=0;
    for (i=0; i<nf; i++)
        a1[i]=-1;
    int page_hit = 0;
    int pr = 0;
    for (i=0; i<count_page; i++)  //TODO dynamic value load
    {
        for (j=0; j<nf; j++)
        {
            if (a1[j]==-1)
            {

                a1[j]=input[i];
                break;
            }
            else
            {
                if (a1[j]==input[i])
                {
                    page_hit++;
                    break;
                }
            }
            if (j==(nf-1))
            {
                //page fault and page replace ++
                pr++;
                int k=0;
                int val = breakTie(a1, input, i, nf);
                for (k=0; k<nf; k++)
                {
                    if (val==a1[k])
                    {

                        a1[k]=input[i];
                        break;
                    }
                }
                /*printf("%d replaced by = %d\n",a1[ptr_top],input[i]);
                 a1[ptr_top]=input[i];
                 ptr_top++;
                 if(ptr_top>=nf)ptr_top=0;
                 break;*/
            }
        }
    }

    struct timeval tv6;
    gettimeofday(&tv6, NULL);
    unsigned int end_t=(int)tv6.tv_usec;

    time1=end_t-start_t;
    return pr;
}

int lfu(unsigned int input[], int nf)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned int start_t = (int)tv.tv_usec;

    //LFU
    int i=0, j=0, a1[nf];
    for (i=0; i<nf; i++)
        a1[i]=-1;

    int count, page_rep_lfu=0, tmp_c, flagmn=0;
    int b[100];
    for (i=0; i<100; i++)
        b[i]=0;
    for (i=0; i<count_page; i++)
    {
        tmp_c=0;
        for (j=0; j<nf; j++)
        {
            if (a1[j]==-1)
            {
                a1[j]=input[i];
                count = input[i];
                //printf("input %d\n",input[i]);
                b[count]++;//to count the occurences
                printf("1b[%d]=== %d\n", count, b[count]);
                break;
                //printf("\nnum array %d\n num %d",b[num],num);
            }
            else
            {
                if (a1[j]==input[i])
                {
                    count=input[i];
                    b[count]++;
                    printf("2b[%d]=== %d\n", count, b[count]);
                    break;
                }
                else
                {
                    tmp_c++;
                }
            }
        }

        if (tmp_c==nf)
        {
            page_rep_lfu++;
            int k=0, l=0, count, count1, min=0, min_value=0, sort_res[100],
                tie=0;
            for (k=0; k<nf-1; k++)
            {
                count=a1[k];
                count1=a1[k+1];
                flagmn = 1;
                if (b[count]<b[count1])
                {
                    min=b[count];
                    min_value=count;
                }
                else
                {
                    min = b[count1];
                    min_value=count1;
                }
                //HERE count will have the number with minimum count
            }
            //FIFO for breaking tie
            for (k=0; k<nf; k++)
            {
                count=a1[k];
                if (b[count]==min)
                {
                    flagmn = 1;
                    tie++;
                    if (tie>1)
                        break;
                }

            }
            if (tie>1)
            {
                int val = breakTie(a1, input, i, nf);
                tie=0;
                for (k=0; k<nf; k++)
                {
                    if (val==a1[k])
                    {
                        printf("%d replaced %d\n", input[i], a1[k]);
                        a1[k]=input[i];
                    }
                }
            }
            else if (flagmn==1)
            {
                for (k=0; k<nf; k++)
                {
                    if (min_value==a1[k])
                    {
                        printf("%d replaced %d\n", input[i], a1[k]);
                        a1[k]=input[i];
                    }
                }
            }
            tie=0;
        }

    }

    struct timeval tv6;
    gettimeofday(&tv6, NULL);
    unsigned int end_t=(int)tv6.tv_usec;

    time1=end_t-start_t;

    return page_rep_lfu;
}

//fifo breaktie
int breakTie(int a[], unsigned int b[], int c, int nf)
{
    int i, max, max_value, j=0;

    int count[1000]= { 0 };
    for (i=0; i<nf; i++)
    {
        for (j=c; j>=0; j--)
        {
            count[i]++;
            if (a[i]==b[j])
                break;
        }
    }
    for (i=0; i<nf; i++)
    {
        if (i==0)
        {
            max = count[0];
            max_value=a[0];
        }
        else if (count[i]>max)
        {
            max=count[i];
            max_value=a[i];
        }
    }
    return max_value;
}

void serverOptions()
{
    printf("\n-------------------------------------------------------------------------------------------------------------\n\n");
    printf("-f frames: \t\t No. of frames available.\n");
    printf("-r replacement policy : \t\t.FIFO or LFU or LRU-STACK or LRU-CLOCK or LRU-REF8\n");
    printf("-i file : \tThe path of the input files.\n");
    printf("\n-------------------------------------------------------------------------------------------------------------\n");
    exit(0);
}
