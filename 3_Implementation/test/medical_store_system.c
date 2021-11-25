#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{
	int ch = 0;
	int two_slots = 0;
	int four_slots = 0;
	int vehicleType;
	char vehicleNo[50];
	char dateTime[50];
	time_t t;
	int i = 0;
	int test = 1;
	
	struct vehicle
	{
		int vType;
		char vNo[50];
		char iDate[50];
		char oDate[50];
		int slotId;
		int status;

	}vehicles[1000];
	int vcount = 0;
	int run = 0;

	printf("Parking Lot\n");
	
	printf("Slot Creation\n");
	printf("No of Two wheeler slots:");
	if(test == 1)
	{
		two_slots = 2;
		printf(" Test twowheelers: %d\n",two_slots);
	}
	else
		scanf("%d",&two_slots);

	printf("No of Four wheeler slots:");
	if(test == 1)
	{
		four_slots = 1;
		printf(" Test fourwheelers: %d\n",four_slots);
	}
	else
		scanf("%d",&four_slots);
	
	int twoWheelers[two_slots];
	int fourWheelers[four_slots];
	
	for(i=0;i<two_slots;i++)
	{
		twoWheelers[i] = 0;
	}

	for(i=0;i<four_slots;i++)
	{
		fourWheelers[i] = 0;
	}
	
	printf("Two wheelers slots %d created\nFour wheelers slots %d created\n\n",two_slots,four_slots);

	do
	{
		if(run == 0)
		{
			printf("****Testing Inward*****\n");
		}
		else if(run == 1)
		{
			printf("****Testing Another Inward*****\n");
		}
		else if(run == 2)
		{
			printf("****Testing 4W Inward*****\n");
		}
		else if(run == 3)
		{
			printf("****Testing Duplicate Inward*****\n");
		}
		else if(run == 4)
		{
			printf("****Testing Inward while unavailable slot*****\n");
		}
		else if(run == 5)
		{
			printf("****Testing Outward*****\n");
		}
		else if(run == 6)
		{
			printf("****Testing Invalid Outward*****\n");
		}
		else if(run == 7)
		{
			printf("****Testing Cumulative Report*****\n");
		}
		else if(run == 8)
		{
			printf("****Testing Current Report*****\n");
		}
		else if(run == 9)
		{
			printf("****Testing Exit*****\n");
		}
		printf("1.Inward entry\n2.Outward entry\n3.Total Report\n4.Current Report\n5.Exit\n");
		printf("Select Option: ");
		if(test == 1)
		{
			if(run == 0 || run == 1 || run == 2 || run == 3 || run == 4)
			{
				ch = 1;
			}
			else if(run == 5 || run == 6)
			{
				ch = 2;
			}
			else if(run == 7)
			{
				ch = 3;
			}
			else if(run == 8)
			{
				ch = 4;
			}
			else
			{
				ch = 5;
			}
			printf("Test choice: %d\n",ch);
		}
		else
			scanf("%d",&ch);
		printf("\n");
		switch(ch)
		{
			case 1:
				{
					printf("Inward Entry\n");
					printf("\tEnter Vehicle Details\n");
					printf("\tVehicle Type: 1.Two wheelers, 2.Four wheelers\n");
					printf("\tEnter Option: ");
					
					if(test == 1)
					{
						if(run == 0)
						{
							vehicleType = 1;
							strcpy(vehicleNo,"TN01P01");
						}
						else if(run == 1)
						{
							vehicleType = 1;
							strcpy(vehicleNo,"TN09AB19");
						}
						else if(run == 2)
						{
							vehicleType = 2;
							strcpy(vehicleNo,"AP55A42");
						}
						else if(run == 3)
						{
							vehicleType = 1;
							strcpy(vehicleNo,"TN09AB19");
						}
						else if(run == 4)
						{
							vehicleType = 2;
							strcpy(vehicleNo,"MH03A63");
						}
					}
					else
						scanf("%d",&vehicleType);
					
					if(!(vehicleType == 1 || vehicleType == 2))
					{
						printf("\tInvalid Entry\n\n");
						break;
					}
					
					printf("\tEnter Vehicle Number: ");
					if(test == 1)
					{
						printf("%s\n",vehicleNo);
					}
					else
						scanf("%s",vehicleNo);

					time(&t);
					struct tm *timeinfo;
					timeinfo = localtime(&t);
					strftime(dateTime, strlen("DD-MMM-YYYY HH:MM")+1,"%d-%b-%Y %H:%M",timeinfo);
					
					int freeSlot = -1;
					
					if(vehicleType == 1)
					{
						for(i=0;i<two_slots;i++)
						{
							if(twoWheelers[i] == 0)
							{
								freeSlot = i;
								break;
							}
						}
					}
					else
					{
						for(i=0;i<four_slots;i++)
						{
							if(fourWheelers[i] == 0)
							{
								freeSlot = i;
								break;
							}
						}
					}
					
					if(freeSlot == -1)
					{
						printf("No slots available for parking the vehicle\n");
					}
					else
					{
						int entry = 0;
						for(i=0;i<vcount;i++)
						{
							if(strcmp(vehicleNo,vehicles[i].vNo) == 0 && vehicles[i].status == 1)
							{
							printf("Vehicle already in %d-W slot %d\n",((vehicles[i].vType == 1)?2:4),vehicles[i].slotId);
							entry = 1;
							break;
							}
						}
						if(entry == 0)
						{
							printf("Vehicle Details: %d-W %s InTime:%s\n",((vehicleType == 1)?2:4),vehicleNo,dateTime);
							int pos = vcount++;
							vehicles[pos].vType = vehicleType;
							strcpy(vehicles[pos].vNo,vehicleNo);
							strcpy(vehicles[pos].iDate,dateTime);
							strcpy(vehicles[pos].oDate,"");
							vehicles[pos].status = 1;
							vehicles[pos].slotId = freeSlot+1;
		
							if(vehicleType == 1)
							{
								twoWheelers[freeSlot] = 1;
							}
							else
							{
								fourWheelers[freeSlot] = 1;
							}
						}
					}
					printf("\n");
				}
				
				break;
			case 2:
				{
					printf("Outward Entry\n");
					printf("\tEnter Vehicle Number: ");
					if(test == 1)
					{
						if(run == 5)
						{
							strcpy(vehicleNo,"TN09AB19");
						}
						else if(run == 6)
						{
							strcpy(vehicleNo,"MH03A63");
						}
						printf("%s\n",vehicleNo);
					}
					else
						scanf("%s",vehicleNo);

					time(&t);
					struct tm *timeinfo;
					timeinfo = localtime(&t);
					strftime(dateTime, strlen("DD-MMM-YYYY HH:MM")+1,"%d-%b-%Y %H:%M",timeinfo);
					int vpos = -1;
					
					for(i=vcount-1;i>=0;i--)
					{
						if(strcmp(vehicleNo,vehicles[i].vNo) == 0 && vehicles[i].status == 1)
						{
							vpos = i;
							break;
						}
					}
					
					if(vpos == -1)
					{
						printf("\tVehicle Entry Not found for Outward\n");
					}
					else
					{
						printf("\tVehicle Entry Updated\n");
						if(vehicles[vpos].vType == 1)
						{
							twoWheelers[vehicles[vpos].slotId-1] = 0;
						}
						else
						{
							fourWheelers[vehicles[vpos].slotId-1] = 0;
						}
						strcpy(vehicles[vpos].oDate,dateTime);
						vehicles[vpos].status = 2;
					}
				}
				break;
			case 3:
				{
					printf("Total Report\n");
					for(i=0;i<vcount;i++)
					{
						printf("Vehicle No: %s VehicleType: %d W, InTime: %s, OutTime: %s, Slot: %d, Status: %c\n",
							vehicles[i].vNo,((vehicles[i].vType == 1)?2:4),
							vehicles[i].iDate,vehicles[i].oDate,
							vehicles[i].slotId,((vehicles[i].status == 1)?'I':'O'));
					}
					printf("\n");
				}
				break;
			case 4:
				{
					printf("Current Report\n");
					for(i=0;i<vcount;i++)
					{
						if(vehicles[i].status == 1)
						{
							printf("Vehicle No: %s VehicleType: %d W, InTime: %s, OutTime: %s, Slot: %d, Status: %c\n",
								vehicles[i].vNo,((vehicles[i].vType == 1)?2:4),
								vehicles[i].iDate,vehicles[i].oDate,
								vehicles[i].slotId,((vehicles[i].status == 1)?'I':'O'));
						}
					}

					int availTwo = 0;
					int availFour = 0;
			
					for(i=0;i<two_slots;i++)
					{
						if(twoWheelers[i] == 1)
						{
							availTwo++;
						}
					}

					for(i=0;i<four_slots;i++)
					{
						if(fourWheelers[i] == 1)
						{
							availFour++;
						}
					}
					
					printf("No of TwoWheelers: %d\nNo of FourWheelers: %d\n",availTwo,availFour);
					printf("\n");
				}
				
				break;
			case 5:
				printf("Bye Bye\n");
				break;
			default:
				printf("Invalid Option\n");
				break;
		}
		run++;
	}
	while(ch != 5);

	printf("Exiting\n");
	return 0;
}

