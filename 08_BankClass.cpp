// 08_BankClass.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

/*
사용자로부터 입력(이름, 돈) 받아서 저장
1 : 출금 -> 잔액 보여주기
2 : 입금 -> 잔액 보여주기

    < class bank >
    1. 고객 정보 저장(name, ID, money, VVIP)
    2. ID 입력 -> VVIP 여부 확인 -> VVIP이면 환영 메세지 출력
    3. service - 1.입금 2. 출금 -> 잔액 부족 시 불가 메세지 출력
*/

#include <iostream>
#include "BankAccount2.h"

int main()
{
    uint32_t customer{ 0U };
    std::cout << "저장할 고객의 숫자를 입력하시오 -> ";
    std::cin >> customer;
    std::cout << " ───────────────────────" << std::endl;
    
    BankAccount2* customers{ new BankAccount2[customer] };  // 고객 정보를 저장할 클래스 동적 할당

    uint32_t index{ 0U };                                   // 배열의 인덱스 초기화

    for (;;)                                                // 무한 루프
    {
        while (index < customer)                            // 입력 받은 고객 숫자만큼 배열에 정보 저장
        {
            std::cout << "* " << index + 1 << "번째 고객 정보" << std::endl;
            std::cout << "계좌번호를 입력하시오 -> ";
            uint32_t account_number{ 0U };
            std::cin >> account_number;
            customers[index].setAccountNumber(account_number); // = ( *(customers + index)).setAccountNumber(account_number);

            std::cout << "고객이름을 입력하시오 -> ";
            std::string customer_name{ "" };
            std::cin >> customer_name;
            customers[index].setCustomerName(customer_name);

            std::cout << "비밀번호를 입력하시오 -> ";
            uint16_t account_password{ 0U };
            std::cin >> account_password;
            customers[index].setPassWord(account_password);

            std::cout << "초기 입금액을 입력하시오 -> ";
            uint64_t initial_money{ 0UL };
            std::cin >> initial_money;
            customers[index].setMoney(initial_money);

            std::cout << "VVIP 회원인가요? [ 1: VVIP / 0: SILVER ] -> ";
            bool isVVIP{ false };
            std::cin >> isVVIP;
            customers[index].setStateVVIP(isVVIP);

            ++index;    // index를 증가시켜서 다음 배열로 넘어간다.

            std::cout << " ───────────────────────" << std::endl;
        }

        // 메뉴화면 출력
        std::cout << std::endl << std::endl ;
        std::cout << " ┌─────────────────────────────┐" << std::endl;
        std::cout << " │                       <  M E N U  >                      │" << std::endl;
        std::cout << " │─────────────────────────────│" << std::endl;
        std::cout << " │                       1. 입금                            │" << std::endl;
        std::cout << " │                       2. 출금                            │" << std::endl;
        std::cout << " │                       3. 통장 정리                       │" << std::endl;
        std::cout << " │                       4. 종료                            │" << std::endl;
        std::cout << " └─────────────────────────────┘" << std::endl << std::endl;

        // 메뉴 선택
        std::cout << " 숫자를 입력 해주세요 -> ";
        uint32_t selection_menu{ 0U };
        std::cin >> selection_menu; std::cout << std::endl;

        uint32_t account_number{ 0U };
        uint16_t account_password{ 0U };


        switch (selection_menu) // 조건식 - selection_menu 값이 1이면 case:1 실행, 2이면 case:2 실행...
        {
        case 1: // 입금
            std::cout << "입금할 계좌번호를 입력하시오 -> ";
            std::cin >> account_number; std::cout << std::endl;

            for (int i = 0; i < customer; i++)  // 만든 배열 갯수만큼 반복해서 찾는다
            {
                if (customers[i].getAccountNumber() == account_number)  // 저장된 accountNumber랑 입력받은 account_number랑 비교해서 같으면
                {
                    customers[i].deposit();
                    customers[i].showBankAccount();
                }
            }
            break;

        case 2: // 출금
            std::cout << "출금할 계좌번호를 입력하시오 -> ";
            std::cin >> account_number; std::cout << std::endl;

            std::cout << "비밀번호를 입력하시오 -> ";
            std::cin >> account_password; std::cout << std::endl;

            for (int i = 0; i < customer; i++)                          // 만든 배열의 개수 만큼 반복해서 찾는다
            {
                if (customers[i].getAccountNumber() == account_number)  // 저장된 계좌번호 입력받은 계좌번호랑 비교
                {
                    if (customers[i].getPassWord() == account_password) // 비밀번호 일치 여부 확인
                    {
                        customers[i].withdraw();
                        customers[i].showBankAccount();
                    }
                    else
                    {                                                   // 비밀번호 불일치 시
                        std::cout << "비밀번호가 일치하지 않습니다. 상위 메뉴로 이동합니다. " << std::endl;
                        break;
                    }
                }
            }
            break;

        case 3: // 통장 정리
            std::cout << "통장 정리할 계좌번호를 입력하시오 -> ";
            std::cin >> account_number; std::cout << std::endl;
            for (int i = 0; i < customer; i++)  // 만든 배열갯수만큼 반복해서 찾는다
            {
                if (customers[i].getAccountNumber() == account_number)  // 저장된 accountNumber랑 입력받은 account_number랑 비교해서 같으면
                {
                    customers[i].showBankAccount(); // 계좌 정보를 보여준다
                }
            }
            break;

        case 4: // 종료
            std::cout << " *** 프로그램을 종료합니다. *** " << std::endl;
            goto EXIT;
            break;

        default:
            std::cout << "잘못 입력했습니다." << std::endl;
            break;
        }
    }
    EXIT:
    delete[] customers;     // 동적 할당 해제
}