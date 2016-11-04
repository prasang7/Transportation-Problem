#include <stdio.h>

void main()
{ 

  int c[20][20],i,j,m,n,dem[20],sup[20],sum=0;
  
  printf("\nEnter the row & column:");
  scanf("%d%d",&m,&n);
  
  printf("\nEnter the cost:");
  for(i=0;i<m;i++){ 
    for(j=0;j<n;j++)
     scanf("%d",&c[i][j]);
  }

  printf("\nEnter the demand:");
  for(i=0;i<n;i++)
   scanf("%d",&dem[i]);
  
  printf("\nEnter the supply:");
  for(i=0;i<m;i++)
   scanf("%d",&sup[i]);
  
  printf("\nMatrix:\n");
  for(i=0;i<m;i++){ 
    for(j=0;j<n;j++)
     printf(" %d ",c[i][j]);
    printf("%d",sup[i]);
    printf("\n");
  }

  for(j=0;j<n;j++)
   printf("%d ",dem[j]);
  
  for(i=0,j=0;(i<m&&j<n);){
    if (sup[i]<dem[j]){ 
      sum+=c[i][j]*sup[i];
      dem[j]-=sup[i];
      i++;
    }
    else
    if(sup[i]>dem[j])
    { sum+=c[i][j]*dem[j];
      sup[i]-=dem[j];
      j++;
    }
    else
    if(sup[i]==dem[j])
    { sum+=c[i][j]*dem[j];
      i++;             
      j++;
    }
  }
  
  printf("Minimum transportation cost: \n\n %d",sum);
}