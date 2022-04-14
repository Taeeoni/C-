#include <stdio.h>

	// �����̿�� ����
	const int ALL_1D_ADULT = 62000, ALL_1D_TEEN = 54000 ,ALL_1D_KID = 47000 ,ALL_1D_BABY = 15000;	
	const int ALL_A4_ADULT = 50000, ALL_A4_TEEN = 43000, ALL_A4_KID = 36000, ALL_A4_BABY = 15000;
	
	// ��ũ�̿�� ����
	const int PARK_1D_ADULT = 59000, PARK_1D_TEEN = 52000, PARK_1D_KID = 46000, PARK_1D_BABY = 15000;
	const int PARK_A4_ADULT = 47000, PARK_A4_TEEN = 41000, PARK_A4_KID = 35000, PARK_A4_BABY = 15000;
	
	// �ֹε�Ϲ�ȣ �м�
	const int PROTECT_CITIZEN_NUM = 10000000;
	const int OLD_GENERATION = 18000000, NEW_GENERATION = 19000000;
	
	// ���̿� ���� ����
	const int MIN_BABY = 1, MIN_KID = 3, MIN_TEEN = 12, MIN_ADULT = 18, MIN_OLD = 65; 
	
	// ������
	const int DISABLED = 0.5, NATIONAL_MERIT = 0.5, SOLDIER = 0.49, PREGNANT = 0.5, MANY_CHILDREN = 0.3;

	
void errorMessagePrint(){
	
}

int orderTicketClass(int ticketClass){
	
	while(ticketClass != 1 && ticketClass != 2){ // ticketClass 1,2�� �ƴ϶�� �ݺ�  
	printf("�̿�� ������ �����ϼ��� : \n");
	printf("1. �����̿�� (�Ե����� + �μӹڹ���)\n");
	printf("2. ��ũ�̿�� (�Ե�����)\n");
	scanf("%d", &ticketClass);
	}
	return ticketClass;
}

int orderTicketType(int ticketType){
	
	while(ticketType != 1 && ticketType != 2){ // 1, 2�� �ƴ϶�� �ݺ� 
	printf("������ �����ϼ��� : \n");
	printf("1. 1Day\n");
	printf("2. After4 (���� 4�ú��� ����)\n");
	scanf("%d", &ticketType);
	}
	return ticketType;
}

int orderCitizenNum(int citizenNum){
	printf("�ֹι�ȣ�� ���ڸ� ù°�ڸ����� �Է��ϼ��� (ex:9304081) : \n");
	scanf("%d", &citizenNum);
	citizenNum += PROTECT_CITIZEN_NUM;
}


int calcAge(int citizenNum){
	int today = 20220414; // ���� ��¥ 
	int gender = citizenNum % 10; // �ֹι�ȣ ���ڸ� 1, 2, 3, 4 
	int birthDay = citizenNum / 10;
	if (gender >= 3){
		birthDay += NEW_GENERATION;
	} else {
		birthDay += OLD_GENERATION;
	}
	int age = (today - birthDay) / 10000;
	return age;
}

int calcAgeGroup(int manAge){
	int ageGroup;
	if(manAge < MIN_BABY){
		ageGroup = 0; //������ 
	} else if(manAge >= MIN_BABY && manAge < MIN_KID){
		ageGroup = 1; // ����  
	} else if (manAge >= MIN_KID && manAge <= MIN_TEEN){
		ageGroup = 2; // ���
	} else if (manAge > MIN_TEEN && manAge <= MIN_ADULT){
		ageGroup = 3; // û�ҳ� 
	} else if (manAge > MIN_ADULT && manAge < MIN_OLD){
		ageGroup = 4; // � 
	} else if (manAge >= MIN_OLD){
		ageGroup = 5;// ���� 
	} else {
		printf("ERROR");
	}
	return ageGroup;
}	


