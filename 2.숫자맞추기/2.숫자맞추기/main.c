#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y){
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void game1(void) {
	system("cls");		// ȭ�� Ŭ����
	gotoxy(20, 0);
	printf("====���� ������ �����մϴ�.====\n");
	int c_num = 0, u_num = 0, count = 0;
	srand(time(NULL));				// seed rand
	c_num = rand() % 99 + 1;

	// �ݺ� ���鼭 ���� �Է�
	do {
		count++;
		printf("%d��° ���� ����\n", count);
		// ��ǻ�Ͱ� ������ ���� 3���� ���� ������ �Է�
		printf("���� �� �� �Է� : ");
		scanf("%d", &u_num);

		// low, high hint
		if (c_num > u_num)
			printf("�� ū �� �Է�\n");
		if (c_num < u_num)
			printf("�� ���� �� �Է�\n");
		//���� ���߸� �ݺ� ����
	} while (c_num != u_num);
	// ���� ��� ���
	printf("%d��° �õ� ���� ������ ���߼̽��ϴ�.\n", count);
	system("pause");
	system("cls");
}

void game2(void) {
	system("cls");			// ȭ�� Ŭ����
	gotoxy(20, 0);
	printf("====�߱� ������ �����մϴ�.====\n");
	int c_num[3] = { 0,0,0 };		// ��ǻ�Ͱ� ������ 3���� �迭
	int u_num[3] = { 0,0,0 };		// �÷��̾ �Է��� 3���� �迭
	int ball = 0, strike = 0, count = 0;
	srand(time(NULL));
	do {
		for (int i = 0; i<= 2; i++)
			c_num[i] = rand() % 9 + 1;		// ������ ���ڸ� �迭�� ����
		// ������ ���� 3���� ��� �ٸ��� �ݺ� ����
	} while (c_num[0] == c_num[1] || c_num[0] == c_num[2] || c_num[1] == c_num[2]);
	printf("%d %d %d", c_num[0], c_num[1], c_num[2]);
	do {
		//strike�� ball �ʱ�ȭ, count�� ����
		strike = 0;		
		ball = 0;
		count++;
		printf("%d��° ����\n", count);
		printf("�� ���� ������ �Է��ϼ��� : ");
		// �� ���� ������ �迭�� ����
		scanf("%d %d %d", &u_num[0], &u_num[1], &u_num[2]);
		for (int i = 0; i <= 3; i++) {
			// �Է��� ���ڰ� �迭 �ȿ� �ϳ��� ������ if ���� ���� ����
			if (u_num[i] == c_num[0] || u_num[i] == c_num[1] || u_num[i] == c_num[2]) {	
				if (u_num[i] == c_num[i])	// ��ġ�� ���� ���
					strike++;
				else						// ��ġ�� �ٸ� ���
					ball++;
			}
		} 
		printf("%d ball %d strike\n", ball, strike);
	//���� ���߸� �ݺ� ����
	} while (strike != 3);
	// ���� ��� ���
	printf("%d��° �õ� ���� ������ ���߼̽��ϴ�.\n", count);
	system("pause");
	system("cls");
}

int main(void) {
	system("mode con: cols=80 lines=20");
	int num = 0;
	while (1) {
		printf("1.���� ���߱�\n2.�߱�����\n");		// �޴�
		printf("�Է� : ");
		scanf("%d", &num);
		if (num == 0)
			break;
		if (num == 1)
			game1();
		if (num == 2)
			game2();
	}
	system("pause");
	system("cls");
}