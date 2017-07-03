#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

char *getinput(char *buffer, size_t buflen) {
	printf("$$ ");
	return fgets(buffer, buflen, stdin);
}

int main(int argc, char **argv) {
	char buf[1024];
	pid_t pid;
	int status;

	while (getinput(buf, sizeof(buf))) {
		buf[strlen(buf) - 1] = '\0';

		/* Place your code to check "exit". If so, then exit */
		if(strcmp(buf,"exit")==0)
                {
                        exit(0);
                }
	if(strstr(buf,"|")!=NULL)
	{
		char filename1[20]; char filename2[20];
		int i;
                        for(i=0;i<strlen(buf);i++)
                        {
                                if(buf[i]=='<')
                                {       int k=0;
                                        int j;
                                        for(j=i+1;i<strlen(buf);j++)
					{
					if(buf[j]=='|'){break;}
					filename1[k++]=buf[j];}
                                }	
			}
			char createCommand1[100];
                        snprintf(createCommand1, sizeof(createCommand1), "cat %s > temp.txt",filename1);
                        system(createCommand1);
			for(i=0;i<strlen(buf);i++)
			{
			
                                        if(buf[i]=='>')
                                        {
                                        int k=0;
                                        int j;
                                        for(j=i+1;i<strlen(buf);j++)
                                        {filename2[k++]=buf[j];}
                         		}
			
                        }
	 char createCommand2[100];
         snprintf(createCommand2, sizeof(createCommand2), "cat temp.txt > %s",filename2);
         system(createCommand2);

	}
	else
	{
		if(strstr(buf,"read")!=NULL)
		{	
			char filename[20];
			int i;
			for(i=0;i<strlen(buf);i++)
			{
				if(buf[i]=='<')
				{	int k=0;
					int j;
					for(j=i+1;i<strlen(buf);j++){filename[k++]=buf[j];}
				}
			}
			char createCommand[100];
			snprintf(createCommand, sizeof(createCommand), "cat %s > temp.txt",filename);
			system(createCommand);
		}
		if(strstr(buf,"write")!=NULL)
                {       
			char filename[20];
			int i;
                        for(i=0;i<strlen(buf);i++)
                        {
                                if(buf[i]=='>')
                                {       int k=0;
                                        int j;
                                        for(j=i+1;i<strlen(buf);j++){filename[k++]=buf[j];}
                                }
                        }
                        char createCommand[100];
                        snprintf(createCommand, sizeof(createCommand), "cat temp.txt > %s",filename);
                        system(createCommand);
                }
		if(strstr(buf,"append")!=NULL)
                {
                        char filename[20];
                        int i;
                        for(i=0;i<strlen(buf);i++)
                        {
                                if(buf[i]=='>')
                                {       int k=0;
                                        int j;
                                        for(j=i+2;i<strlen(buf);j++){filename[k++]=buf[j];}
                                }
                        }
                        char createCommand[100];
                        snprintf(createCommand, sizeof(createCommand), "cat temp.txt >> %s",filename);
                        system(createCommand);
                }
	}

		//printf("PID = %d",(pid=fork()));
		
		printf("command: %s",buf);
		
		if((pid=fork()) == -1) {
			fprintf(stderr, "shell: can't fork: %s\n", strerror(errno));
			continue;
		} else if (pid == 0) {
		if(strstr(buf, "read") != NULL)
		{	int i;
			printf("if read. ");
			for(i=0;i<strlen(buf);i++)
			{	printf("looping in buf. ");
				if(buf[i]=='<')
				{
					printf("t value is: %s\n",buf[i]);
				}
			}
			//printf("File read successfully. Command: %s",buf);	
		}
		else
		{
			
		}






			exit(EX_OK);
		}

		if ((pid=waitpid(pid, &status, 0)) < 0)
			fprintf(stderr, "shell: waitpid error: %s\n",
					strerror(errno));
	}
	exit(EX_OK);
}

