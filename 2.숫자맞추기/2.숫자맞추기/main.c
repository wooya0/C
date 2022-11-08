#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void gotoxy(int x, int y){
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void game1(void) {
	system("cls");		// 화면 클리어
	gotoxy(20, 0);
	printf("====숫자 게임을 시작합니다.====\n");
	int c_num = 0, u_num = 0, count = 0;
	srand(time(NULL));				// seed rand
	c_num = rand() % 99 + 1;

	// 반복 돌면서 정답 입력
	do {
		count++;
		printf("%d번째 숫자 추측\n", count);
		// 컴퓨터가 생성한 숫자 3개를 맞출 때까지 입력
		printf("숫자 한 개 입력 : ");
		scanf("%d", &u_num);

		// low, high hint
		if (c_num > u_num)
			printf("더 큰 수 입력\n");
		if (c_num < u_num)
			printf("더 작은 수 입력\n");
		//정답 맞추면 반복 종료
	} while (c_num != u_num);
	// 최종 결과 출력
	printf("%d번째 시도 만에 정답을 맞추셨습니다.\n", count);
	system("pause");
	system("cls");
}

void game2(void) {
	system("cls");			// 화면 클리어
	gotoxy(20, 0);
	printf("====야구 게임을 시작합니다.====\n");
	int c_num[3] = { 0,0,0 };		// 컴퓨터가 생성할 3개의 배열
	int u_num[3] = { 0,0,0 };		// 플레이어가 입력할 3개의 배열
	int ball = 0, strike = 0, count = 0;
	srand(time(NULL));
	do {
		for (int i = 0; i<= 2; i++)
			c_num[i] = rand() % 9 + 1;		// 랜덤한 숫자를 배열에 저장
		// 생성한 숫자 3개가 모두 다르면 반복 종료
	} while (c_num[0] == c_num[1] || c_num[0] == c_num[2] || c_num[1] == c_num[2]);
	printf("%d %d %d", c_num[0], c_num[1], c_num[2]);
	do {
		//strike와 ball 초기화, count는 증가
		strike = 0;		
		ball = 0;
		count++;
		printf("%d번째 도전\n", count);
		printf("세 개의 정수를 입력하세요 : ");
		// 세 개의 정수를 배열에 저장
		scanf("%d %d %d", &u_num[0], &u_num[1], &u_num[2]);
		for (int i = 0; i <= 3; i++) {
			// 입력한 숫자가 배열 안에 하나라도 있으면 if 안의 문장 실행
			if (u_num[i] == c_num[0] || u_num[i] == c_num[1] || u_num[i] == c_num[2]) {	
				if (u_num[i] == c_num[i])	// 위치가 같을 경우
					strike++;
				else						// 위치가 다를 경우
					ball++;
			}
		} 
		printf("%d ball %d strike\n", ball, strike);
	//정답 맞추면 반복 종료
	} while (strike != 3);
	// 최종 결과 출력
	printf("%d번째 시도 만에 정답을 맞추셨습니다.\n", count);
	system("pause");
	system("cls");
}

int main(void) {
	system("mode con: cols=80 lines=20");
	int num = 0;
	while (1) {
		printf("1.숫자 맞추기\n2.야구게임\n");		// 메뉴
		printf("입력 : ");
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