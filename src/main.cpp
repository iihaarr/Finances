#include "finances/storage/account_interface.hpp"
#include <iostream>
int main()
{
   auto& storage = finances::storage::GetAccountStorage();
   auto id = storage.CreateAccount("new account");
   auto acc = storage.GetAccountById(id);
   if (acc)
      std::cout << acc->GetName() << '\n';
   return 0;
}