int calcPriceProcess(int ageGroup, int ticketClass, int ticketType){
	if(ticketClass == 1){ // ALL
		if(ticketType == 1){ // 1D
			if(ageGroup == 4){
				return ALL_1D_ADULT;
			} else if(ageGroup == 3){
				return ALL_1D_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return ALL_1D_KID;
			} else if(ageGroup == 1){
				return ALL_1D_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}
		} else if(ticketType == 2){ //A4
			if(ageGroup == 4){
				return ALL_A4_ADULT;
			} else if(ageGroup == 3){
				return ALL_A4_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return ALL_A4_KID;
			} else if(ageGroup == 1){
				return ALL_A4_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}		
		} else {
			printf("ERROR");
		}
		
	} else if(ticketClass == 2){ // PARK
		if(ticketType == 1){ // 1D
			if(ageGroup == 4){
				return PARK_1D_ADULT;
			} else if(ageGroup == 3){
				return PARK_1D_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return PARK_1D_KID;
			} else if(ageGroup == 1){
				return PARK_1D_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}
		} else if(ticketType == 2){ //A4
			if(ageGroup == 4){
				return PARK_A4_ADULT;
			} else if(ageGroup == 3){
				return PARK_A4_TEEN;
			} else if(ageGroup == 2 || ageGroup == 5){
				return PARK_A4_KID;
			} else if(ageGroup == 1){
				return PARK_A4_BABY;
			} else if(ageGroup == 0){
				return 0;
			} else{
				printf("ERROR");
			}
		} else {
			printf("ERROR");
		}
	}
}

int orderTicketCount(int ticketCount, int price){
	printf("��� �ֹ��Ͻðڽ��ϱ�?(�ִ� 10��)\n");
	scanf("%d", &ticketCount);
	price *= ticketCount;
	return price;
}

int orderPreferClass(int preferClass){
	
	while(preferClass < 1 || preferClass > 6){
	printf("�������� �����ϼ���.\n");
	printf("1. ���� (���� ���� �ڵ�ó��)\n");
	printf("2. ����� ���\n");
	printf("3. ���������� ���\n");
	printf("4. �ް��庴 ���\n");
	printf("5. �ӻ�� ���\n");
	printf("6. �ٵ��� �ູī�� ���\n");
	scanf("%d", &preferClass);
	}
	
	return preferClass;	
}

int calcDiscount(int price, int preferClass, int ticketClass){
	if(preferClass == 2){
		price *= DISABLED;
	} else if(preferClass == 3){
		price *= NATIONAL_MERIT;
	} else if(preferClass == 4 && ticketClass == 1){
		price *= SOLDIER;
	} else if(preferClass == 5 && ticketClass == 1){
		price *= PREGNANT;
	} else if(preferClass == 6 && ticketClass == 1){
		price *= MANY_CHILDREN;
	}
	return price;
}

void savedInforms (int ticketClass, int ticketType, int ageGroup, int ticketCount, int price, int preferClass, int position, 
					int inputList [][6]){
	
	inputList[position][0] = ticketClass;
	inputList[position][1] = ticketType;
	inputList[position][2] = ageGroup;
	inputList[position][3] = ticketCount;
	inputList[position][4] = price;
	inputList[position][5] = preferClass;
}


void inputData(int position, int inputList[][6]){
	int ticketClass = 0;
	int ticketType = 0;
	int citizenNum = 0;
	int manAge = 0;
	int ageGroup = 0;
	int price = 0;
	int ticketCount = 0;
	int preferClass = 0;
	
	ticketClass = orderTicketClass(0);
	ticketType = orderTicketType(0);
	citizenNum = orderCitizenNum(0);
	manAge = calcAge(citizenNum);
	ageGroup = calcAgeGroup(manAge);
	price = calcPriceProcess(ageGroup, ticketClass, ticketType);
	price = orderTicketCount(0, price);
	preferClass = orderPreferClass(0);
	if(preferClass != 1){
		price = calcDiscount(price, preferClass, ticketClass); 
	}
	
	savedInforms(ticketClass, ticketType, ageGroup, ticketCount, price, preferClass, position, inputList);
	
}






  
void entrancePrint(int ticketClass, int ticketType, char* ageGroup, int ticketCount, int price, int preferClass){

	printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n");
	printf("%d  %d  %s  %d  %d  %d", ticketClass, ticketType, ageGroup, ticketCount, price, preferClass);
			
}


int main() {
	
	int totalPrice = 0; // �ֹ� �Ѿ� 
	int position = 0; // inputList �� �߰��� ���  
	int filePosition = 0; // ���� ��� ù�� ���� 
	int inputList [100][6] = {0}; // �ֹ����� ���� 
	
	
	

	while(true){
		inputData(position, inputList);	
		//������ ����  
		int continueSelect;
		printf("��� �߱� �Ͻðڽ��ϱ�?\n");
		printf("1. Ƽ�� �߱�\n");
		printf("2. ����\n");
		scanf("%d", &continueSelect);
		
		if(continueSelect == 2){
			break;
		}	
		
		position++; // �迭��ġ ���� 
	} 

}



