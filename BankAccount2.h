#pragma once
#include <iostream>

class BankAccount2
{
private:                                                // ���� ���� ���û�(�ܺ� ����, �Ļ� Ŭ�����κ����� ���� ����)
    uint32_t accountNumer;                              // ���¹�ȣ
    std::string customerName;                           // ���̸�
    uint64_t money;                                     // �ܾ�
    bool stateVVIP;                                     // VVIP ����
    uint16_t passWord;                                  // ��й�ȣ

public: // ���� ���� ���û�(����� ���� ��� �ܺ� ���� ���)
    BankAccount2();                                     // ����Ʈ ������
    uint32_t getAccountNumber() const;                  // ���¹�ȣ ȣ��  const(�б� ����)    const ����ϴ� ���� : �����͸� ���� ���� �ְ� �� ���� ����.(�б� ����)
    void setAccountNumber(uint32_t accountNumber);      // ���¹�ȣ ����
    std::string getCustomerName() const;                // �̸� ȣ��
    void setCustomerName(std::string customerName);     // �̸� ����
    uint64_t getMoney() const;                          // �ܾ� ȣ��
    void setMoney(uint64_t money);                      // �ܾ� ����
    bool getStateVVIP() const;                          // VVIP ���� ȣ��
    void setStateVVIP(bool stateVVIP);                  // VVIP ���� ����
    uint16_t getPassWord() const;                       // ��й�ȣ ȣ��
    void setPassWord(uint16_t passWord);                // ��й�ȣ ����
    void withdraw();                                    // ���
    void deposit();                                     // �Ա�
    void showBankAccount();                             // ���� ����
};

