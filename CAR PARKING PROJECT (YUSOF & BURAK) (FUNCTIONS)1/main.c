/* VEHICLE PARKING PROJECTS*/

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>   /*srtlen, strcmp, strcpy and etc..*/
#include <conio.h>    /*System cls*/
#include <time.h>     /*Include time */
#include <windows.h>  /*In case it is needed*/ 
#include <math.h>     /*In case it is needed*/
#include <dos.h>      /*In case it is needed*/

struct vehicle
{
	char name     [25];
	char lastname [25];
	char vnumb    [25];
	char unumb    [25];

} y[100];

/*Global Variables*/

int i; //Used for (for loop)
int j; //Used for (for loop)
int r; //To take row number from user
int c; //To take colom number from user*/

//int z; 
//int k;
//int lot;

FILE *fcars;   /*Writes the cars info to files so admin can view parking info*/
FILE *fbuses;  /*Writes the buses info to files so admin can view parking info*/
FILE *fbikes;  /*Writes the bikes info to files so admin can view parking info*/
	
int slots [5][10]; /* PARKED VEHICLES SHOWNN IN 2D (CARS,BUSES & BIKES) */
int totalvehicles; /* STORES NUMBER OF VEHICLE PARKED (CARS,BUSES & BIKES) */
int numofbikes ;   /* STORES NUMBERS OF BIKES PARKED  */
int numofcars ;    /* STORES NUMBERS OF CARS PARKED */
int numofbuses ;   /* STORES NUMBERS OF BUSES PARKED */

int first_choise (); /*Where the user chooses which part he want to access (Admin, Customer or Exit)*/
int log_in (); /*To check if login info is correct then access to admin menu if not keep try again*/
int admin (); /*Choises available only for admin*/
int customer (); /*Choises available only for customer*/
int vehicle (); /*To choose type of vehicle (Car, Bus or Bike)*/
int parking_order (); /*View parking order in 2D array*/
int cost (); /*View the prices for customer*/
int parked_vehicle_info (); /*Number of vehicles parked (Cars, Buses and Bikes)*/
int read_file (); /*For admin to get vehivles info*/
int leaving_vehicles (); /*To remove a vehicle from parking and empty 1 slot*/
int leaving_vehicles_order (); /*To free the parking [X] to [A]*/
int dos_interance (); /*First Thing To be Displayed In c Screen*/
int search_vehicle_by_vnumber ();  /*By typing vehicle number all info are displayed*/ 
int search_vehicle_by_unumber (); /*By typing mobile number all info are displayed*/
int search_vehicle_by_name (); /*By typing name all info are displayed*/
int time_display (); /*View date and time in program*/
int take_info_cars (); /*Take info to be stored in str and be diplayed by search (Cars)*/
int take_info_buses ();/*Take info to be stored in str and be diplayed by search (Buses)*/
int take_info_bikes ();/*Take info to be stored in str and be diplayed by search (Bikes)*/

int customer_choise ()
{
	 int open;
	 
	 printf("DO YOU WANT TO MAKE OTHER OPERATION \nPRESS 1 (YES) ANYKEY FOR (NO):");
     scanf(" %d", &open);
     
     if ( open == 1 )
     {
     	system("cls");
     	customer ();
	 }
	 
	 else
	 {
	 	exit (0);
	 }
}

int admin_choise ()
{
	 int opeen;
	 
	 printf("DO YOU WANT TO MAKE OTHER OPERATION \nPRESS 1 (YES) ANYKEY FOR (NO):");
     scanf(" %d", &opeen);
     
     if ( opeen == 1 )
     {
     	system("cls");
     	admin ();
	 }
	 
	 else
	 {
	 	exit (0);
	 }
}

int take_info_cars ()
{	
    printf("\n");
    
    fprintf(fcars, "CAR\n");
    
    fflush(stdin);//Delete stdin.Buffer area deleted.s
    printf("Enter First Name:");
    gets(y[100].name);
    fprintf(fcars, "First Name: %s\n", y[100].name);
    
    fflush(stdin);
    printf("Enter Last Name:");
    gets(y[100].lastname);
    fprintf(fcars, "Last Name: %s\n", y[100].lastname);
    
    fflush(stdin);
    printf("Enter Vehicle Number:");
    gets(y[100].vnumb);
    fprintf(fcars, "Vehicle Number: %s\n", y[100].vnumb);
    
    fflush(stdin);
    printf("Enter Your Number:");
    gets(y[100].unumb);
    fprintf(fcars, "Customer Number: %s\n", y[100].unumb);
    
    fclose(fcars);
    
    numofcars++;
    totalvehicles++;
}	

