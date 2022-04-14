#include <stdio.h>
 
int leapYear(int year){//윤년 확인  
	int day;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
		day = 366;//윤년이면 366일 
	} else{
		day = 365;//윤년이 아니라면 365일 
	}	
	return day;
}

int main() {
	int year_input; int month_input; 
	printf("년도 입력 : ");
	scanf("%d", &year_input);
	printf("월 입력 : ");
	scanf("%d", &month_input);
	//1900년 1월 1일 월요일 
	int mon_day [] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 월별 일자 수  
	
	int day_sum = 1;
	for(int year1 = 1900; year1 < year_input; year1++){	//년도 차이만큼 일자 더하기 
		day_sum += leapYear(year1);	
	}
	
	for(int month_index = 0; month_index < month_input - 1; month_index++){//월 차이만큼 일자 더하기 
		day_sum += mon_day[month_index];
	}
	//input 년도가 윤년이고 input 월이 3월 이후라면 1일 더하기 
	if(leapYear(year_input) == 366 && month_input > 2){
		day_sum += 1;
	}
	// 1900년도부터 input 년 월까지의 day_sum 구하기 끝
	 
	int day_num = day_sum % 7; // 1일이 무슨요일인지 알기 위해 day_num 변수생성 0:일요일 ~ 6:토요일 
	
	//출력부 
	printf("-------------------------------------------------------\n");
	printf("\t\t%8d년\n", year_input);
	printf("\t\t%6d월\n", month_input);
	printf("-------------------------------------------------------\n");
	printf(" 일\t 월\t 화\t 수\t 목\t 금\t 토\n"); 
	int day; 
	for(int i = 0; i < 7; i++){ // 첫째주 
		if(i < day_num){ // day_num (1일) 전까지는 공백 출력 
			printf(" \t");
		} else{ // i가 1일에 해당하는 나머지에 다달으면 일자 출력 
			printf(" %d\t", day + 1);
			day++;
		}		
	}
	printf("\n");
	int week = 0;
	for(int days = day + 1; days <= mon_day[month_input - 1]; days++){ // 나머지 주 , 월에 알맞는 일까지 출력 
		printf(" %d\t", days);
		week++;
		if(week % 7 == 0){ // 7번 출력했다면 다음라인으로  
			printf("\n");
		}
	}	
}
