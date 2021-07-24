#include "BankAccount2.h"

BankAccount2::BankAccount2()    // 생성자 호출
{
    this->accountNumer = uint16_t(0U);
    this->customerName = std::string("");
    this->money = uint64_t(0UL);
    this->stateVVIP = false;
    this->passWord = uint16_t(0U);
}

// 계좌 번호            get,set 은닉화
uint32_t BankAccount2::getAccountNumber() const 
{
    return this->accountNumer;
}
void BankAccount2::setAccountNumber(uint32_t accountNumber)
{
    this->accountNumer = accountNumber;
}

// 고객 이름
std::string BankAccount2::getCustomerName() const
{
    return this->customerName;
}
void BankAccount2::setCustomerName(std::string customerName)
{
    this->customerName = customerName;
}

// 초기 금액
uint64_t BankAccount2::getMoney() const
{
    return this->money;
}
void BankAccount2::setMoney(uint64_t money)
{
    this->money = money;
}

// VVIP 여부
bool BankAccount2::getStateVVIP() const
{
    return this->stateVVIP;
}
void BankAccount2::setStateVVIP(bool stateVVIP)
{
    this->stateVVIP = stateVVIP;
}

// 비밀번호 지정
uint16_t BankAccount2::getPassWord() const
{
    return this->passWord;
}
void BankAccount2::setPassWord(uint16_t passWord)
{
    this->passWord = passWord;
}

// 출금 메서드
void BankAccount2::withdraw()
{
    if (this->money <= 0)                                // 잔액이 0원일 때 출금할 경우
    {
        std::cout << "잔액이 부족합니다." << std::endl;
        return;
    }
    else
    {
        uint64_t balance{ 0UL };                        // 출금할 금액
        std::cout << "얼마를 출금하시겠습니까? -> ";
        std::cin >> balance; std::cout << std::endl;
        if (balance > this->money)         // 출금할 금액이 잔액보다 크면
        {
            std::cout << "출금 가능 금액을 초과하였습니다." << std::endl;
            return;
        }
        else          
        {                               
            this->money -= balance;     // 출금할 금액이 잔액이내이면 잔액-출금액을 저장
        }

    }
}

// 입금 메서드
void BankAccount2::deposit()
{
    uint64_t balance{ 0UL };
    std::cout << "입금할 금액을 입력해주세요 -> ";
    std::cin >> balance; std::cout << std::endl;
    this->money += balance; // 기존 잔액에 입금할 금액을 더해서 저장
}

// 고객정보 출력하기 위한 메서드
void BankAccount2::showBankAccount()
{
    std::cout << "고객 이름 : " << this->customerName << std::endl;
    std::cout << "계좌 번호 : " << this->accountNumer << std::endl;
    std::cout << "계좌 잔액 : " << this->money << std::endl << std::endl;
    
    // 저장된 VVIP정보 사용하여 VVIP 또는 SILVER 고객에게 출력할 문구 
    if (this->stateVVIP) std::cout  << "환영합니다. VVIP 고객님 *^_^*" << std::endl;
    else std::cout << this->customerName << "님 좋은 은행 상품이 있습니다. " << std::endl;
}