int take_info_buses ()
{
	
	printf("\n");
    
    fprintf(fbuses, "BUS\n");
    
    
    
    fflush(stdin);
    printf("Enter Name & Last Name:");
    gets(y[100].lastname);
    fprintf(fbuses, "Last Name: %s\n", y[100].lastname);
    
    fflush(stdin);
    printf("Enter Vehicle Number:");
    gets(y[100].vnumb);
    fprintf(fbuses, "Vehicle Number: %s\n", y[100].vnumb);
    
    fflush(stdin);
    printf("Enter Your Number:");
    gets(y[100].unumb);
    fprintf(fbuses, "Customer Number: %s\n", y[100].unumb);
    
    fclose(fbuses);
    
    numofbuses++;
	totalvehicles++;
} 

int take_info_bikes ()
{
	printf("\n");
    
    fprintf(fbikes, "BIKE\n");
    
    fflush(stdin);
    printf("Enter First Name:");
    gets(y->name);
    fprintf(fbikes, "First Name: %s\n", y->name);
    
    fflush(stdin);
    printf("Enter Last Name:");
    gets(y->lastname);
    fprintf(fbikes, "Last Name: %s\n", y->lastname);
    
    fflush(stdin);
    printf("Enter Vehicle Number:");
    gets(y->vnumb);
    fprintf(fbikes, "Vehicle Number: %s\n", y->vnumb);
    
    fflush(stdin);
    printf("Enter Your Number:");
    gets(y->unumb);
    fprintf(fbikes, "Customer Number: %s\n", y->unumb);
    
    fclose(fbikes);
    
    numofbikes++;
	totalvehicles++;
}

int search_vehicle_by_vnumber ()
{
    char num[25];
    
    fflush(stdin);
    printf("Enter Mobile Number:");
    gets(num);
    
    fflush(stdin);
    
    	if(strcmp(num,y[100].vnumb)==0)
            
			{
                printf("\n");
                
                printf("First Name:");
                puts(y[100].name);
                
                printf("Last Name:");
                puts(y[100].lastname);
                
                printf("Customer Number:");
                puts(y[100].unumb);
                
                printf("Vehicle Number:");
                puts(y[100].vnumb);
            
            }
            
        if(strcmp(num,y[100].vnumb)!=0)
        {
        	printf("\nNot Found\n");
		}
        
}	 

int search_vehicle_by_unumber ()
{
    char mnum[25];
    
    fflush(stdin);
    printf("Enter Vehicle Number:");
    gets(mnum);
    
    fflush(stdin);
    
    	if(strcmp(mnum,y[100].unumb)==0)
            
			{
                printf("\n");
                
                printf("First Name:");
                puts(y[100].name);
                
                printf("Last Name:");
                puts(y[100].lastname);
                
                printf("Customer Number:");
                puts(y[100].unumb);
                
                printf("Vehicle Number:");
                puts(y[100].vnumb);
            
            }
            
        if(strcmp(mnum,y[100].unumb)!=0)
        {
        	printf("\nNot Found\n");
		}
        
}

search_vehicle_by_name ()
{
	char namee[25];
    
    fflush(stdin);
    printf("Enter Uere name:");
    gets(namee);
    
    fflush(stdin);
    
    	if(strcmp(namee,y[100].name)==0)
            
			{
                printf("\n");
                
                printf("First Name:");
                puts(y[100].name);
                
                printf("Last Name:");
                puts(y[100].lastname);
                
                printf("Customer Number:");
                puts(y[100].unumb);
                
                printf("Vehicle Number:");
                puts(y[100].vnumb);
            
            }
            
        if(strcmp(namee,y[100].name)!=0)
        {
        	printf("\nNot Found\n");
		}
}

