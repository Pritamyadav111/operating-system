#include<stdio.h> 
 #include<conio.h>
 #include<math.h>      

 
int main() 
{ 
      int i, n, total = 0, x, counter = 0, time_quantum; 
      int wa_ti = 0, tu_ti = 0, arr_ti[10], bur_ti[10], temp[10]; 
      float avg_wa_ti, average_tu_ti;
      printf("\nEnter Total Number of Processes:\t"); 
      scanf("%d", &n); 
      x = n; 
      for(i = 0; i < n; i++) 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arr_ti[i]);
            printf("Burst Time:\t");
            scanf("%d", &bur_ti[i]); 
            temp[i] = bur_ti[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &time_quantum); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;) 
      { 
            if(temp[i] <= time_quantum && temp[i] > 0) 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  counter = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - time_quantum; 
                  total = total + time_quantum; 
            } 
            if(temp[i] == 0 && counter == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bur_ti[i], total - arr_ti[i], total - arr_ti[i] - bur_ti[i]);
                  wa_ti = wa_ti + total - arr_ti[i] - bur_ti[i]; 
                  tu_ti = tu_ti + total - arr_ti[i]; 
                  counter = 0; 
            } 
            if(i == n - 1) 
            {
                  i = 0; 
            }
            else if(arr_ti[i + 1] <= total) 
            {
                  i++;
            }
            else 
            {
                  i = 0;
            }
      } 
      avg_wa_ti = wa_ti * 1.0 / n;
      average_tu_ti = tu_ti * 1.0 / n;
      printf("\n\nAverage Waiting Time:\t%f", avg_wa_ti); 
      printf("\nAvg Turnaround Time:\t%f\n", average_tu_ti); 
      return 0; 
  }
	  

