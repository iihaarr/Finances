#include "finances/entities/account.hpp"

namespace finances::entities
{
   Account::Account(utils::types::ID id_, std::string name_)
      : m_id(id_), m_name(std::move(name_))
   {
   }
   finances::utils::types::ID Account::GetID() const noexcept
   {
      return m_id;
   }
   const std::string& Account::GetName() const noexcept
   {
      return m_name;
   }
   std::unique_ptr<IAccount> Account::Clone() const noexcept
   {
      return std::make_unique<Account>(*this);
   }
}