int dos_interance ()
{
	printf("\n\n\n\n\n\n\t\t**********************************************************************************\n");
    printf("\t\t**********************************************************************************\n");
	printf("\t\t**********************************************************************************\n");
	printf("\t\t***                                                                            ***\n");
    printf("\t\t***  W       W    E E E    L         C C C     O O O     M       M    E E E    ***\n");
    printf("\t\t***  W       W    E        L        C         O     O    M M   M M    E        ***\n");
    printf("\t\t***  W   W   W    E E E    L        C         O     O    M   M   M    E E E    ***\n");
    printf("\t\t***  W W   W W    E        L        C         O     O    M       M    E        ***\n");
    printf("\t\t***  W       W    E E E    L L L      C C C    O O O     M       M    E E E    ***\n");
	printf("\t\t***                                                                            ***\n");
	printf("\t\t**********************************************************************************\n");
	printf("\t\t**********************************************************************************\n");
	printf("\t\t**********************************************************************************\n");
	printf("\t\t\t\t\tPRESS ANY KEY TO CONTINUE");
	
	getch();
	system("cls");
}

int leaving_vehicles ()
{
	totalvehicles--;
	int choose4;
	int caar;
	int buus;
	int biike;
		
	printf("\n\n\t**************VEHICLE TYPE**************\n\n");
	printf("\t1-CAR\n");
	printf("\t2-BUS\n");
	printf("\t3-MOTOR\n");

	printf("PLEASE ENTER YOUR CHOISE: ");
	scanf(" %d",&choose4);

	if ( choose4 == 1)
	{
		printf("ENTER CAR NUMBER: ");
		scanf(" %d", &caar);
		
		numofcars--;
		
		leaving_vehicles_order ();

		main ();
	}

	else if ( choose4 == 2)
	{	
	    printf("ENTER BUS NUMBER: ");
		scanf(" %d", &buus);
	
		numofbuses--;
		
		leaving_vehicles_order ();
		
		main ();
	}

	else if ( choose4 == 3)
	{
		printf("ENTER BIKE NUMBER: ");
		scanf(" %d", &biike);
		
		numofbikes--;
		
		leaving_vehicles_order ();
		
		main ();
	}
	
	else
	{
		system("cls");
		printf("PLEASE CHOOSE CAREFULLY\n");
		leaving_vehicles ();
	}
}

int read_file ()
{
	
	fcars   = fopen ("cars.txt", "r");
	fbuses  = fopen ("buses.txt", "r");
	fbikes  = fopen ("bikes.txt", "r");
	
	char cars  [150];
	char buses [150];
	char bikes [150];
	
	while (!feof(fcars))
	{
		fgets(cars,150,fcars);
		puts(cars);
	}
	
	while (!feof(fbuses))
	{
		fgets(buses,150,fbuses);
		puts(buses);
	}
	
	while (!feof(fbikes))
	{
		fgets(bikes,150,fbikes);
		puts(bikes);
	}
	
	fclose(fcars);
	fclose(fbuses);
	fclose(fbikes);
}

int time_display ()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf("\033[1;34m");
  printf ( "\n\t\t\t\tCURRENT TIME AND DATE: %s", asctime (timeinfo) );
  printf("\033[0m");
  return 0;
  
}
int leaving_vehicles_order ()
{
	printf("\n\n\t[A] = AVAILABLE [X] = BOOKED\n\n");
    printf(" 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n");

    for (i = 0; i <= 4; i++) 
	{
        for (j = 0; j <= 9; j++) 
		{
            if (slots[i][j] == 1)
            {
            	printf("[X]\t"); 
			}
            
			else
			{
				printf("[A]\t"); 
			}
                  
        }
        printf("\n\n");
    }
    
    do 
	{      
	  printf("\nPLEASE CHOOSE A COLUMN (1-10): ");
      scanf(" %d", &c);
      
      printf("\nPLEASE CHOOSE A ROW (1-5): ");
      scanf("%d", &r);
	  
	  slots[r - 1][c - 1] = 0;
			    
    } 
    while (r > 5 || c > 10);
	{
    	main();
	}
}

int booking() 
{
    printf("\n\n\t[A] = AVAILABLE [X] = BOOKED\n\n");
    printf(" 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\n");

    for (i = 0; i <= 4; i++) 
	{
        for (j = 0; j <= 9; j++) 
		{
            if (slots[i][j] == 1)
            printf("[X]\t");
			          
            else
            printf("[A]\t");        
        }
        printf("\n\n");
    }
    
    do 
	{      
	  printf("\nPLEASE CHOOSE A COLUMN (1-10): ");
      scanf(" %d", &c);
      
      printf("\nPLEASE CHOOSE A ROW (1-5): ");
      scanf("%d", &r);
      
	  printf("YOUR SLOT IS %d - %d\n", c, r);
	  
	  slots[r - 1][c - 1] = 1;
			    
    } 
    while (r > 5 || c > 10);
	{
    	main();
	}
        
} 
           
