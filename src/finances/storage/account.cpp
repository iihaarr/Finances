#include <vector>
#include <algorithm>

#include "finances/storage/account.hpp"
#include "finances/entities/account.hpp"

namespace finances::storage
{
   IAccountStorage& GetAccountStorage()
   {
      static AccountStorage st;
      return st;
   }
   std::unique_ptr<entities::IAccount> AccountStorage::GetById(utils::types::ID id_) const noexcept
   {
      const auto accIter = std::find_if(std::begin(m_storage), std::end(m_storage),
                                        [id_](const auto& account_) {return account_->GetID() == id_; });
      return accIter != std::end(m_storage) ? (*accIter)->Clone() : nullptr;
   }
   utils::types::ID AccountStorage::Create(const std::string& name_) noexcept
   {
      static utils::types::ID lastIdx{};
      m_storage.emplace_back(std::make_unique<entities::Account>(lastIdx, name_));
      return lastIdx++;
   }
}