#ifndef __STORAGE_ACCOUNT_INTERFACE_HPP__
#define __STORAGE_ACCOUNT_INTERFACE_HPP__

#include "finances/entities/account_interface.hpp"

namespace finances::storage
{
   struct IAccountStorage
   {
      virtual std::unique_ptr<entities::IAccount> GetById(utils::types::ID id_) const noexcept = 0;
      virtual utils::types::ID Create(const std::string& name_) noexcept = 0;
      virtual ~IAccountStorage() = default;
   };

   IAccountStorage& GetAccountStorage();
}

#endif