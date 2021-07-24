#include "BankAccount2.h"

BankAccount2::BankAccount2()    // ������ ȣ��
{
    this->accountNumer = uint16_t(0U);
    this->customerName = std::string("");
    this->money = uint64_t(0UL);
    this->stateVVIP = false;
    this->passWord = uint16_t(0U);
}

// ���� ��ȣ            get,set ����ȭ
uint32_t BankAccount2::getAccountNumber() const 
{
    return this->accountNumer;
}
void BankAccount2::setAccountNumber(uint32_t accountNumber)
{
    this->accountNumer = accountNumber;
}

// �� �̸�
std::string BankAccount2::getCustomerName() const
{
    return this->customerName;
}
void BankAccount2::setCustomerName(std::string customerName)
{
    this->customerName = customerName;
}

// �ʱ� �ݾ�
uint64_t BankAccount2::getMoney() const
{
    return this->money;
}
void BankAccount2::setMoney(uint64_t money)
{
    this->money = money;
}

// VVIP ����
bool BankAccount2::getStateVVIP() const
{
    return this->stateVVIP;
}
void BankAccount2::setStateVVIP(bool stateVVIP)
{
    this->stateVVIP = stateVVIP;
}

// ��й�ȣ ����
uint16_t BankAccount2::getPassWord() const
{
    return this->passWord;
}
void BankAccount2::setPassWord(uint16_t passWord)
{
    this->passWord = passWord;
}

// ��� �޼���
void BankAccount2::withdraw()
{
    if (this->money <= 0)                                // �ܾ��� 0���� �� ����� ���
    {
        std::cout << "�ܾ��� �����մϴ�." << std::endl;
        return;
    }
    else
    {
        uint64_t balance{ 0UL };                        // ����� �ݾ�
        std::cout << "�󸶸� ����Ͻðڽ��ϱ�? -> ";
        std::cin >> balance; std::cout << std::endl;
        if (balance > this->money)         // ����� �ݾ��� �ܾ׺��� ũ��
        {
            std::cout << "��� ���� �ݾ��� �ʰ��Ͽ����ϴ�." << std::endl;
            return;
        }
        else          
        {                               
            this->money -= balance;     // ����� �ݾ��� �ܾ��̳��̸� �ܾ�-��ݾ��� ����
        }

    }
}

// �Ա� �޼���
void BankAccount2::deposit()
{
    uint64_t balance{ 0UL };
    std::cout << "�Ա��� �ݾ��� �Է����ּ��� -> ";
    std::cin >> balance; std::cout << std::endl;
    this->money += balance; // ���� �ܾ׿� �Ա��� �ݾ��� ���ؼ� ����
}

// ������ ����ϱ� ���� �޼���
void BankAccount2::showBankAccount()
{
    std::cout << "�� �̸� : " << this->customerName << std::endl;
    std::cout << "���� ��ȣ : " << this->accountNumer << std::endl;
    std::cout << "���� �ܾ� : " << this->money << std::endl << std::endl;
    
    // ����� VVIP���� ����Ͽ� VVIP �Ǵ� SILVER ������ ����� ���� 
    if (this->stateVVIP) std::cout  << "ȯ���մϴ�. VVIP ���� *^_^*" << std::endl;
    else std::cout << this->customerName << "�� ���� ���� ��ǰ�� �ֽ��ϴ�. " << std::endl;
}