int parked_vehicle_info () 
{
	printf("\n\t************BOOKED SLOTS*************");
	printf("\n\t[1] TOTAL VEHICLES PARKED ARE %d FROM 50\n",totalvehicles);
	printf("\t[2] TOTAL CARS  PARKED ARE %d\n",numofcars);
	printf("\t[3] TOTAL BUSES PARKED ARE %d\n",numofbuses);
	printf("\t[4] TOTAL BIKES PARKED ARE %d\n\n",numofbikes);
	printf("\t************AVAILABLE SLOTS*************");
	printf("\n\t[1] TOTAL SLOTS AVAILABLE ARE %d\n",50-totalvehicles);

}

int cost ()
{
	printf("\n\t[1] FROM 1-3 HOURS    ........................  (10TL)\n");
	printf("\t[2] FROM 4-9 HOURS    ........................  (20TL) \n");
	printf("\t[3] WHOLE DAY         ........................  (30TL)\n");
}

int main ()
{
	
	dos_interance ();
	
	time_display ();
	
	printf("\n\t\t*************************************************************************\n");
	printf("\t\t                   WELCOME TO VEHICLE PARKING PROJECT                    \n");
	printf("\t\t*************************************************************************\n\n");


    printf("================\n\t[1] ADMIN\n\n");
    printf("\t[2] CUSTOMER\n\n");
    printf("\t[3] EXIT\n================\n");

	
	
	first_choise ();
}

int first_choise () 
{
	int a;
	
	printf("ENTER YOUR CHOICE:");
	scanf(" %d",&a);
	
	if ( a == 1)
	{
		system("cls");
		log_in();
	}

	else if ( a == 2)
	{
		system("cls");
		customer();
	}

	else if ( a == 3)
	{
		printf("THANKS FOR USING OUR APP AND HOPE TO SEE YOU SOON\n");
		exit(0);
	}

	else
	{
		system("cls");
		printf("TRY AGAIN\n");
		main ();
	}
}

int log_in ()
{
	char user [15];
    char pass [15];
    
    printf("\n\t\t*************************************************************************\n");
	printf("\t\t               TO ACCESS TO THIS PAGE YOU MUST BE AN ADMIN               \n");
    printf("\t\t                PLEASE DO NOT TRY TO PLAY WITH THE SYSTEM               \n");
	printf("\t\t*************************************************************************\n\n"); 
	
	sign_in:

	printf("ENTER USERNAME: ");
    scanf(" %s" ,user);

    printf("ENTER PASSWORD: ");
    scanf(" %s" ,pass);

	if ( ( (strcmp (user,"user") == 0) || (strcmp (user,"burak") == 0)||(strcmp (user,"yusof") == 0))  && ( strcmp (pass,"1234") == 0) )
    {
        printf("SUCCESSFULLY LOGIN\n");
        system("cls");
        admin ();
    }

    else
    {
    	printf("\a");
        //system("cls");
        printf("\033[1;31m");
        printf("\n\tWARNING\n");
        printf("\tTRY AGAIN\n\n");
        printf("\033[0m"); 
        goto sign_in;
    }
}

