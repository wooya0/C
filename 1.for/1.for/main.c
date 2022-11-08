#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y){
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void sum1(int num) {
	int e_sum = 0, o_sum = 0;			// e(even), o(odd)
	int e_count = 5, o_count = 5;
	for (int i = 1; i <= num; i++) {
		if (i % 2 == 0) {
			e_count++;
			// ¦��
			gotoxy(40, e_count);
			printf("i�� %2d�϶� ¦���� �� : %2d\n", i, e_sum += i);

		}
		else {
			// Ȧ��
			o_count++;
			gotoxy(0, o_count);
			printf("i�� %2d�϶� ¦���� �� : %2d\n", i, o_sum += i);
		}
	}
}

void sum2(int num) {
	int t_sum = 0, f_sum = 0;				//t(third), f(forth)
	int t_count = 5, f_count = 5;
	for (int i = 1; i <= num; i++) {
		if (i % 12 == 0)
			continue;
		if (i % 3 == 0) {
			t_count++;
			gotoxy(0, t_count);
			printf("i�� %2d�϶� 3�� ����� �� : %2d\n", i, t_sum += i);
		}
		if (i % 4 == 0) {
			f_count++;
			gotoxy(40, f_count);
			printf("i�� %2d�϶� 4�� ����� �� : %2d\n", i, f_sum += i);

		}
	}
}

int main(void) {
	system("mode con: cols=80 lines=20");
	int num = 0;
	while (1) {
		gotoxy(35, 1);
		printf("���� : ");
		scanf("%d", &num);
		if (num == -1)
			break;
		else {
			int choice = 0;
			do {					//1. Ȧ¦��, 2.3��4�ǹ��
				gotoxy(30, 4);
				printf("1.Ȧ/¦���� �� ���ϱ�\n");
				gotoxy(30, 5);
				printf("2.3/4�� ��� �� ���ϱ�\n");
				gotoxy(30, 7);
				printf("�޴��� ���� : ");
				scanf("%d", &choice);

			} while (choice < 1 || choice >2);
			if (choice == 1) {		// Ȧ¦��
				system("cls");
				sum1(num);

			}
			else if (choice == 2) {		// 3,4�� ���
				system("cls");
				sum2(num);
			}
		}

		system("pause");
		system("cls");
	}
	return 0;
}