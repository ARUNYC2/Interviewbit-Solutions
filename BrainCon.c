#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
//#include<file.h>
#include<string.h>

	pthread_t  tid[2];
	pthread_t  ttid[2];
	
	//int counter;
	int x;int z=0;
	//int sum;
	int score=0;
	int nscore=20;
	pthread_mutex_t lock;
	int  counter = 0;

void* do_Calculate_Score(void *arg) { 

    unsigned long i = 0;
    int counter_times = 0;
    sleep(1);
   //printf("\n Job %d started\n", counter);
    b:
    	counter = 0;
    	nscore = 20;
	a:
    	sleep(1);
        counter++;
        nscore--;
      //printf("\n%d  ",50-counter);
	if(x == 0 ) goto a;
	if(counter == 20) 
	  	printf("\n Time out \n");
	if(z == 1) { 
		x = 0;
		pthread_mutex_lock(&lock);
	  	printf("\n you got  %d points \n",nscore);
	  	score += nscore;
		counter = 0;
		counter_times++;
		z = 0;
	}
	else if (z==-1) {
		printf("\n Wrong answer got 0 point :@\n");
		//score=score+2;
		z=0;//all_wrong++;
		counter_times++;
	}
	pthread_mutex_unlock(&lock);	
	if(counter_times <5) goto b;  
	 // pthread_kill(ttid[0], NULL);
	  //printf("\n your total  score = %d \n",score);
	  //else break;
	  //}
   // printf("\n Job %d finished\n", counter);
    
    return NULL;
}

void* do_Take_Result(void *arg)
{
	int sum;  int cursum;int sign;
  	int num1,num2; int k=0; //File *fid;
  	int level;
  	a:
    	printf("\n\tEnter game level press [0 , 1] ");
    	scanf("%d",&level);
    	printf("\n\tLOADING......\n");
    if(level==0)
     	level=10;
    else if(level==1)
        level=100;
    else {
		printf("\n@@@....please enter correct LEVEL....@@@");
		goto a;
	}
    while(k<5)	{
		++k;
        num2 = (rand()%level) ;
        num1 = (rand()%level) ;
        sign = rand()%2;
        if(sign==1) {
        	printf(" \n\t%d+%d\t=",num1,num2);
        	cursum=  num1+num2;
        }
        else if(sign==0) {
        	printf(" \n\t%d*%d\t=",num1,num2);
        	cursum=  num1*num2;	
		}
	    x=scanf("%d", &sum);
        if(sum == cursum)    
			z=1;
	   	//printf("\n you got  %d points \n",counter);
        else z=-1; 
        	sleep(2);
           
    }
    printf("\n your total  score = %d  / 100\n",score);
         
         
    	/*printf("\nDo you want to save this History  ?? press {y/n}");
       	  scanf("%c",ch);
          if(ch=='y'){
       	  fid=fopen("game_history","a+");
       	  printf("\n history save \n");*/
  		//printf("\ndosum"); 
    return NULL;
}

int main(void)
{  
	while(2) {
	    int i = 0;  counter = 0;score=0;z=0;x=0;
	    int err,er,k; char choi,ch;
	    char  name[30] ; char ScoreBuffer[10];
		int PlayerName=0;  
		printf("\n\t\t..##..weLCOme..##..  to world BrainCon GAME....");
	    printf("\n\n\tEnter the player name ::");
	    scanf("%s",&name);
	    FILE *fp;
	    if (pthread_mutex_init(&lock, NULL) != 0) {
        	printf("\n mutex init has failed\n");
        	return 1;
    	}   
   // while(i < 1)
    //{
      
        er = pthread_create(&(ttid[0]), NULL, &do_Calculate_Score, NULL);
        err = pthread_create(&(tid[0]), NULL, &do_Take_Result, NULL);
        if (err != 0)
        	printf("\ncan't create thread :[%s]", strerror(err));
        if (er != 0)
            printf("\ncan't create thread :[%s]", strerror(er));
      //  i++;
    //}
      
   // k=0;
    //while(k<8){
	
        pthread_join(ttid[0], NULL);
          //pthread_join(tid[1], NULL);
        pthread_join(tid[0], NULL);
          //pthread_join(ttid[1], NULL);
      // k++;}
        pthread_mutex_destroy(&lock);
        pthread_kill(ttid[k], NULL);
        pthread_kill(tid[k], NULL);
      /* printf("\n Do you want to save the history  press [y/n]\n");
        scanf("%c" , &choi);
        if(choi=="y" || choi =="Y" ) {
      		fp=fopen("GameHistory.txt","w");
      	if(fp==NULL) {
			printf("\n ## ERROR  ## Sorry File can not open .");
      		exit(0); 
		}
		else printf("....\nfile open ");
		  itoa(score,ScoreBuffer,10);   
      	 for(i=0;i<strlen(name);i++)
      	 {	
	       if(strlen(name) > PlayerName){
		        PlayerName++;
      	          fputc(name[i],fp);
             }
             fputc("  ",fp);
             for(i=0;i<strlen(ScoreBuffer);i++)
              fputc(ScoreBuffer[i],fp);
	  	 } } */
	printf("\n\n Do you want to play [y/n] \n");
	scanf("%c",&ch);
	if(ch == "y" || ch == "Y") continue;
	else break;
    }
    return 0;
}