int admin ()
{
	int choose2;
	printf("\n\n\t**************FOR ADMIN*****************\n\n");
	/*View all vehicles info (Cars,Buses or Bikes) after restart the programm*/
	printf("\t[1] VIEW PARKING INFO (HISTORY)\n"); 
	printf("\t[2] VEWIE BOOKED SLOTS\n"); /*How many slots are booked*/
	printf("\t[3] SEARCH VEHICLE INFO BY VNUMBER\n"); /*View info by vehicle number (Car,Bus or Bike)*/
	printf("\t[4] SEARCH VEHICLE INFO BY UNUMBER\n");
	printf("\t[5] SEARCH VEHICLE INFO BY NAME\n");
	printf("\t[6] RETURN BACK\n");
	printf("\t[7] EXIT\n\n");
	
	printf("ENTER YOUR CHOICE:");
	scanf(" %d" ,&choose2);

	if ( choose2 == 1)
	{
		system("cls");
		read_file ();
		admin_choise ();
	}

	else if ( choose2 == 2)
	{
		system("cls");
	    parked_vehicle_info ();
	    admin_choise ();
	}

	else if ( choose2 == 3)
	{
		system("cls");
		search_vehicle_by_vnumber ();
		admin_choise ();
	}

	else if ( choose2 == 4)
	{
		system("cls");
		search_vehicle_by_unumber ();
		admin_choise ();
	}
	
	else if ( choose2 == 5)
	{
		system("cls");
		search_vehicle_by_name ();
		admin_choise ();
	}
	
	else if ( choose2 == 6)
	{
		system("cls");
		main ();
	}
	
	else if ( choose2 == 7)
	{
		printf("THANKS FOR USING OUR APP AND HOPE TO SEE YOU SOON\n");
		exit(0);
	}

	else
	{
		system("cls");
		printf("PLEASE CHOOSE CAREFULLY\n");
		admin();
	}
}

int customer ()
{

	int choose1;
	printf("\n\n\t**************FOR CUSTOMAR**************\n\n");
	printf("\t[1] ARRIVING VEHICLES\n"); /*To add an arriving vehicl info and add 1 in slots*/
	printf("\t[2] VIEW PARKING ORDER\n"); /*2D array of slots*/
	printf("\t[3] CAR LEAVING\n"); /*Delet a car from 2D and system*/
	printf("\t[4] COST\n");       /*View the prices to the customers*/
	printf("\t[5] RETURN BACK\n");
	printf("\t[6] EXIT\n");
	
	printf("\t****************************\n\n");

	printf("PLEASE ENTER YOUR CHOISE: ");
	scanf(" %d" ,&choose1);

	if ( choose1 == 1)
	{
		system("cls");
		vehicle ();
		customer_choise ();
	}

	else if ( choose1 == 2)
	{
		system("cls");
		parking_order ();
		customer_choise ();
	}

	else if ( choose1 == 3)
	{
		system("cls");
		leaving_vehicles ();
	}

	else if ( choose1 == 4)
	{
		system("cls");
		cost ();
		customer_choise ();
	}

	else if ( choose1 == 5)
	{
		system("cls");
		main ();
	}

	else if ( choose1 == 6)
	{
		printf("THANKS FOR USING OUR APP AND HOPE TO SEE YOU SOON\n");
		exit(0);
	}

	else
	{
		system("cls");
		printf("PLEASE CHOOSE CAREFULLY\n");
		customer();
	}
}

int vehicle ()
{
	int choose3;
	int t;
		
	fcars  = fopen ("cars.txt",  "ab+");
	fbuses = fopen ("buses.txt", "ab+");
	fbikes = fopen ("bikes.txt", "ab+");
	
	sttarr:

	printf("\n\n\t**************VEHICLE TYPE**************\n\n");
	printf("\t[1] CAR\n");
	printf("\t[2] BUS\n");
	printf("\t[3] MOTOR\n");
	printf("\t[4] RETURN BACK\n");
	printf("\t[5] EXIT\n");

	printf("PLEASE ENTER YOUR CHOISE: ");
	scanf(" %d",&choose3);

	if ( choose3 == 1)
	{
        take_info_cars ();
        
		booking ();

	}

	else if ( choose3 == 2)
	{
		take_info_buses ();
	    
		booking ();
	}

	else if ( choose3 == 3)
	{
		take_info_bikes ();
		
		booking ();
	}

	else if ( choose3 == 4)
	{
		system("cls");
		customer ();
	}

	else if ( choose3 == 5)
	{
		printf("THANKS FOR USING OUR APP AND HOPE TO SEE YOU SOON\n");
		exit(0);
	}

	else
	{
		system("cls");
		printf("PLEASE CHOOSE CAREFULLY\n");
		customer ();
	}
		
}

int parking_order ()
{
	printf("\n\n\t**************FOR CUSTUMOR**************\n\n");
	printf("\n\n\t[A] = AVAILABLE [X] = BOOKED\n\n");
    printf(" 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t10\n");
    for ( i = 0; i <= 4; i++)
    {
        for ( j = 0; j <= 9; j++)
        {
            if ( slots[i][j] == 1)
            {
            	printf("[X]\t");
			}
                
            else
            {
            	printf("[A]\t");
			}
                
        }
        printf("\n\n");
    }
}
