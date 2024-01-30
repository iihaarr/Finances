#include <vector>
#include <algorithm>

#include "finances/storage/category.hpp"
#include "finances/entities/category.hpp"

namespace finances::storage
{
   ICategoryStorage& GetCategoryStorage()
   {
      static CategoryStorage st;
      return st;
   }
   std::unique_ptr<entities::ICategory> CategoryStorage::GetCategoryById(utils::types::ID id_) const noexcept
   {
      const auto catIter = std::find_if(std::begin(m_storage), std::end(m_storage),
                                        [id_](const auto& category_) {return category_->GetID() == id_; });
      return catIter != std::end(m_storage) ? (*catIter)->Clone() : nullptr;
   }
   utils::types::ID CategoryStorage::CreateCategory(const std::string & name_)  noexcept
   {
      static utils::types::ID lastId{};
      m_storage.emplace_back(std::make_unique<entities::Category>(lastId, name_));
      return lastId++;
   }
}