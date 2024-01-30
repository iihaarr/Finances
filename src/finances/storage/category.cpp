#include <vector>
#include <algorithm>

#include "finances/storage/category.hpp"
#include "finances/entities/category.hpp"

namespace finances::storage
{
   std::unique_ptr<entities::ICategory> CategoryStorage::GetCategoryById(utils::types::ID id_) const noexcept
   {
      const auto catIter = std::find_if(std::begin(m_storage), std::end(m_storage),
                                        [id_](const auto& category_) {return category_->GetID() == id_; });
      return catIter != std::end(m_storage) ? (*catIter)->Clone() : nullptr;
   }
}