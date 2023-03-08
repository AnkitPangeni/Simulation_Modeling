
// 4 digit poker test
#include <stdio.h>
#define TAB_CHISQUARE_4D 9.49
#define TAB_CHISQUARE_3D 5.99

int main()
{

int num;
printf("Please choose your test:");
printf("\n 1. Three digit poker test");
printf("\n 2. Four digit poker test\n");
scanf("%d",&num);

	int i,n;
	
	int four_diff,four_of_a_kind, three_of_a_kind, one_pair, two_pair; // for 4 digit poker
	float CAL_CHISQUARE=0.0;
	float probabilities_4d[5]={0.504, 0.001, 0.036, 0.432, 0.027};
	float expected_frequency_4d[5];
	
	int three_diff; // for 3 digit poker
	float probabilities_3d[3]={0.72, 0.01, 0.27};
	float expected_frequency_3d[3];

	
    switch(num){
	
	case 2:
		
    printf("\nHow many numbers did you generate:");
	scanf("%d", &n);
	
	printf("\nEnter the observed frequencies of: \n");
	printf("\nFour different digits:");
	scanf("%d", &four_diff);
	
	printf("\nFour same digits:");
	scanf("%d", &four_of_a_kind);
	
	printf("\nThree of a kind:");
	scanf("%d", &three_of_a_kind);
	
	printf("\nOne Pair:");
	scanf("%d", &one_pair);
	
	printf("\nTwo Pair:");
	scanf("%d", &two_pair);
	
	if ((four_diff+four_of_a_kind+ three_of_a_kind+ one_pair+ two_pair)!=n){
		printf("\nThe sum is not equal to %d",n);
	}
	else {
	
	
	printf("----------------------------------------------------------------------");
	int observed_frequency_4d[5] ={four_diff,four_of_a_kind, three_of_a_kind, one_pair, two_pair}; 
	printf("\nThe Observed frequencies are:\n");
	for(i=0; i<5; i++)
	{
		printf("\t%d", observed_frequency_4d[i]);
		expected_frequency_4d[i]=probabilities_4d[i]*n;
	}
	
	printf("\nAnd their respective expected frequencies are:\n");
	
	for(i=0; i<5; i++)
	{
		
		printf("\t%d",(int)expected_frequency_4d[i]);
	}
	
	for(i=0;i<5;i++)
	{
		CAL_CHISQUARE+=
	((
	(observed_frequency_4d[i]-expected_frequency_4d[i])*
	(observed_frequency_4d[i]-expected_frequency_4d[i]))
	/expected_frequency_4d[i]);
	}
		printf("\n----------------------------------------------------------------------");

	printf("\n \n The sum of calculated chi square statistics is : %f ",CAL_CHISQUARE);
	
	printf("\n The tabulated value for chisquare is %f",TAB_CHISQUARE_4D);
	if(CAL_CHISQUARE<= TAB_CHISQUARE_4D){
		printf("\n\nSo,the generated random numbers are independent.");
	}
	else
		printf("\n\nSo,the generated random numbers are not independent.");
	
}
break;

case 1:
	
    printf("\nHow many numbers did you generate:");
	scanf("%d", &n);
	
	printf("\nEnter the observed frequencies of: \n");
	printf("\nThree different digits:");
	scanf("%d", &three_diff);
	
	printf("\nThree same digits:");
	scanf("%d", &three_of_a_kind);
	
	printf("\nOne Pair:");
	scanf("%d", &one_pair);
	
	
	if ((three_diff+three_of_a_kind+ one_pair)!=n){
		printf("\nThe sum is not equal to %d",n);
	}
	else {
		
	printf("----------------------------------------------------------------------");
	int observed_frequency_3d[3] ={three_diff,three_of_a_kind,one_pair}; 
	printf("\nThe Observed frequencies are:\n");
	for(i=0; i<3; i++)
	{
		printf("\t%d", observed_frequency_3d[i]);
		expected_frequency_3d[i]=probabilities_3d[i]*n;
	}
	
	printf("\nAnd their respective expected frequencies are:\n");
	
	for(i=0; i<3; i++)
	{
			printf("\t%d",(int)expected_frequency_3d[i]);
	}
	
	for(i=0;i<3;i++)
	{
		CAL_CHISQUARE+=
	((
	(observed_frequency_3d[i]-expected_frequency_3d[i])*
	(observed_frequency_3d[i]-expected_frequency_3d[i]))
	/expected_frequency_3d[i]);
	}
		printf("\n----------------------------------------------------------------------");

	printf("\n \n The sum of calculated chi square statistics is : %f ",CAL_CHISQUARE);
	
	printf("\n The tabulated value for chisquare is %f",TAB_CHISQUARE_3D);
	if(CAL_CHISQUARE<= TAB_CHISQUARE_3D){
		printf("\n\nSo,the generated random numbers are independent.");
	}
	else
		printf("\n\nSo,the generated random numbers are not independent.");
	
}
	
	break;
	
	default: printf("\nPlease choose either 1 or 2"); break;
}
}

