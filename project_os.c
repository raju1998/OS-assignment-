#include<stdio.h>
#include<malloc.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int counter=0;
struct Process{
    int burst_time,priority,process_pid,arrival_time;
    struct Process* next;
};
struct Process* queue1=NULL;
struct Process* queue2=NULL;
struct Process* queue3=NULL;
void insert(int burst,int prior,int pid);
void FCFS(queue3);
int main()
{
	printf("            ****This Program is for Mulitlevel Queue Scheduling*****\n\n");
    int limit,burst,prior,pid,arr;
    printf("Enter Total Number of Processes: ");
	scanf("%d", &limit);
	printf("\n\n");
	printf("Priority for Queue \n");
	printf("Queue 1 for Round Robin Scheduling                 Range 0-6 \n");  //queue one has range 0 to 6
	printf("Queue 2 for Priority Scheduling                    Range 7-12 \n"); //queue two has range 7 to 12
	printf("Queue 3 for First Come First Serve Scheduling      Range 13-19 \n"); // queue three has rannge  13 to 19
    while(limit--)
    {
        
        printf("Enter the process pid: ");
        scanf("%d",&pid);
        printf("Enter the burst time: ");
        scanf("%d",&burst);
        printf("Enter the priority: ");
        scanf("%d %d",&prior);
        insert(burst,prior,pid);
        

    }
    //roundrobin_scheduling(queue1);\
    //priority_scheduling(queue2);
    //FCFS(queue3);
}

void insert(int burst,int prior,int pid)
{
    struct Process* head=NULL;
    if(prior>=0&&prior<=6)
        head=queue1;
    else if(prior>=7&&prior<=13)
        head=queue2;
    else if(prior>=14&&prior<=20)
        head=queue3;
    else
    {
        printf("Priority must be in the given Range.\n");
        return;
    }
    struct Process* newnode=(struct Process*)malloc(sizeof(struct Process));
    newnode->burst_time=burst;
    newnode->priority=prior;
    newnode->process_pid=pid;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
        if(head==NULL)
        {
        printf("Nothing inside the Queue\n");
        }
    }

        else{
        	struct Process* ptr=head;
            while(ptr->next!=NULL&&ptr->next->priority<prior)
            {
                ptr=ptr->next;
            }
            newnode->next=ptr->next;
            ptr->next=newnode;
            
    }
    if(prior>=0&&prior<=6)
        queue1=head;
    else if(prior>=7&&prior<=13)
        queue2=head;
    else if(prior>=14&&prior<=20)
        queue3=head;
}

int isEmpty1=0,isEmpty2=0,isEmpty3=0;
void roundrobin_scheduling(struct Process* queue1)
{
	int count=10;
    int time_quantum=4;
	if(queue1==NULL)
		{
			printf("No Process in Queue 1 \n");
			return;
		}

	
    struct Process* ptr=queue1;
    if(queue1==NULL||ptr==NULL)
{
printf("There is no process in Queue 1\n");}

    int pcount=0;
    while(count>0&&pcount<5)
    {
        if(isEmpty1==1)
            return;
        if(ptr->burst_time==0)
        {
        if(ptr->next==NULL)
        	{
			ptr=queue1;
        	pcount++;
			}
        else
        	ptr=ptr->next;
        if(pcount>=5)
            isEmpty1=1;
        continue;
        }

        if(ptr->burst_time<=time_quantum&&time_quantum<=count)
        {
            printf("\nProcess with pid:%d had been exectued completely\n",ptr->process_pid);
            count=count-ptr->burst_time;
            ptr->burst_time=0;
        }
        else if(time_quantum<=count)
        {
            printf("\nProcess with pid:%d is executed for 4 units of time and remaining time is %d",ptr->process_pid,(ptr->burst_time-time_quantum));
            ptr->burst_time=ptr->burst_time-time_quantum;
            count=count-time_quantum;
            if(ptr->next==NULL)
            	{
					pcount++;
					ptr=queue1;
				}
            else
                ptr=ptr->next;
        }
        else{
            printf("\nProcess with pid:%d is executed for %d units of time",ptr->process_pid,count);
            ptr->burst_time-=count;
            count=0;
            if(ptr->next==NULL)
        		{
					ptr=queue1;
					pcount++;
				}
        	else
        		ptr=ptr->next;
        	}
    }
}
void FCFS(queue3)
{
    
}
void priority_scheduling(queue2)
{
	
}

