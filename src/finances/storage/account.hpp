#ifndef __STORAGE_ACCOUNT_HPP__ 
#define __STORAGE_ACCOUNT_HPP__

#include <vector>

#include "finances/storage/account_interface.hpp"

namespace finances::storage
{
   class AccountStorage : public IAccountStorage
   {
   public:
      std::unique_ptr<entities::IAccount> GetAccountById(utils::types::ID id_) const noexcept override;
      utils::types::ID  CreateAccount(const std::string& name_) noexcept override;
      virtual ~AccountStorage() = default;
   private:
      std::vector<std::unique_ptr<entities::IAccount>> m_storage;
   };
}
#endif