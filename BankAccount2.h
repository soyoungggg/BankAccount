#pragma once
#include <iostream>

class BankAccount2
{
private:                                                // 접근 제어 지시사(외부 접근, 파생 클래스로부터의 접근 차단)
    uint32_t accountNumer;                              // 계좌번호
    std::string customerName;                           // 고객이름
    uint64_t money;                                     // 잔액
    bool stateVVIP;                                     // VVIP 여부
    uint16_t passWord;                                  // 비밀번호

public: // 접근 제어 지시사(멤버에 관한 모든 외부 접근 허용)
    BankAccount2();                                     // 디폴트 생성자
    uint32_t getAccountNumber() const;                  // 계좌번호 호출  const(읽기 전용)    const 사용하는 이유 : 데이터를 읽을 수만 있고 쓸 수는 없다.(읽기 전용)
    void setAccountNumber(uint32_t accountNumber);      // 계좌번호 저장
    std::string getCustomerName() const;                // 이름 호출
    void setCustomerName(std::string customerName);     // 이름 저장
    uint64_t getMoney() const;                          // 잔액 호출
    void setMoney(uint64_t money);                      // 잔액 저장
    bool getStateVVIP() const;                          // VVIP 여부 호출
    void setStateVVIP(bool stateVVIP);                  // VVIP 여부 저장
    uint16_t getPassWord() const;                       // 비밀번호 호출
    void setPassWord(uint16_t passWord);                // 비밀번호 설정
    void withdraw();                                    // 출금
    void deposit();                                     // 입금
    void showBankAccount();                             // 계좌 상태
};

