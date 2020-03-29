#include <stdio.h>
#include <stdlib.h>
struct process
{
	char name[5];
	int AT;
	int BT;
	int IBT;
	int TAT;
	int WT;
	int c;
}obj1[4],obj2;

int main()
{
	int x,y,i,j,k,v=0,min,tat,tbt=0;
	float awt;
	float atat;
	for(i=0;i<4;++i)
	{
		printf("\nEnter the process name:\t");
		scanf("%s",obj1[i].name);
		printf("Enter the Arrival Time:\t");
		scanf("%d",&obj1[i].AT);
		printf("Enter the burst time:\t");
		scanf("%d",&obj1[i].BT);
		obj1[i].IBT=obj1[i].BT;
		tbt+=obj1[i].BT;
		obj1[i].c=0;
	}

	for (i=1;i<=1+tbt;i++)
	{
		min=tbt;
		for(j=0;j<4;j++)
		{
			if (obj1[j].AT<=i)
			{
				if((min>=obj1[j].BT)&&(obj1[j].BT>0))
				{
					min=obj1[j].BT;
					obj2=obj1[j];
				}
				if(obj1[j].BT==0 && obj1[j].c==0)
				{
					tat=(i-(obj1[j].AT));
					obj1[j].WT=(tat-(obj1[j].IBT));
					obj1[j].TAT=tat;
					obj1[j].c=2;
				}
			}
		}
		if (obj2.BT!=0)
		obj2.BT=((obj2.BT)-1);
		for(k=0;k<4;k++)
		{
			if(obj2.AT==obj1[k].AT)
			 obj1[k]=obj2;
		}
		
	}
	for (i=0;i<4;i++)
	{
		if (obj1[i].TAT==0 )
		 obj1[i].TAT=(tbt+1)-(obj1[i].AT);
		 obj1[i].WT=(obj1[i].TAT)-(obj1[i].IBT);
		 
		printf("\n%d\t%d",obj1[i].TAT,obj1[i].WT);
		x+=obj1[i].WT;
		y+=obj1[i].TAT;
	}
	awt=x/4.0;
	atat=y/4.0;
	printf("\n\n%f",awt);
	printf("\t%f",atat);

}
