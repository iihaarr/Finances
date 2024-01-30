#ifndef __ENTITIES_ACCOUNT_HPP__
#define __ENTITIES_ACCOUNT_HPP__

#include "finances/entities/account_interface.hpp"

namespace finances::entities
{
   struct Account : public IAccount
   {
      Account(utils::types::ID id_, std::string name_);
      Account(const Account&) = default;
      Account(Account&&) = default;
      Account& operator=(const Account&) = default;
      Account& operator=(Account&&) = default;

      finances::utils::types::ID GetID() const noexcept override;
      const std::string& GetName() const noexcept override;
      std::unique_ptr<IAccount> Clone() const noexcept override;
      virtual ~Account() = default;
   private:
      utils::types::ID m_id;
      std::string m_name;
   };
}

#endif